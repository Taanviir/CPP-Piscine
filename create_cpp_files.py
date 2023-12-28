import os
import sys

def create_cpp_file(file_name, output_path="./"):
    if output_path != "./":
        file_path = os.path.join(output_path, file_name)
    else:
        file_path = file_name

    with open(file_path, 'w') as file:
        if file_name.endswith(".hpp"):
            # Header file
            file.write(f'#ifndef {file_name.upper()[:-4]}_HPP\n')
            file.write(f'# define {file_name.upper()[:-4]}_HPP\n\n')
            file.write(f'class {file_name[:-4]} {{\npublic:\n')
            if file_name[0].isupper():
                file.write(f'    {file_name[:-4]}();\n    ~{file_name[:-4]}();\n    {file_name[:-4]}(const {file_name[:-4]}& copy);\n\n    {file_name[:-4]}& operator=(const {file_name[:-4]}& copy);')
            file.write(f'\n\nprivate:\n\n}};\n\n')
            file.write(f'#endif // {file_name.upper()[:-4]}_HPP\n')
        elif file_name.endswith(".cpp"):
            # Source file
            if file_name == "main.cpp":
                file.write('#include <iostream>\n\n')
                file.write('int main() {\n    // Your code here\n    return 0;\n}\n')
            else:
                file.write('#include ')
                file.write(f'"{file_name[:-4]}.hpp"\n\n')
        else:
            print(f"Unsupported file type: {file_name}")

def generate_makefile(output_path="./"):
    if output_path != "./":
        file_path = os.path.join(output_path, "Makefile")
    else:
        file_path = "Makefile"

    execname = input("Enter the name of the executable: ")

    with open(file_path, 'w') as makefile:
        makefile.write("### COLORS\n")
        makefile.write("GREEN_B = \"\\033[1;32m\"\n")
        makefile.write("RED_B = \"\\033[1;31m\"\n")
        makefile.write("BLUE_I = \"\\033[2;34m\"\n")
        makefile.write("RESET = \"\\033[0m\"\n\n")
        
        makefile.write(f"NAME = {execname}\n")
        makefile.write("CPPFLAGS = -Wall -Werror -Wextra -std=c++98\n\n")
        
        makefile.write("SRCS = $(wildcard *.cpp)\n\n")
        
        makefile.write("OBJ_DIR = obj/\n")
        makefile.write("OBJS_LIST = $(SRCS:.cpp=.o)\n")
        makefile.write("OBJS = $(addprefix $(OBJ_DIR), $(OBJS_LIST))\n\n")
        
        makefile.write("all : $(NAME)\n\n")
        
        makefile.write("$(NAME) : $(OBJS)\n")
        makefile.write("\t@c++ $(CPPFLAGS) $(OBJS) -o $@\n")
        makefile.write("\t@echo $(GREEN_B)$(NAME)$(RESET)\" is ready. ✅\\n\"\n\n")
        
        makefile.write("$(OBJ_DIR)%.o : %.cpp\n")
        makefile.write("\t@mkdir -p $(OBJ_DIR)\n")
        makefile.write("\t@c++ $(CPPFLAGS) -I./ -c $< -o $@\n")
        makefile.write("\t@echo $(BLUE_I)\"Compiling $<.\"$(RESET)\n\n")
        
        makefile.write("valgrind : CPPFLAGS+=-g3\n")
        makefile.write("valgrind : re\n")
        makefile.write("\t@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)\n\n")
        
        makefile.write("debug : CPPFLAGS+=-g3 -fsanitize=address\n")
        makefile.write("debug : re\n")
        makefile.write("\t@./$(NAME)\n\n")
        
        makefile.write("clean :\n")
        makefile.write("\t@rm -rf $(OBJ_DIR)\n")
        makefile.write("\t@echo $(RED_B)\"Object files removed.\"$(RESET)\n\n")
        
        makefile.write("fclean : clean\n")
        makefile.write("\t@rm -f $(NAME)\n")
        makefile.write("\t@echo $(RED_B)\"$(NAME) removed.\\n\"$(RESET)\n\n")
        
        makefile.write("re : fclean all\n\n")
        
        makefile.write(".PHONY : all clean fclean re\n")

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 create_cpp_files.py <file1> <file2> ... [output_path]")
        return

    output_path = "./"
    if len(sys.argv) > 2 and not sys.argv[-1].endswith(".cpp") and not sys.argv[-1].endswith(".hpp"):
        output_path = sys.argv[-1]
        for file_name in sys.argv[1:-1]:
            create_cpp_file(file_name, output_path)
    else:
        for file_name in sys.argv[1:]:
            create_cpp_file(file_name, output_path)

    makefile = input("Do you want to create a Makefile? (y/n) ")
    if makefile == "y":
        generate_makefile(output_path)
    elif makefile == "n":
        print("Alright")
    else:
        print("Invalid Input")

if __name__ == "__main__":
    main()
