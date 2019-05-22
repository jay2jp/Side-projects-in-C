CC = gcc
CFLAGS = -Wall -Werror
all :	first second third fourth fifth
	
first : first.c 
	$(CC) $(CFLAGS) first.c -o first
second : second.c
	$(CC) $(CFLAGS) second.c -o second
third : third.c 
	$(CC) $(CFLAGS) third.c -o third
fourth : fourth.c 
	$(CC) $(CFLAGS) fourth.c -o fourth
fifth : fifth.c
	$(CC) $(CFLAGS) fifth.c -o fifth
	
clean :
	rm -f first second third fourth fifth
