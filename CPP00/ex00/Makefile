### COLORS
GREEN_B = "\033[1;32m"
RED_B = "\033[1;31m"
RESET = "\033[0m"

NAME = megaphone
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = $(wildcard *.cpp)

all : $(NAME)

$(NAME) :
	@c++ $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo $(GREEN_B)$(NAME)$(RESET)" is ready. ✅\n"

clean :
	@rm -f $(NAME)
	@echo $(RED_B)"$(NAME) removed.\n"$(RESET)

fclean : clean

re : fclean all

.PHONY : all clean fclean re