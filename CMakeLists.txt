## CMake file for the project
cmake_minimum_required(VERSION 2.8)

# Project files
function (PROJECT_FILES)
  # Add any additional include paths here
  include_directories(
  )

  # Add any additional library paths here
  # ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
  link_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  ## Build and link
  # Add all the files needed to compile here
  FILE(GLOB_RECURSE PROJ_SOURCES src/*cpp)
  add_executable(${PROJECT_NAME}
    ${PROJ_SOURCES}
  )
endfunction()

# PSVita specific build instructions
function (VITA_BUILD)
  # Print VITASDK path as status
  message(STATUS "VITASDK path: $ENV{VITASDK}")

  if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{VITASDK})
      message(STATUS "Set VITASDK toolchain path: $ENV{VITASDK}/share/vita.toolchain.cmake")
      set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else()
      message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
    endif()
  endif()
endfunction()

function (VITA_LIBS)
  # Vita-specific macros
  include("${VITASDK}/share/vita.cmake" REQUIRED)

  # Libraries to link to (drop the -l prefix). This will mostly be stubs.
  target_link_libraries(${PROJECT_NAME}
    stdc++
    SDL2_mixer
    SDL2_image
    SDL2
    mikmod
    mpg123
    FLAC
    vorbisfile
    vorbis
    ogg
    m
    png
    jpeg
    webp
    z
    pthread
    SceDisplay_stub
    SceCtrl_stub
    SceAudio_stub
    SceSysmodule_stub
    SceGxm_stub
    SceCommonDialog_stub
    SceAppMgr_stub
    SceTouch_stub
    SceHid_stub
    SceMotion_stub
  )
endfunction()

function (VITA_AFTER)
  ## App config
  # Display name (under bubble in LiveArea)
  set(VITA_APP_NAME "Five Nights at Freddy's")
  # Unique ID must be exactly 9 characters.
  set(VITA_TITLEID  "GHNR00001")
  # Optional version string to show in LiveArea's more info screen
  set(VITA_VERSION  "01.00")

  # Optional. You can specify more param.sfo flags this way.
  set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

  ## Create Vita files
  vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
  # The FILE directive lets you add additional files to the VPK, the syntax is
  # FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
  vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE sce_sys/icon0.png sce_sys/icon0.png
    FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
    FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
    FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
    FILE assets/menu/1.png assets/menu/1.png
    FILE assets/menu/2.png assets/menu/2.png
    FILE assets/menu/3.png assets/menu/3.png
    FILE assets/menu/4.png assets/menu/4.png
    FILE assets/gui/loader.png assets/gui/loader.png
    FILE assets/gui/static/1.png assets/gui/static/1.png
    FILE assets/gui/static/2.png assets/gui/static/2.png
    FILE assets/gui/static/3.png assets/gui/static/3.png
    FILE assets/gui/static/4.png assets/gui/static/4.png
    FILE assets/gui/static/5.png assets/gui/static/5.png
    FILE assets/gui/static/6.png assets/gui/static/6.png
    FILE assets/gui/static/7.png assets/gui/static/7.png
    FILE assets/gui/static/8.png assets/gui/static/8.png
    FILE assets/text/WARNING.png assets/text/WARNING.png
    FILE assets/text/GAME_TITLE.png assets/text/GAME_TITLE.png
    FILE assets/audio/static2.wav assets/audio/static2.wav
    FILE assets/audio/darkness_music.wav assets/audio/darkness_music.wav
  )
endfunction()

# Unix specific build instructions
function (UNIX_BUILD)

endfunction()

function (UNIX_LIBS)
  # Libraries to link to (drop the -l prefix).
  target_link_libraries(${PROJECT_NAME}
    stdc++
    pthread
    SDL2_mixer
    SDL2_image
    SDL2
  )
endfunction()

function (UNIX_AFTER)
  # Copy the assets to the bin path
  add_custom_command(TARGET VitaFNAF1 PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:VitaFNAF1>/bin/assets/)
endfunction()

## Building mode check
if(DEFINED BUILD_ENV)

  # PSVita
  if(${BUILD_ENV} STREQUAL "VITA")
    # Send to the compiler
    add_compile_definitions(ENV_PSVITA=1)

    message(STATUS "Building the app in PSVita mode...")
    VITA_BUILD()

    # Project name
    project(VitaFNAF1)

    # Common for all platforms
    PROJECT_FILES()

    ## Compiler flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    message(STATUS "Linking libraries in PSVita mode...")
    VITA_LIBS()

    message(STATUS "After-build in PSVita mode...")
    VITA_AFTER()

  # Unix
  elseif(${BUILD_ENV} STREQUAL "UNIX")
    # Send to the compiler
    add_compile_definitions(ENV_UNIX=1)

    message(STATUS "Building the app in Unix mode...")
    UNIX_BUILD()

    # Project name
    project(VitaFNAF1)

    # Common for all platforms
    PROJECT_FILES()

    ## Compiler flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    message(STATUS "Linking libraries in Unix mode...")
    UNIX_LIBS()

    message(STATUS "After-build in Unix mode...")
    UNIX_AFTER()
  endif()
# Undefined
else()
  message(FATAL_ERROR "Please define the build environment using the BUILD_ENV variable!")
endif()