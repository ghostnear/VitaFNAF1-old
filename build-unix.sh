mkdir builds
cd builds
mkdir build-unix
cmake -S ../ -B build-unix/ -DBUILD_ENV=UNIX