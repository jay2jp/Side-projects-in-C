CC = gcc
Cflags = -Wall -Werror -g

first: first.c 
	$(CC) $(CFLAGS) -o first first.c

second: second.c 
	$(CC) $(CFLAGS) -o second second.c

third: third.c
	$(CC) $(CFLAGS) -o third third.c

clean: 
	rm -f first
	rm -f second
	rm -f third
	