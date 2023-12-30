#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm();
    virtual ~AForm();
    AForm(const AForm& copy);
    AForm(const std::string& name);
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);

    AForm& operator=(const AForm& copy);

    // getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // methods
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif // AFORM_HPP
