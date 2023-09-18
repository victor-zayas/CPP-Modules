# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 09:53:56 by codespace         #+#    #+#              #
#    Updated: 2023/09/18 10:30:48 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FLAGS = -Wall -Werror -Wextra -g3 -std=c++98 --pedantic
RM = /bin/rm -f

.SILENT:

all: $(NAME)

$(NAME): megaphone.o
	$(CXX) $(FLAGS) $< -o $@
	echo "$(BLUE)༺ Program compiled༻$(END)"

megaphone.o: megaphone.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) megaphone.o
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) megaphone
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re