#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"

class Controller
{
public:

    enum Command {
        Create,
        Import,
        Export,
        CreateRectangle,
        CreateEllipse,
        CreateTriangle,
        DeleteByIndex
    };

    Controller(Model *model) : m_model(model) {}

    /**
     * @brief Действия пользователя векторного редактора
     * @param command[in] - идентификатор команды
     */
    void performCommand(Command command, int index = -1)
    {
        switch (command) {
        case Create:
            m_model->createNew();
            break;
        case Import:
            m_model->importFromFile("my_file_in.txt");
            break;
        case Export:
            m_model->exportToFile("my_file_out.txt");
            break;
        case CreateRectangle:
            m_model->addPrimitive(new Rectangle);
            break;
        case CreateEllipse:
            m_model->addPrimitive(new Ellipse);
            break;
        case CreateTriangle:
            m_model->addPrimitive(new Triangle);
            break;
        case DeleteByIndex:
            m_model->removePrimitive(m_model->primitive(index));
            break;
        default:
            break;
        }
    }

private:
    Model *m_model;
};

#endif // CONTROLLER_H
