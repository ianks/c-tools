CC = gcc
CFLAGS = -Wall -g

fifo_queue:
	$(CC) $(CFLAGS) -o examples/fifo_queue lib/fifo_queue.c examples/fifo_queue_example.c

clean:
	$(RM) examples/fifo_queue
