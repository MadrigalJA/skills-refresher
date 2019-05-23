

test-read-file: test-read-file.o utils.o
	gcc -o test-read-file test-read-file.o utils.o

test-read-file.o: test-read-file.c
	gcc -c test-read-file.c

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm *.o
	rm test-read-file
