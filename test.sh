#!/bin/bash

result=""

if [ ! -d "$DIRECTORY" ]; then
    echo "remove old build"
    rm -rf tempbuild
fi

mkdir tempbuild
COMPILER='Unix Makefiles'
if command -v ninja 2>&1 >/dev/null
then
    COMPILER='Ninja'
fi
cmake -B tempbuild -S . -G "$COMPILER"
cmake --build ./tempbuild --target tools_test --config Release

./tempbuild/utils/tools_test

rm -rf tempbuild