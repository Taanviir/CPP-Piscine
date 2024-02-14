#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "debug.hpp"
# include <string>
# include <iostream>

typedef unsigned long int uintptr_t;

struct Data {
    std::string firstName;
    std::string surname;
    int age;
    std::string email;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(Serializer const& copy);
    ~Serializer();
    Serializer &operator=(Serializer const& copy);
};

#endif // SERIALIZER_HPP
