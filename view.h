#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <cassert>
#include "imodel.h"
#include "icontroller.h"

/**
 * @brief Класс View (MVC) с интерфейсом "наблюдателя"
 */
class View : public IObserver
{
public:

    /*! Идентификаторы команд редактора */
    enum class Action {
        Create,             /*!< для создания нового документа */
        Import,             /*!< для импорта документа из файла */
        Export,             /*!< для экспорта документа в файл */
        CreateRectangle,    /*!< для создания примитива "Прямоугольник" */
        CreateEllipse,      /*!< для создания примитива "Эллипс" */
        CreateTriangle,     /*!< для создания примитива "Треугольник" */
        RemovePrimitive,    /*!< для удаления текущего примитива */
        SelectPrimitive     /*!< для выбора примитива */
    };

    /**
     * @brief View
     * @param model - указатель на объект модели (MVC)
     * @param os - выходной текстовый поток
     */
    View(IModel *model, IController *controller, std::ostream &os = std::cout)
        : m_model{model}
        , m_controller{controller}
        , m_os{os}
    {
        m_model->attachObserver(this);
    }

    /**
     * @brief Обновление представления модели (интерфейс "наблюдателя")
     */
    void update() override
    {
        m_os << m_model->modelState();
    }

    /**
     * @brief Имитация событий View (без дополнительнрых параметров)
     * @param[in] action - идентификатор события
     */
    void execute(Action action)
    {
        assert(action >= Action::Create
                && action < Action::SelectPrimitive
                && action != Action::Import
                && action != Action::Export);
        switch (action) {
        case Action::Create:
            m_model->createNew();
            break;
        case Action::CreateRectangle:
            m_model->addPrimitive(new Rectangle);
            break;
        case Action::CreateEllipse:
            m_model->addPrimitive(new Ellipse);
            break;
        case Action::CreateTriangle:
            m_model->addPrimitive(new Triangle);
            break;
        case Action::RemovePrimitive:
            m_model->removePrimitive(m_model->currentPrimitive());
            break;
        default:
            break;
        }
    }

    /**
     * @brief Имитация событий View (с дополнительныйм параметром типа int)
     * @param[in] action - идентификатор события
     * @param[in] index - индекс выбираемого примитива
     */
    void execute(Action action, int index)
    {
        assert(action == Action::SelectPrimitive);
        m_controller->selectPrimitive(index);
    }

    /**
     * @brief Имитация событий View (с дополнительныйм параметром типа string)
     * @param action - идентификатор события
     * @param filename - имя импортируемого / экспортируемого файла
     */
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
    IModel *m_model;
    IController *m_controller;
    std::ostream &m_os;
};

#endif // VIEW_H
