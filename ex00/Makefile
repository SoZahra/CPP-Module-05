# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 14:15:26 by fzayani           #+#    #+#              #
#    Updated: 2025/03/08 16:05:50 by fzayani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Beaureaucrat

CC = c++

CFLAG = -Wall -Wextra -Wextra -std=c++98

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all