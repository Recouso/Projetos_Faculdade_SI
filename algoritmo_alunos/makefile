main_lista: main.o aluno.o
	gcc -o main_lista main.o aluno.o
	
main.o: main.c aluno.h
	gcc -c main.c
	
aluno.o: aluno.c aluno.h
	gcc -c aluno.c