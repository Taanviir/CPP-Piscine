#ifndef DEBUG_HPP
# define DEBUG_HPP

/* COLORS */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"

/* Printing Debug Message */
# ifdef DEBUG
# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)
# else
# define DEBUG_MESSAGE(message, color) do {} while(0)
# endif

#endif // DEBUG_HPP
