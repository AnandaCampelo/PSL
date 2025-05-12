all:
	bison -d psl.y
	flex psl.l
	gcc -o psl main.c psl.tab.c lex.yy.c -lfl