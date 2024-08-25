CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: $(TARGET) all re clean fclean
