all: test.dll test

test.dll: test.cs
	gmcs -target:library -debug test.cs

test: test.c
	gcc `pkg-config --cflags --libs mono-2` `pkg-config --cflags glib-2.0` test.c -o test

clean:	
	rm test test.dll

