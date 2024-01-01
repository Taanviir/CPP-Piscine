#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "Form.hpp"

/* COLORS */
# define WHITE "\e[0m"
# define RED "\e[31m"
# define YELLOW_B "\e[1;33m"
# define BLUE "\e[34m"
# define GRAY "\e[90m"

/* Printing Debug Message */
# ifdef DEBUG
# define DEBUG_MESSAGE(message, color) do {std::cout << (color) << message << WHITE << std::endl; } while(0)
# else
# define DEBUG_MESSAGE(message, color) do {} while(0)
# endif

class Form;

class Bureaucrat {
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, const int grade);

    Bureaucrat& operator=(const Bureaucrat& copy);

    const std::string& getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(Form& form);

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
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif // BUREAUCRAT_HPP
