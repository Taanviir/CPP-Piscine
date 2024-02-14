#ifndef DEBUG_HPP
# define DEBUG_HPP

/* COLORS */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define GRAY "\e[90m"

/* Printing Debug Message */
# ifdef DEBUG
# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)
# else
# define DEBUG_MESSAGE(message, color) do {} while(0)
# endif

#endif // DEBUG_HPP
