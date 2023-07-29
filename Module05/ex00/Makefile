# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 17:24:28 by hyerimki          #+#    #+#              #
#    Updated: 2023/07/29 12:57:04 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp
OBJS = $(SRC:.cpp=.o)
NAME = mommy

all : ${NAME}

${NAME} : ${OBJS}
	@${CXX} ${CFLAGS} -o ${NAME} ${OBJS} 
	@echo "$(COLOR)$(NAME) created!✅"
	
%.o : %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS)
	
fclean : clean
	@rm -rf ${NAME}
	@echo "$(COLOR)$(NAME) fclean!✅"

re : 
	make fclean 
	make all

.PHONY: all clean fclean re