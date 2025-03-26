# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 14:56:08 by deryacar          #+#    #+#              #
#    Updated: 2024/09/25 14:56:11 by deryacar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ClapTrap

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone\033[m"

clean:
	@$(RM) $(OBJ) $(NAME)
	@echo "\033[0;34mclean\033[m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;36mfclean\033[m"

re: fclean $(NAME)

.PHONY: all clean fclean re