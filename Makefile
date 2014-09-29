
all:
	gcc -c test.c -o test.o
	gcc -c menu.c -o menu.o
	gcc menu.o test.o -o test

clean:
	rm -rf *.o test

exp2:
	gcc menufunction.c test.c linkTable.c -o test

run:
	./test

