CFLAGS = -Wall -fpic -coverage -ftest-coverage -fprofile-arcs -lm -std=c99

default: testme

testme.exe: testme.c
	gcc -o testme testme.c $(CFLAGS)
	
clean:
	rm testme.exe
