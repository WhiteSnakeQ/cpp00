NAME		:=	program

CC			:=	c++

SRCS		:=	tests.cpp Account.cpp

HEADERS		:=	Account.hpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

all: $(NAME) test fclean

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -I${HEADERS} -o $(NAME)
	@echo DONE

.cpp.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

test:
	./$(NAME) > task.txt

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re