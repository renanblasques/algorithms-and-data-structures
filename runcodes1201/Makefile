CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o linked_list.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

%.o: %.c linked_list.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
