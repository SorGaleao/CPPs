
NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = src/megaphone.cpp
OBJS = obj/megaphone.o

GREEN		= \033[0;32m
GREY		= \033[0;90m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"
	@echo "To run this program, use ./megaphone fallowed by the sentece you would like to put through the megaphone."

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -r obj
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Fully cleaned everything.$(RESET)"
re: fclean all

.PHONY: all clean fclean re run valgrind
