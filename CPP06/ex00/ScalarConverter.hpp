#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/* Colors */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define GRAY "\e[90m"

/* Printing Debug Message */
# ifdef DEBUG
# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)
# else
# define DEBUG_MESSAGE(message, color) do {} while(0)
# endif

# include <string>

class ScalarConverter {
public:
    ~ScalarConverter();

    static void convert(std::string input);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif // SCALARCONVERTER_HPP
