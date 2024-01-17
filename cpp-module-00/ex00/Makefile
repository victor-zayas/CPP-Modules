NAME = megaphone

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 --pedantic
RM = /bin/rm -f

# ASCII COLORS #
RED=\033[0;31m
YELLOW=\033[0;33m
BLUE=\033[0;34m
END=\033[0m

.SILENT:

all: $(NAME)

$(NAME): megaphone.o
	$(CXX) $(CXXFLAGS) $< -o $@
	echo "$(BLUE)༺ Program compiled༻$(END)"

$(OBJS):%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)༺ Objects compiled༻$(END)"

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