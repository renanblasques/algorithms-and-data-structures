CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o linked_list.o big_numbers.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

%.o: %.c linked_list.h big_numbers.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
