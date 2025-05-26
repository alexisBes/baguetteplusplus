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
cmake --build ./tempbuild --target all --config Debug

./tempbuild/utils/tools_test

cd tempbuild
ctest
cd ..

rm -rf tempbuild