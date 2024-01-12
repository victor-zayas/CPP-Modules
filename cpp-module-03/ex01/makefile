NAME = clapTrap

CXX = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 --pedantic

# ASCII COLORS #
RED=\033[0;31m
YELLOW=\033[0;33m
BLUE=\033[0;34m
END=\033[0m

SRCS =	main.cpp	\
		ClapTrap.cpp	\
		ScavTrap.cpp	\

OBJS = $(SRCS:.cpp=.o)

.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@
	echo "$(BLUE)༺ Program compiled༻$(END)"

clean:
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re