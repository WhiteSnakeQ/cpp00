# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 11:49:51 by kreys             #+#    #+#              #
#    Updated: 2024/02/01 17:43:09 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Heroes

CC			:=	c++

SRCS		:=	main.cpp \
				MaterialSource.cpp \
				AMateria.cpp \
				Cure.cpp \
				Ice.cpp \
				Character.cpp \
				
OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo DONE

.cpp.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	@rm -fr $(OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re