#pragma once

#include <iostream>
#include "model.h"
#include "controller.h"
#include "observer.h"

namespace view {

    /*! Actions */
    enum class Action {
        Create,             /*!< create new document */
        Import,             /*!< import from file */
        Export,             /*!< export to file */
        CreateRectangle,    /*!< create rectangle */
        CreateEllipse,      /*!< create ellipse */
        CreateTriangle,     /*!< create triangle */
        RemovePrimitive,    /*!< remove primitive */
        SelectPrimitive     /*!< select primitive */
    };

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

        void execute(Action action)
        {
            assert(action >= Action::Create
                    && action < Action::SelectPrimitive
                    && action != Action::Import
                    && action != Action::Export);
            switch (action) {
            case Action::Create:
                m_controller->createNew();
                break;
            case Action::CreateRectangle:
                m_controller->addRectangle(primitive::RectanglePtr(new primitive::Rectangle));
                break;
            case Action::CreateEllipse:
                m_controller->addEllipse(primitive::EllipsePtr(new primitive::Ellipse));
                break;
            case Action::CreateTriangle:
                m_controller->addTriangle(primitive::TrianglePtr(new primitive::Triangle));
                break;
            case Action::RemovePrimitive:
                m_controller->removePrimitive(m_model->currentPrimitive());
                break;
            default:
                break;
            }
        }

        void execute(Action action, int index)
        {
            assert(action == Action::SelectPrimitive);
            m_controller->selectPrimitive(index);
        }

        void execute(Action action, const std::string &filename)
        {
            assert(action == Action::Import || action == Action::Export);
            if (action == Action::Import) {
                m_controller->importFromFile(filename);
            } else {
                m_controller->exportToFile(filename);
            }
        }

    private:
        model::ModelPtr m_model;
        controller::ControllerPtr m_controller;
        std::ostream &m_os;
    };

    using ViewPtr = std::unique_ptr<View>;
}

