all: indexer

indexer: indexer.o main.o
	gcc -o indexer inxeder.o main.o

indexer.o: indexer.c indexer.h
	gcc -o indexer.o -c indexer.c

main.o: main.c indexer.h
	gcc -o main.o -c main.c

clean:
        rm -rf *.o
