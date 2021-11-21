#ifndef VECTOREDITOR_H
#define VECTOREDITOR_H

#include "model.h"
#include "view.h"
#include "controller.h"

/**
 * @brief Класс VectorEditor - класс векторного редактора
 */
class VectorEditor
{
public:

    /**
     * @brief VectorEditor
     */
    VectorEditor() :
        m_model{Model()},
        m_view{View(&m_model)},
        m_controller{Controller(&m_model)}
    {
    }

    /**
     * @brief Вызов соответствующего метода Controller::performCommand
     * @param command[in] - идентификатор команды
     * @param index[in] - индекс удалаемого примитива
     */
    void performCommand(Controller::Command command, int index = -1)
    {
        m_controller.performCommand(command, index);
    }

private:
    Model m_model;
    View m_view;
    Controller m_controller;
};

#endif // VECTOREDITOR_H
