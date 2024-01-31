NAME		:=	harlFilter

CC			:=	c++

SRCS		:=	main.cpp Harl.cpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -pedantic

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
	./$(NAME) lol "main.cpp"
	./$(NAME) lol
	./$(NAME) ERROR
	./$(NAME) DEBUG

test2:
	./$(NAME) Makefile "	" "0"

re: fclean all

.PHONY: clean fclean re