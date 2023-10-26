# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 06:55:22 by pszleper          #+#    #+#              #
#    Updated: 2023/10/26 02:57:39 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILATION = c++ -Wall -Wextra -Werror -std=c++98

NAME = MutantStack

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = MutantStack.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(COMPILATION) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(COMPILATION) $< -c -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
