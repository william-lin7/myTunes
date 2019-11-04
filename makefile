all: main.o songs.o library.o
	gcc -o testing main.o songs.o library.o

functions.o: songs.c library.c listMethods.h libraryMethods.h
	gcc -c songs.c library.c

main.o: main.c listMethods.h libraryMethods.h
	gcc -c main.c

run:
	./testing

clean:
	rm *.o
	rm *~
