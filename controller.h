#pragma once

#include "model.h"
#include "primitive.h"

namespace controller {

    class Controller
    {
    public:

        Controller(const model::ModelPtr &model) : m_model(model) {}

        void createNew()
        {
            m_model->createNew();
        }

        void importFromFile(const std::string &filename)
        {
            m_model->importFromFile(filename);
        }

        void exportToFile(const std::string &filename)
        {
            m_model->exportToFile(filename);
        }

        void addRectangle(const primitive::RectanglePtr &rectangle)
        {
            m_model->addPrimitive(rectangle);
        }

        void addEllipse(const primitive::EllipsePtr &ellipse)
        {
            m_model->addPrimitive(ellipse);
        }

        void addTriangle(const primitive::TrianglePtr &triangle)
        {
            m_model->addPrimitive(triangle);
        }

        void removePrimitive(const primitive::IPrimitivePtr &primitive)
        {
            m_model->removePrimitive(primitive);
        }

        void selectPrimitive(int index)
        {
            m_model->selectPrimitive(index);
        }

    private:
        model::ModelPtr m_model;
    };

    using ControllerPtr = std::shared_ptr<Controller>;

}

