#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& copy);

    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

    virtual void execute(Bureaucrat const & executor) const;

private:

};

#endif // PRESIDENTIALPARDONFORM_HPP
