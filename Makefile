CC = gcc

FLAG = -Wall -Werror -Werror

LIBS = libft/libft.a liba/liba.a

RM	= rm -rf

SRC = main.c

OBJ	= $(SRC:.c=.o)

NAME = arkanoid

all: $(NAME)
	
libcompil:
	@make -C ./libft/

$(NAME):
	@make -C ./libft
	@make -C ./liba
	@git submodule update
	@cd glfw && cmake . && make
	@gcc -Wall -Werror -Wextra -o glfw/src/libglfw3.a $(NAME) $(LIBS) $(SRC) $(MLX_FLAG)

clean:
	@make clean -C ./liba
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./liba
	@make fclean -C ./libft
	@$(RM) glfw
	@$(RM) $(NAME)

re: fclean all
