CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_display_file.c
OBJS = $(SRCS:.c=.o)

TARGET = ft_display_file

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
