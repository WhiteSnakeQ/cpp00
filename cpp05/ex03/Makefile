NAME		:=	Bureaucrat

CC			:=	c++

SRCS		:=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJ			:=	$(SRCS:.cpp=.o)

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

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