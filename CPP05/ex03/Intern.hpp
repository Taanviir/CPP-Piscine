#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    Intern(const Intern& copy);

    Intern& operator=(const Intern& copy);

    AForm* makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // INTERN_HPP
