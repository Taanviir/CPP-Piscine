#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

/* COLORS */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define YELLOW_B "\e[1;33m"

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
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, const int grade);

    Bureaucrat& operator=(const Bureaucrat& copy);

    const std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

    // exceptions
    class GradeTooHighException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    std::string const _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif // BUREAUCRAT_HPP
