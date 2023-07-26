# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 17:24:28 by hyerimki          #+#    #+#              #
#    Updated: 2023/07/26 16:25:00 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp AForm.cpp \
	PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRC:.cpp=.o)
NAME = 28b

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
	@echo "$(COLOR)$(NAME) created!✅"
	
%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS) *_shrubbery
	
fclean : clean
	@rm -rf ${NAME} *_shrubbery
	@echo "$(COLOR)$(NAME) fclean!✅"

re : fclean all

.PHONY: all clean fclean re