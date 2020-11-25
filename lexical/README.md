目录下：

lex lexical.lex

yacc -d ch.y

cc -o test1 lex.yy.c y.tab.c

./test1 test.txt result.txt

cat result.txt
