# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 13:56:30 by hyerimki          #+#    #+#              #
#    Updated: 2023/03/25 14:00:50 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)
NAME = megaphone

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