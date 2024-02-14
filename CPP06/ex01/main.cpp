#include "Serializer.hpp"

int main(void) {
    Data* data = new Data();
    data->firstName = "John";
    data->surname = "Doe";
    data->age = 42;
    data->email = "example@email.com";

    uintptr_t serialized = Serializer::serialize(data);

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "First name: " << deserialized->firstName << std::endl;
    std::cout << "Surname: " << deserialized->surname << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Email: " << deserialized->email << std::endl;

    if (data == deserialized)
        std::cout << "Data pointers are the same" << std::endl;
    else
        std::cout << "Data pointers are different" << std::endl;

    delete deserialized; // able to delete deserialized because it's a copy of data
    return 0;
}
