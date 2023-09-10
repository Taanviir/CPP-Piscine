### COLORS
GREEN_B = "\033[1;32m"
RED_B = "\033[1;31m"
RESET = "\033[0m"

NAME = megaphone
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp

all : $(NAME)

$(NAME) :
	@c++ $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo $(GREEN_B)"Megaphone\033[0m is ready. ✅\n"$(RESET)

clean :
	@rm -f $(NAME)
	@echo $(RED_B)"Executable removed.\n"$(RESET)

fclean : 
	@rm -f $(NAME)
	@echo $(RED_B)"Executable removed.\n"$(RESET)

re : fclean all

.PHONY : all clean fclean re