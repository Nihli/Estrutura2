all: indexer

indexer: gloria.o
	gcc -o indexer gloria.o

gloria.o: gloria.c
	gcc -o gloria.o -c gloria.c

clean:
        rm -rf *.o
