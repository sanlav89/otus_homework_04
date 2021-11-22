#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"

/**
 * @brief Класс IController - интерфейс контроллера (MVC)
 */
class IController
{
public:
    virtual ~IController() = default;
    virtual void createNew() = 0;
    virtual void importFromFile(const std::string &) = 0;
    virtual void exportToFile(const std::string &) = 0;
    virtual void addRectangle(Rectangle *) = 0;
    virtual void addEllipse(Ellipse *) = 0;
    virtual void addTriangle(Triangle *) = 0;
    virtual void removePrimitive(IPrimitive *) = 0;
    virtual void selectPrimitive(int) = 0;
};

#endif // ICONTROLLER_H
