CC=clang
CFLAGS=-std=c89 -Weverything -pedantic-errors
OBJECTS=main.o revbits.o atoh.o

all: revbits

revbits: $(OBJECTS)
	$(CC) $(CFLAGS) -o revbits $(OBJECTS)

main.o: main.c revbits.h atoh.h
	$(CC) $(CFLAGS) -Wno-padded -c main.c

revbits.o: revbits.h revbits.c
	$(CC) $(CFLAGS) -c revbits.c

atoh.o: atoh.h atoh.c 
	$(CC) $(CFLAGS) -Wno-padded -c atoh.c

clean:
	rm -f *.o *~ revbits

test: revbits
	@echo Running tests
	./runtests.sh
