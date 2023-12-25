#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

/* COLORS */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW_B "\e[1;33m"
# define BLUE "\e[34m"
# define CYAN "\e[36m"
# define GRAY "\e[90m"
# define WHITE_B "\e[1m"

/* Printing Debug Message */
# ifdef DEBUG
# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)
# else
# define DEBUG_MESSAGE(message, color) do {} while(0)
# endif

class Bureaucrat {
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat(std::string* const name);
    Bureaucrat(std::string& const name);
    Bureaucrat(std::string& const name, int const grade);

    Bureaucrat& operator=(const Bureaucrat& copy);

    const std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

    // exceptions

private:
    std::string const _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif // BUREAUCRAT_HPP
