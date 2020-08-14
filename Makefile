.PHONY: clean main

CC=gcc
OBJS=coroutine.o main.o
TARGET=srv client

all:$(TARGET)
srv:$(OBJS)
	$(CC) $^ -o $@
client:
	gcc client.c -o client
	$(CC) $^ -o $@
clean:
	rm -rf $(OBJS) main
