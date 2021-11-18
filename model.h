#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <iterator>
#include "iobservable.h"
#include "primitive.h"

class Model : public IObservable
{
public:
    Model() = default;

    /**
     * @brief Создание нового документа
     */
    void createNew()
    {
        m_logMessage = "New document was created";
        removeOldPrimitives();
        notify();
    }

    /**
     * @brief Импорт документа из файла
     * @param filename[in] - имя файла
     */
    void importFromFile(const std::string &filename)
    {
        m_logMessage = "Document was imported from file " + filename;
        removeOldPrimitives();
        notify();
    }

    /**
     * @brief Экспорт документа в файл
     * @param filename[in] - имя файла
     */
    void exportToFile(const std::string &filename)
    {
        m_logMessage = "Document was exported to file " + filename;
        notify();
    }

    /**
     * @brief Добавление графического примитива
     * @param primitive - указатель на вновь созданный графический примитив
     */
    void addPrimitive(Primitive *primitive)
    {
        m_logMessage = primitive->show() + " was added to document";
        m_primitives.push_back(primitive);
        notify();
    }

    /**
     * @brief Удаление графического примитива
     * @param primitive - указатель на удаляемый графический примитив
     */
    void removePrimitive(Primitive *primitive)
    {
        m_logMessage = primitive->show() + " was removed from document";
        m_primitives.remove(primitive);
        notify();
    }

    /**
     * @brief Добавление "наблюдателя"
     */
    void attach(IObserver *observer) override
    {
        m_observers.push_back(observer);
    }

    /**
     * @brief Удаление "наблюдателя"
     */
    void detach(IObserver *observer) override
    {
        m_observers.remove(observer);
    }

    /**
     * @brief Оповещение "наблюдателей" о состоянии модели
     */
    void notify() override
    {
        for (auto observer : m_observers) {
            observer->update();
        }
    }

    /**
     * @brief Лог-сообщение (обновляется после каждого изменения модели).
     * @return сообщение в формате std::string
     */
    std::string logMessage() const
    {
        return m_logMessage;
    }

    /**
     * @brief Список графических примитивов
     * @return Список указателей на графические примитивы
     */
    std::list<Primitive *> primitives() const
    {
        return m_primitives;
    }

    /**
     * @brief Получение указателя на графический примитив по индексу
     * @param index[in] - индекс
     * @return Указатель на графический примитив
     */
    Primitive *primitive(int index) const
    {
        assert(index >= 0 && index < static_cast<int>(m_primitives.size()));
        auto front = m_primitives.begin();
        std::advance(front, index);
        return *front;
    }

private:
    std::string m_logMessage;
    std::list<IObserver *> m_observers;
    std::list<Primitive *> m_primitives;

    void removeOldPrimitives()
    {
        if (m_primitives.size() > 0) {
            m_primitives.clear();
            m_logMessage.append(". All old Primitives was removed");
        }
    }

};

#endif // MODEL_H
