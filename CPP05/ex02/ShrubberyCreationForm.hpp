#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

    virtual void execute(Bureaucrat const & executor) const;

private:

};

#endif // SHRUBBERYCREATIONFORM_HPP
