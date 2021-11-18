#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

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
    void performCommand(Command command)
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
            // TODO
            break;
        case CreateEllipse:
            // TODO
            break;
        case CreateTriangle:
            // TODO
            break;
        case DeleteByIndex:
            // TODO
            break;
        default:
            break;
        }
    }

private:
    Model *m_model;
};

#endif // CONTROLLER_H
