"""
This script file creates C++ class files in the orthodox canonical form.

Usage: python3 create_files.py [output_path]

Program loop:
Ask what the user wants to create (Makefile, C++ class, debug file, main)
Create the files
Ask if the user wants to create more files (repeat loop basically)
"""

import os
import sys
from platform import system

def generate_makefile(output_path="./"):
    if output_path != "./":
        file_path = os.path.join(output_path, "Makefile")
    else:
        file_path = "Makefile"

    execname = input("Enter the name of the executable (type n to cancel): ")
    if execname == "n":
        print("Cancelling request...")
        return

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
        
        makefile.write("valgrind : CPPFLAGS+=-g3 -DDEBUG\n")
        makefile.write("valgrind : re\n")
        makefile.write("\t@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)\n\n")
        
        makefile.write("debug : CPPFLAGS+=-g3 -fsanitize=address -DDEBUG\n")
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

def create_cpp_class(output_path="./"):
    class_name = input("Enter the name of the class (type n to cancel): ")
    if class_name == "n":
        print("Cancelling request...")
        return
    if output_path != "./":
        file_path = os.path.join(output_path, class_name)

    with open(f"{file_path}.hpp", 'w') as hpp_file:
        hpp_file.write(f"#ifndef {class_name.upper()}_HPP\n")
        hpp_file.write(f"# define {class_name.upper()}_HPP\n\n")
        hpp_file.write(f"class {class_name} ")
        hpp_file.write("{\n")
        hpp_file.write("public:\n")
        hpp_file.write(f"    {class_name}();\n")
        hpp_file.write(f"    {class_name}({class_name} const& copy);\n")
        hpp_file.write(f"    ~{class_name}();\n")
        hpp_file.write(f"    {class_name} &operator=({class_name} const& copy);\n")
        hpp_file.write("\nprivate:\n")
        hpp_file.write("};\n\n")
        hpp_file.write(f"#endif //{class_name.upper()}_HPP\n")

    with open(f"{file_path}.cpp", 'w') as cpp_file:
        cpp_file.write(f'#include "{class_name}.hpp"\n\n')
        cpp_file.write(f"{class_name}::{class_name}() ") # constructor
        cpp_file.write("{\n\n}\n\n")
        cpp_file.write(f"{class_name}::{class_name}({class_name} const& copy) ") # copy constructor
        cpp_file.write("{\n\n}\n\n")
        cpp_file.write(f"{class_name}::~{class_name}() ") # destructor
        cpp_file.write("{\n\n}\n\n")
        cpp_file.write(f"{class_name}& {class_name}::operator=({class_name} const& copy) ") # assignment operator
        cpp_file.write("{\n")
        cpp_file.write("    return *this;\n")
        cpp_file.write("}\n\n")

def create_debug_file(output_path="./"):
    if output_path != "./":
        file_path = os.path.join(output_path, "debug.hpp")
    else:
        file_path = "debug.hpp"
    opt = input("Do you wish to create a debug.hpp file (y/n): ")
    if opt == "n":
        print("Cancelling request...")
        return

    with open(file_path, 'w') as debug_file:
        debug_file.write("#ifndef DEBUG_HPP\n")
        debug_file.write("# define DEBUG_HPP\n\n")
        debug_file.write("/* COLORS */\n")
        debug_file.write("# define WHITE \"\\e[0m\"\n")
        debug_file.write("# define RED \"\\e[31m\"\n")
        debug_file.write("# define GRAY \"\\e[90m\"\n\n")
        debug_file.write("/* Printing Debug Message */\n")
        debug_file.write("# ifdef DEBUG\n")
        debug_file.write("# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)\n")
        debug_file.write("# else\n")
        debug_file.write("# define DEBUG_MESSAGE(message, color) do {} while(0)\n")
        debug_file.write("# endif\n\n")
        debug_file.write("#endif // DEBUG_HPP\n")

def create_main_file(output_path="./"):
    if output_path != "./":
        file_path = os.path.join(output_path, "main.cpp")
    else:
        file_path = "main.cpp"

    opt = input("Do you wish to create a main.cpp file (y/n): ")
    if opt == "n":
        print("Cancelling request...")
        return

    with open(file_path, 'w') as main_file:
        main_file.write("#include <iostream>\n\n")
        main_file.write("int main() {\n")
        main_file.write("    // Your code here\n")
        main_file.write("    return 0;\n")
        main_file.write("}\n")

def main():
    if len(sys.argv) > 2:
        print("Usage: python3 create_files.py [output_path]")
        sys.exit(1)
    elif len(sys.argv) == 2:
        output_path = sys.argv[1]
    else:
        output_path = "./"
    os.system("clear" if system() == "Darwin" or system() == "Linux" else "cls")
    print("What do you want to create?")
    print("1. Makefile")
    print("2. C++ class")
    print("3. Debug file")
    print("4. Main file")
    print("5. Exit")

    while (True):
        option = input("Enter the option number here: ")
        if option == "1":
            generate_makefile(output_path)
        elif option == "2":
            create_cpp_class(output_path)
        elif option == "3":
            create_debug_file(output_path)
        elif option == "4":
            create_main_file(output_path)
        elif option == "5" or option == "exit" or option == "Exit":
            print("Exiting...")
            break
        else:
            print("Invalid Input")

if __name__ == "__main__":
    main()