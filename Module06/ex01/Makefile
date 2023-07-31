# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:58:29 by hyerimki          #+#    #+#              #
#    Updated: 2023/07/31 15:32:53 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp Serializer.cpp
OBJS = $(SRC:.cpp=.o)
NAME = Serializer

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