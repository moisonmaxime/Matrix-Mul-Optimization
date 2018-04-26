CC = gcc -std=gnu99

CFLAGS = -msse4 -O3 -pipe -fno-omit-frame-pointer

all:	bench-naive bench-max bench-chunk bench-unroll bench-reorder bench-tile

#naive
bench-naive: benchmark.o dgemm-naive.o
	$(CC) -o $@ benchmark.o dgemm-naive.o 

#max
bench-max: benchmark.o dgemm-max.o
	$(CC) -o $@ benchmark.o dgemm-max.o

#chunk
bench-chunk: benchmark.o dgemm-chunk.o
	$(CC) -o $@ benchmark.o dgemm-chunk.o

#unroll
bench-unroll: benchmark.o dgemm-unroll.o
	$(CC) -o $@ benchmark.o dgemm-unroll.o

#tile
bench-tile: benchmark.o dgemm-tile.o
	$(CC) -o $@ benchmark.o dgemm-tile.o

#reorder
bench-reorder: benchmark.o dgemm-reorder.o
	$(CC) -o $@ benchmark.o dgemm-reorder.o

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f bench-naive bench-max bench-chunk bench-unroll bench-reorder bench-tile *.o
