TARGET=main

# all .c files in this directory are my sources
SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

INC_DIR=../include
CC=gcc
LDFLAGS= -g

CFLAGS= -c -ansi $(LDFLAGS) -Wall  -pedantic -Wconversion -D_DEBUG -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)


.PHONY: clean run gdb

$(TARGET): $(OBJS)


include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

leak:
	valgrind ./$(TARGET) --leak-check=full
	
