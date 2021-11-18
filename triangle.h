#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "primitive.h"

class Triangle : public Primitive
{
public:
    Triangle() = default;
    std::string show() const override
    {
        return std::string("<TRIANGLE>");
    }
};

#endif // TRIANGLE_H
