CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

TARGET = ft_tail

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ 

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f *.o

.PHONE: all clean fclean
