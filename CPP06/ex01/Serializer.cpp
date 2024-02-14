#include "Serializer.hpp"

Serializer::Serializer() {
    DEBUG_MESSAGE("Serializer constructor called", GRAY);
}

Serializer::Serializer(Serializer const& copy) {
    DEBUG_MESSAGE("Serializer copy constructor called", GRAY);
    (void) copy;
}

Serializer::~Serializer() {
    DEBUG_MESSAGE("Serializer destructor called", GRAY);
}

Serializer& Serializer::operator=(Serializer const& copy) {
    DEBUG_MESSAGE("Serializer assignment operator called", GRAY);
    (void) copy;
    return *this;
}

/**
 * @brief Deserialize a Data object from a raw pointer
 * Basically just cast the raw pointer to a Data pointer
 * 
 * @param raw The raw pointer to deserialize
 * @return Data* The deserialized Data object
*/
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Serialize a Data object into a raw pointer
 * Basically just cast the Data pointer to a raw pointer
 * 
 * @param raw The raw pointer to deserialize
 * @return Data* The deserialized Data object
*/
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}