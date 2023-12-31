#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
public:
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm(const std::string& target);

    virtual void execute(Bureaucrat const & executor) const;

private:
    const std::string _target;

    ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
};

#endif // SHRUBBERYCREATIONFORM_HPP
