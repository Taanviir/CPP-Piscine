#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
public:
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm(const std::string& target);

    virtual void execute(Bureaucrat const & executor) const;

private:
    const std::string _target;

    RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
};

#endif // ROBOTOMYREQUESTFORM_HPP
