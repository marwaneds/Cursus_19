# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 16:54:51 by mael-faq          #+#    #+#              #
#    Updated: 2024/11/29 16:28:54 by mael-faq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
INCLUDE	=	includes
CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE)
RM		=	rm -f

SRCS	=	src/main.c \
			src/utils.c \
			src/atoi.c \
			src/init.c \
			src/functions.c \
			src/threads.c

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "Linked into executable \033[0;32mphilo\033[0m."

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			@echo "Removed object files."
			
fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed executable."

re:			fclean all

.PHONY:		all clean fclean re
