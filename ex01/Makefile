NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

OBJ_DIR := obj

SRCS := main.cpp Bureaucrat.cpp Form.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
TOTAL := $(words $(SRCS))
COUNT := 0

all: $(NAME)
	

$(NAME): $(OBJS)
	@printf "\033[1A\033[2KCreate $(NAME)... "; \
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[0;32mcreated\033[0m\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@if [ $(COUNT) -eq 1 ]; then \
		printf "\n"; \
	fi
	@printf "\033[1A\033[2KCompilen ($(COUNT)/$(TOTAL)) $<\n";
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		printf "Clean $(NAME)... "; \
		rm -rf $(OBJ_DIR); \
		printf "\033[0;31mcleaned.\033[0m\n"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		printf "Remove $(NAME)... "; \
		rm -f $(NAME); \
		printf "\033[0;31mremoved.\033[0m\n"; \
	fi

re: fclean all

.PHONY: all clean fclean re
