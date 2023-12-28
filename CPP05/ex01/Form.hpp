#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form {
public:
    Form();
    ~Form();
    Form(const Form& copy);

    Form& operator=(const Form& copy);

    // getters
    const std::string& getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // methods
    void beSigned(const Bureaucrat& bureaucrat);
    void signForm(const Bureaucrat& bureaucrat);

    // exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
