CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = do-op.c ft_atoi.c ft_putnbr.c ft_putstr.c
OBJS = $(SRCS:.c=.o)

TARGET = do-op

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

re: fclean all

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean $(TARGET) re
