NAME = fillit

SRC_D = $(addprefix ./srcs/, $(SRCS))

OBJ_D = objs

GCCFLAGS = -Wall -Wextra -Werror

SRCS = map.c   \
	   main.c   \
	   reader.c  \
	   fillit.c   \
	   validator.c \

OBJS = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(GCCFLAGS) -c $(SRC_D) -I ./includes -I ./libft/includes
		mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)/
		gcc $(GCCFLAGS) -o $(NAME) $(OBJS) \
		 	-L./libft/ -lft -I ./includes -I ./libft/includes

clean:
		make clean -C ./libft
		rm -rf $(OBJ_D)

fclean: clean
		make fclean -C ./libft
		rm -rf $(NAME)

re: fclean all
