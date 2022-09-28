/*
 *Jingbo Wang
 */

CC=clang
CFLAGS=-std=c89 -Weverything -pedantic-errors
OBJECTS=main.o contacts.o create.o search.o add.o delete.o exit.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c contacts.h create.h search.h add.h delete.h exit.h
	$(CC) $(CFLAGS) -Wno-padded -c main.c

contacts.o: contacts.c contacts.h create.h search.h add.h delete.h exit.h
	$(CC) $(CFLAGS) -c contacts.c

createcontact.o: createcontact.h create.c contacts.h
	$(CC) $(CFLAGS) -c createcontact.c

search.o: search.h search.c contacts.h create.h
	$(CC) $(CFLAGS) -c search.c

add.o: add.h add.c contacts.h create.h
	$(CC) $(CFLAGS) -c add.c

delete.o: delete.h delete.c contacts.h
	$(CC) $(CFLAGS) -c delete.c

exit.o: exit.h exit.c contacts.h
	$(CC) $(CFLAGS) -c exit.c

clean:
	rm -f *.o *~ contacts
