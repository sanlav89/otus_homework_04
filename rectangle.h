#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "iprimitive.h"

/**
 * @brief Класс Rectangle - графический примитив "Прямоугольник"
 */
class Rectangle : public IPrimitive
{
public:
    Rectangle() = default;
    std::string show() const override
    {
        return std::string("[RECTANGLE]");
    }
};

#endif // RECTANGLE_H
