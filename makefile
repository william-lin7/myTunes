all: main.o songs.o
	gcc -o testing main.o songs.o

functions.o: songs.c listMethods.h
	gcc -c songs.c

main.o: main.c listMethods.h
	gcc -c main.c

run:
	./testing

clean:
	rm *.o
	rm *~
