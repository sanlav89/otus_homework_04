#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "primitive.h"

class Rectangle : public Primitive
{
public:
    Rectangle() = default;
    std::string show() const override
    {
        return std::string("[RECTANGLE]");
    }
};

#endif // RECTANGLE_H
