CC = gcc

FLAG = -Wall -Werror -Werror

LIBS = libft/libft.a liba/liba.a

RM	= rm -rf

SRC = main.c \
		colision.c \
		init.c \
		draw.c \
		math.c \
		init_score.c \
		draw_seg.c \
		key_callback.c \
		singleton.c \
		gere_map.c \
		color_seg.c \
		color_seg2.c


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
	@gcc -Wall -Werror -Wextra -o $(NAME) $(LIBS) $(SRC) -L ./glfw/src/ -lglfw3 -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo

clean:
	@make clean -C ./liba
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./liba
	@make fclean -C ./libft
	@$(RM) glfw
	@$(RM) $(NAME)

quick:
	@$(RM) $(NAME)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(LIBS) $(SRC) -L ./glfw/src/ -lglfw3 -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo

re: fclean all
