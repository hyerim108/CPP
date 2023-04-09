# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 23:42:24 by hyerimki          #+#    #+#              #
#    Updated: 2023/04/09 05:49:09 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp
OBJS = $(SRC:.cpp=.o)
NAME = ClapTrap

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
	@echo "$(COLOR)$(NAME) created!✅"
	
%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS)
	
fclean : clean
	@rm -rf ${NAME}
	@echo "$(COLOR)$(NAME) fclean!✅"

re : fclean all

.PHONY: all clean fclean re