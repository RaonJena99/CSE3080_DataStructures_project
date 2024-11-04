CC = gcc
TARGET = hw1_naive hw1_kmp
OBJS = hw1_naive.o hw1_kmp.o

all: $(TARGET)

hw1_naive: hw1_naive.o
	$(CC) -o $@ $^

hw1_kmp: hw1_kmp.o
	$(CC) -o $@ $^

clean: 
	rm $(TARGET) $(OBJS)
