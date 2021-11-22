#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <cassert>
#include "imodel.h"

/**
 * @brief Класс Model (MVC)
 */
class Model : public IModel
{
public:
    Model()
    {
        m_logMessage = "";
        m_currentPrimitive = nullptr;
    }

    ~Model()
    {
        while (m_primitives.size() > 0) {
            delete m_primitives.back();
            m_primitives.pop_back();
        }
    }

    /**
     * @brief Создание нового документа
     */
    void createNew() override
    {
        m_logMessage = "New document was created";
        removeOldPrimitives();
        notifyObservers();
    }

    /**
     * @brief Импорт документа из файла
     * @param[in] filename - имя файла
     */
    void importFromFile(const std::string &filename) override
    {
        m_logMessage = "Document was imported from file " + filename;
        removeOldPrimitives();
        notifyObservers();
    }

    /**
     * @brief Экспорт документа в файл
     * @param[in] filename - имя файла
     */
    void exportToFile(const std::string &filename) override
    {
        m_logMessage = "Document was exported to file " + filename;
        notifyObservers();
    }

    /**
     * @brief Добавление графического примитива
     * @param[in] primitive - указатель на вновь созданный графический примитив
     */
    void addPrimitive(IPrimitive *primitive) override
    {
        m_logMessage = primitive->show() + " was added to document";
        m_primitives.push_back(primitive);
        m_currentPrimitive = m_primitives.back();
        notifyObservers();
    }

    /**
     * @brief Удаление графического примитива
     * @param[in] primitive - указатель на удаляемый графический примитив
     */
    void removePrimitive(IPrimitive *primitive) override
    {
        m_logMessage = primitive->show() + " was removed from document";
        m_primitives.remove(primitive);
        delete primitive;
        m_currentPrimitive = m_primitives.size() > 0 ? m_primitives.back() : nullptr;
        notifyObservers();
    }

    /**
     * @brief Добавление "наблюдателя"
     */
    void attachObserver(IObserver *observer) override
    {
        m_observers.push_back(observer);
    }

    /**
     * @brief Удаление "наблюдателя"
     */
    void detachObserver(IObserver *observer) override
    {
        m_observers.remove(observer);
    }

    /**
     * @brief Оповещение "наблюдателей" о состоянии модели
     */
    void notifyObservers() override
    {
        for (auto observer : m_observers) {
            observer->update();
        }
    }

    /**
     * @brief Выбор текущего примитива по индексу
     * @param[in] index - индекс
     */
    void selectPrimitive(int index) override
    {
        if (index >= 0 && index < static_cast<int>(m_primitives.size())) {
            auto front = m_primitives.begin();
            std::advance(front, index);
            m_currentPrimitive = *front;
        }
    }

    /**
     * @brief Статус-сообщение о состоянии модели (обновляется после каждого изменения модели).
     * @return сообщение в формате std::string
     */
    std::string modelState() const override
    {
        return "|-LOG---| " + m_logMessage + "\n" + primitivesState();
    }

    /**
     * @brief Текущий (активный) примитив
     * @return Указатель на текущий (активный примитив)
     */
    IPrimitive *currentPrimitive() const override
    {
        return  m_currentPrimitive;
    }

private:
    IPrimitive *m_currentPrimitive;
    std::string m_logMessage;
    std::list<IObserver *> m_observers;
    std::list<IPrimitive *> m_primitives;

    void removeOldPrimitives()
    {
        if (m_primitives.size() > 0) {
            m_primitives.clear();
            m_logMessage.append(". All old Primitives was removed");
        }
        m_currentPrimitive = nullptr;
    }

    std::string primitivesState() const
    {
        std::string result;
        result += "|-STATE-| ";
        if (m_primitives.empty()) {
            result += "Document is empty... \n";
        } else {
            result += "Primitives: \n";
            auto index = 0;
            for (auto primitive : m_primitives) {
                result += "    " + std::to_string(index++) + ": " + primitive->show() + "\n";
            }
        }
        result += "\n";
        return result;
    }

};

#endif // MODEL_H
