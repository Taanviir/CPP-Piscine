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

# include <cctype>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

# define MAX_UCHAR std::numeric_limits<unsigned char>::max()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()

using std::string;

enum inputType {
    CHAR = 0,
    INT,
    FLOAT,
    DOUBLE,
    ERROR
};

class ScalarConverter {
public:
    ~ScalarConverter();

    static void convert(string input);

private:
    static inputType _type;
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
};

#endif // SCALARCONVERTER_HPP
