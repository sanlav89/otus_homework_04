#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>

class Primitive
{
public:
    virtual ~Primitive() {}
    virtual std::string show() const = 0;
};

#endif // PRIMITIVE_H
