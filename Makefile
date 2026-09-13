CC = gcc
CFLAGS = -Wall -std=c99

all: algorithm_benchmark

algorithm_benchmark: main.o sorting.o searching.o
	$(CC) $(CFLAGS) -o algorithm_benchmark main.o sorting.o searching.o

main.o: main.c algorithms.h
	$(CC) $(CFLAGS) -c main.c

sorting.o: sorting.c algorithms.h
	$(CC) $(CFLAGS) -c sorting.c

searching.o: searching.c algorithms.h
	$(CC) $(CFLAGS) -c searching.c

clean:
	rm -f *.o algorithm_benchmark
