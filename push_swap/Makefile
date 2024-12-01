CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
NAME_BONUS = checker

SRC_PATH = src/
OBJ_PATH = obj/
SRC_PATH_BONUS = bonus/
OBJ_PATH_BONUS = obj_bonus/

SRC		= main.c \
		check_input.c check_utils_input.c \
		initialization.c \
		stack.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort3.c sort.c \
		position.c cost.c do_move.c \
		utils.c parsing.c ft_split.c \
		check_double.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

SRC_B	= main.c \
		gnl.c gnl_utils.c read.c utils.c \
		operation.c do_move.c \
		parsing.c ft_split.c utils2.c
SRCS_B	= $(addprefix $(SRC_PATH_BONUS), $(SRC_B))
OBJ_B		= $(SRC_B:.c=.o)
OBJS_B	= $(addprefix $(OBJ_PATH_BONUS), $(OBJ_B))
INCS_B	= -I ./includes_bonus/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJ_PATH_BONUS) $(NAME_BONUS) 

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH_BONUS):
	mkdir $(OBJ_PATH_BONUS)

$(NAME_BONUS): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ_PATH) $(OBJ_PATH_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re