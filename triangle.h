#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "iprimitive.h"

/**
 * @brief Класс Rectangle - графический примитив "Треугольник"
 */
class Triangle : public IPrimitive
{
public:
    Triangle() = default;
    std::string show() const override
    {
        return std::string("<TRIANGLE>");
    }
};

#endif // TRIANGLE_H
