#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>

/**
 * @brief Класс IPrimitive - интерфейс графического примитива
 */
class IPrimitive
{
public:
    virtual ~IPrimitive() {}
    virtual std::string show() const = 0;
};

#endif // PRIMITIVE_H
