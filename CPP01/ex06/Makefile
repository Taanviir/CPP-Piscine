### COLORS
GREEN_B = "\033[1;32m"
RED_B = "\033[1;31m"
BLUE_I = "\033[2;34m"
RESET = "\033[0m"

NAME = harlFilter
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = $(wildcard *.cpp)

OBJ_DIR = obj/
OBJS_LIST = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJS_LIST))

all : $(NAME)

$(NAME) : $(OBJS)
	@c++ $(CPPFLAGS) $(OBJS) -o $@
	@echo $(GREEN_B)$(NAME)$(RESET)" is ready. ✅\n"

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(CPPFLAGS) -I./ -c $< -o $@
	@echo $(BLUE_I)"Compiling $<."$(RESET)

clean :
	@rm -rf $(OBJ_DIR)
	@echo $(RED_B)"Object files removed."$(RESET)

fclean : clean
	@rm -f $(NAME)
	@echo $(RED_B)"$(NAME) removed.\n"$(RESET)

re : fclean all

.PHONY : all clean fclean re
