#pragma once

#include <string>
#include <memory>

namespace primitive {

    class IPrimitive
    {
        public:
        virtual ~IPrimitive() {}
        virtual std::string show() const = 0;
    };

    class Rectangle : public IPrimitive
    {
    public:
        Rectangle() = default;
        std::string show() const override
        {
            return std::string("[RECTANGLE]");
        }
    };

    class Triangle : public IPrimitive
    {
    public:
        Triangle() = default;
        std::string show() const override
        {
            return std::string("<TRIANGLE>");
        }
    };

    class Ellipse : public IPrimitive
    {
    public:
        Ellipse() = default;
        std::string show() const override
        {
            return std::string("(ELLIPSE)");
        }
    };

    using IPrimitivePtr = std::shared_ptr<IPrimitive>;
    using RectanglePtr = std::shared_ptr<Rectangle>;
    using TrianglePtr = std::shared_ptr<Triangle>;
    using EllipsePtr = std::shared_ptr<Ellipse>;

}
