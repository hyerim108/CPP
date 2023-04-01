# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 23:42:24 by hyerimki          #+#    #+#              #
#    Updated: 2023/04/01 23:45:20 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp
OBJS = $(SRC:.cpp=.o)
NAME = ex00

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
	@echo "$(COLOR)$(NAME) created!✅"
	
%.o : %.cpp
	@$(CC) $(CFAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS)
	
fclean : clean
	@rm -rf ${NAME}
	@echo "$(COLOR)$(NAME) fclean!✅"

re : fclean all

.PHONY: all clean fclean re