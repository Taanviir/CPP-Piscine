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
            file.write('# include <iostream>\n\n')
            file.write(f'class {file_name[:-4]} {{\n\npublic:\n')
            if file_name[0].isupper():
                file.write(f'\t{file_name[:-4]}();\n\t~{file_name[:-4]}();\n\t{file_name[:-4]}(const {file_name[:-4]}& copy);\n\n\t{file_name[:-4]}& operator=(const {file_name[:-4]}& copy);')
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

    with open('./Makefile_template', 'r') as template_file:
        makefile_contents = template_file.read()
    
    execname = input("Enter the name of the executable: ")
    makefile_contents = makefile_contents.replace("<program_name>", execname)

    with open(file_path, 'w') as makefile:
        makefile.write(makefile_contents)

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
    elif makefile != "n":
        print("Alright")
    else:
        print("Invalid Input")

if __name__ == "__main__":
    main()
