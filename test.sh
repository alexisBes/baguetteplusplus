
result=""

if [ ! -d "$DIRECTORY" ]; then
    echo "remove old build"
    rm -rf tempbuild
fi

mkdir tempbuild
cd tempbuild
cmake .. 
make

./tools/tools_test

cd ..
rm -rf tempbuild