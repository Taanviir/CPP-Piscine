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

# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()

using std::string;

class ScalarConverter {
public:
    ~ScalarConverter();

    static void convert(string input);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif // SCALARCONVERTER_HPP
