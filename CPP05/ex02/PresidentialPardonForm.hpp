#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm(const std::string& target);

    virtual void execute(Bureaucrat const & executor) const;

private:
    const std::string _target;

    PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
};

#endif // PRESIDENTIALPARDONFORM_HPP
