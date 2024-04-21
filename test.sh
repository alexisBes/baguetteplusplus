
result=""
for t in "$(find . -name *.bpp)";
do 

./build/baguetteplusplus $t

result="$(diff $t.result $t.lexer) ${result}";

done

if [ -z $result ] 
then
echo "Les tests sont ok"
else
echo "Les test ont echoué"
fi