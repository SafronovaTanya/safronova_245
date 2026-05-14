CC = gcc
CFLAGS = -Wall -fPIC

all: program

fred.o: fred.c
	$(CC) $(CFLAGS) -c fred.c

john.o: john.c
	$(CC) $(CFLAGS) -c john.c

bill.o: bill.c
	$(CC) $(CFLAGS) -c bill.c

sam.o: sam.c
	$(CC) $(CFLAGS) -c sam.c

link_interpose.o: link_interpose.c
	$(CC) $(CFLAGS) -c link_interpose.c

libstatic.a: fred.o john.o
	ar crv libstatic.a fred.o john.o

libshared.so: bill.o sam.o
	$(CC) -shared -o libshared.so bill.o sam.o -lm

load_interpose.so: load_interpose.c
	$(CC) -shared -fPIC -o load_interpose.so load_interpose.c -ldl

program: program.c lib.h libstatic.a libshared.so link_interpose.o load_interpose.so
	$(CC) -Wall -Wl,--wrap,fred -Wl,--wrap,john \
		-o program program.c link_interpose.o \
		-L. -lstatic -lshared -lm -Wl,-rpath,.

run: program
	LD_PRELOAD=./load_interpose.so ./program

clean:
	rm -f *.o *.a *.so program
