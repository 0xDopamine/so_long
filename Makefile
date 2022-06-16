CC = cc
CFLAGS =  -c -I/usr/include -c 
SRCS = draw.c map_checker.c events.c get_next_line.c get_next_line_utils.c ft_split.c
NAME = so_long
OBJS = ${SRCS:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
		$(CC) $(SRCS) -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

.PHONY: clean fclean re all