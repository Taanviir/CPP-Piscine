#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>

class RPN {
public:
    RPN();
    ~RPN();

private:
    RPN(RPN const& copy);
    RPN& operator=(RPN const& copy);
};

#endif // RPN_HPP
