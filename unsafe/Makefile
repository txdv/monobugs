all: test.exe libtest.so

test.exe: test.cs
	gmcs -target:exe -unsafe -debug test.cs

test.o: test.c
	gcc -c -fPIC test.c -o test.o

libtest.so: test.o
	gcc -shared -W1,-soname,libtest.so.1 -o libtest.so test.o

clean:	
	rm -f libtest.so test.o test.exe *.mdb

