#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "iprimitive.h"

/**
 * @brief Класс Ellipse - графический примитив "Эллипс"
 */
class Ellipse : public IPrimitive
{
public:
    Ellipse() = default;
    std::string show() const override
    {
        return std::string("(ELLIPSE)");
    }
};

#endif // ELLIPSE_H
