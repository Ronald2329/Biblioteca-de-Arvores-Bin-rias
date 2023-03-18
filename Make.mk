CC=gcc
CFLAGS=-Wall -g -fPIC

all: arvorebinaria.so

arvorebinaria.so: arvorebinaria.o
	$(CC) -shared -o $@ $^

arvorebinaria.o: arvorebinaria.c arvorebinaria.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.so

