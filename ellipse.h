#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "primitive.h"

class Ellipse : public Primitive
{
public:
    Ellipse() = default;
    std::string show() override
    {
        return std::string("(ELLIPSE)");
    }
};

#endif // ELLIPSE_H
