NAME		:=	PhoneBook

CC			:=	c++

SRCS		:=	main.cpp Contact.cpp PhoneBook.cpp Builder.cpp

HEADERS		:= Contact.hpp PhoneBook.hpp Builder.hpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) ${HEADERS} -o $(NAME)
	@echo DONE

.cpp.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re