#ifndef VIEW_H
#define VIEW_H

#include "model.h"

/**
 * @brief Класс View (MVC) с интерфейсом "наблюдателя"
 */
class View : public IObserver
{
public:
    /**
     * @brief View
     * @param model - указатель на объект модели (MVC)
     * @param os - выходной текстовый поток
     */
    View(Model *model, std::ostream &os = std::cout)
        : m_model{model}
        , m_os{os}
    {
        m_model->attach(this);
    }

    /**
     * @brief Обновление представления модели (интерфейс "наблюдателя")
     */
    void update() override
    {
        m_os << "[LOG]: " << m_model->logMessage() << std::endl;
        m_os << "[STATE]: " << std::endl;
        if (m_model->primitives().empty()) {
            m_os << "    Document is empty..." << std::endl;
        } else {
            auto index = 0;
            for (auto primitive : m_model->primitives()) {
                m_os << "    " << index++ << ": " << primitive->show() << std::endl;
            }
        }
        m_os << std::endl;
    }

private:
    Model *m_model;
    std::ostream &m_os;
};

#endif // VIEW_H
