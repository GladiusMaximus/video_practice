#!/bin/sh

flags="-std=c++0x -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused"
debug_flags="-g -O0"
release_flags="-O3 -DNDEBUG"

source="./*.cpp"
args=""
out_file="./app"

. ./config.sh

rm -f $out_file

g++ $source $flags $debug_flags -o $out_file `pkg-config --libs opencv`

if [ $? -eq 0 ]; then
    printf  "\nBuild Done!\n\n"
    $out_file $args
    return 0
else
    printf "\nBuild Failed!\n"
    return 1
fi