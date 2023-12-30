#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& copy);

    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

    virtual void execute(Bureaucrat const & executor) const;

private:

};

#endif // ROBOTOMYREQUESTFORM_HPP
