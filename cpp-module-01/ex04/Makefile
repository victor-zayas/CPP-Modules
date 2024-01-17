# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 21:20:39 by vzayas-s          #+#    #+#              #
#    Updated: 2024/01/17 12:20:36 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = replace

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 --pedantic #-g3 -fsanitize=address

# ASCII COLORS #
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
END=\033[0m

SRCS =	main.cpp	\

OBJS = $(SRCS:.cpp=.o)

#.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@
	@echo "$(BLUE)༺ Program compiled༻$(END)"

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)༺ Objects compiled༻$(END)"

clean:
	$(RM) $(OBJS)
	@echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	$(RM) *.replace
	@echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
