#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
public:
    static void calculate(std::string const& input);

private:
    static std::stack<int> _numberStack;
    static int extractNumber(std::string::const_iterator &strItr);

    RPN();
    ~RPN();
    RPN(RPN const& copy);
    RPN& operator=(RPN const& copy);
};

#endif // RPN_HPP
