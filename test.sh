
result=""

if [ ! -d "$DIRECTORY" ]; then
    echo "remove old build"
    rm -rf tempbuild
fi

mkdir tempbuild
cd tempbuild
cmake .. -DTESTING=ON
make

cd ..

for t in "$(find . -name *.bpp)";
do 
./tempbuild/baguetteplusplus $t

result="$(diff -q $t.result $t.lexer) $result";
echo $result

done

if [ -z $result ] 
then
echo "Les tests sont ok"
else
echo "Les test ont echoué"
fi

rm -rf tempbuild