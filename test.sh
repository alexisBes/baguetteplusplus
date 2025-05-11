#!/bin/bash

result=""

if [ ! -d "$DIRECTORY" ]; then
    echo "remove old build"
    rm -rf tempbuild
fi

mkdir tempbuild

cmake -B tempbuild -S . -G Ninja
cmake --build ./tempbuild --target tools_test --config Release

./tempbuild/tools/tools_test

rm -rf tempbuild