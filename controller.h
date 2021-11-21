#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "imodel.h"
#include "icontroller.h"

/**
 * @brief Класс Controller (MVC)
 */
class Controller : public IController
{
public:
    /**
     * @brief Controller (MVC)
     * @param model - указатель на модель (MVC)
     */
    Controller(IModel *model) : m_model(model) {}

    void createNew() override
    {
        m_model->createNew();
    }

    void importFromFile(const std::string &filename) override
    {
        m_model->importFromFile(filename);
    }

    void exportToFile(const std::string &filename) override
    {
        m_model->exportToFile(filename);
    }

    void addRectangle(Rectangle *rectangle) override
    {
        m_model->addPrimitive(rectangle);
    }

    void addEllipse(Ellipse *ellipse) override
    {
        m_model->addPrimitive(ellipse);
    }

    void addTriangle(Triangle *triangle) override
    {
        m_model->addPrimitive(triangle);
    }

    void removePrimitive(IPrimitive *primitive) override
    {
        m_model->removePrimitive(primitive);
    }

    void selectPrimitive(int index) override
    {
        m_model->selectPrimitive(index);
    }

private:
    IModel *m_model;
};

#endif // CONTROLLER_H
