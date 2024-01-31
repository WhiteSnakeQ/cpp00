NAME		:=	program

CC			:=	c++

SRCS		:=	main.cpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo DONE

.cpp.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

test:
	./$(NAME) Makefile "main.cpp" "replace --------"
	./$(NAME) lol
	./$(NAME) lol asdaw awdas

test2:
	./$(NAME) Makefile "	" "0"

re: fclean all

.PHONY: clean fclean re