NAME = Harl2.0

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 --pedantic

# ASCII COLORS #
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
END=\033[0m

SRCS =	main.cpp	\

OBJS = $(SRCS:%.cpp=%.o)
CLASS = Harl
CLASS_SRC = $(CLASS:%=%.cpp)
CLASS_OBJ = $(CLASS:%=%.o)
CLASS_HEADER = $(CLASS:%=%.hpp)

#.SILENT:
all: $(NAME)

$(NAME): $(CLASS_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $(CLASS_OBJ) $(OBJS) -o $(NAME)
	@echo "$(BLUE)༺ Program compiled༻$(END)"

$(OBJS):%.o: %.cpp $(CLASS_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)༺ Objects compiled༻$(END)"

$(CLASS_OBJ): %.o: %.cpp $(CLASS_HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CLASS_OBJ)
	@echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re