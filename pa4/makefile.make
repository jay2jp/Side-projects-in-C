all: first

first: first.c
	gcc -Wall -o first first.c
clean:
	rm first