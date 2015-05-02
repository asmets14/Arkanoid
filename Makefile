CC = gcc

FLAG = -Wall -Werror -Werror 

LIBS = libft/libft.a liba/liba.a

RM	= rm -f

SRC = 

OBJ	= $(SRC:.c=.o)

NAME = arkanoid

all: $(NAME)
	
libcompil:
	make -C ./libft/

gitcompil:
	git submodule add https://github.com/glfw/glfw.git
	git submodule update


$(NAME):
	Make -C ./libft
	Make -C ./liba
	gcc -Wall -Werror -Wextra -o $(NAME) $(LIBS) $(SRC) $(MLX_FLAG)

clean:
	Make -C clean ./liba
	Make -C clean ./libft
	$(RM) $(OBJ)

fclean: clean
	Make -C fclean ./liba
	Make -C fclean ./libft
	$(RM) $(NAME)

re: fclean all

	