NAME		:=	Fixed

CC			:=	c++

SRCS		:=	main.cpp Fixed.cpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-std=c++98 -pedantic

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

re: fclean all

.PHONY: clean fclean re