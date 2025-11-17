

NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include/phonebook -I include/contact
RM = rm -f

SRCS = src/main.cpp \
       src/contact/contact.cpp \
       src/phonebook/phonebook.cpp
OBJS = $(SRCS:src/%.cpp=obj/%.o)

GREEN		= \033[0;32m
GREY		= \033[0;90m
RED			= \033[0;31m
RESET		= \033[0m


all: $(NAME)


$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"


obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) -r obj
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Fully cleaned everything.$(RESET)"
re: fclean all

.PHONY: all clean fclean re run valgrind
