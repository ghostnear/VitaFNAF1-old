export VITASDK=/usr/local/vitasdk
export PATH=$VITASDK/bin:$PATH # add vitasdk tool to $PATH
mkdir builds
cd builds
mkdir build
cmake -S ../ -B build/ -DBUILD_ENV=VITA