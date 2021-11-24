#pragma once

#include <iostream>
#include "model.h"
#include "controller.h"

namespace view {

    class View : public observer::IObserver
    {
    public:

        View(
                const model::ModelPtr &model,
                const controller::ControllerPtr &controller,
                std::ostream &os = std::cout
                )
            : m_model{model}
            , m_controller{controller}
            , m_os{os}
        {
            m_os << "Hello from Amazing Vector Editor!" << std::endl << std::endl;
            m_model->attachObserver(observer::IObserverPtr(this));
        }

        void update() override
        {
            m_os << m_model->modelState();
        }

        void newAction()
        {
            m_controller->createNew();
        }

        void importAction(const std::string &filename)
        {
            m_controller->importFromFile(filename);
        }

        void exportAction(const std::string &filename)
        {
            m_controller->exportToFile(filename);
        }

        void addRectangleAction()
        {
            m_controller->addRectangle(primitive::RectanglePtr(new primitive::Rectangle));
        }

        void addEllipseAction()
        {
            m_controller->addEllipse(primitive::EllipsePtr(new primitive::Ellipse));
        }

        void addTriangleAction()
        {
            m_controller->addTriangle(primitive::TrianglePtr(new primitive::Triangle));
        }

        void removeAction(int index)
        {
            m_controller->removePrimitive(index);
        }

    private:
        model::ModelPtr m_model;
        controller::ControllerPtr m_controller;
        std::ostream &m_os;
    };

    using ViewPtr = std::unique_ptr<View>;
}

