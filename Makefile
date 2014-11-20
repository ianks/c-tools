CC = gcc
CFLAGS = -Wall -g

queue: queue.c
	$(CC) $(CFLAGS) -o queue queue.c

clean:
	$(RM) queue
