CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_cat.c
OBJS = $(SRCS:.c=.o)

TARGET = ft_cat

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $< -o $@ 

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f *.o

.PHONE: all clean fclean
