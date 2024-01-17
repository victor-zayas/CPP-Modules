# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 11:11:49 by vzayas-s          #+#    #+#              #
#    Updated: 2024/01/17 11:48:55 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 --pedantic

# ASCII COLORS #
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
END=\033[0m

SRCS =	main.cpp		\

OBJS = $(SRCS:%.cpp=%.o)

.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	echo "$(BLUE)༺ Program compiled༻$(END)"

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)༺ Objects compiled༻$(END)"

clean:
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
