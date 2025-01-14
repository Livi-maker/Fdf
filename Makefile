NAME = fdf

MY_SOURCES = $(wildcard *.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

LIBFLAGS = -Lminilibx-linux -lmlx -Llibft -lft

all: $(NAME)

$(NAME): $(MY_OBJECTS) add 
	$(CC) $(MY_OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)
	make -C libft clean
	make -C minilibx-linux clean

fclean:
	rm -f $(MY_OBJECTS) $(NAME)
	make -C libft fclean

re:
	fclean $(NAME)

add:
	make -C libft 
	make -C minilibx-linux
