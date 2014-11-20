CC = gcc
CFLAGS = -Wall -g

fifo_queue: lib/fifo_queue.c
	$(CC) $(CFLAGS) -o fifo_queue lib/fifo_queue.c

clean:
	$(RM) fifo_queue
