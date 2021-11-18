#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>
#include "iobservable.h"

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
        notify();
    }

    /**
     * @brief Импорт документа из файла
     * @param filename[in] - имя файла
     */
    void importFromFile(const std::string &filename)
    {
        m_logMessage = "Document was imported from file " + filename;
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

    void createPrimitive()
    {
        // TODO
        notify();
    }

    void deletePrimitive()
    {
        // TODO
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
     * @brief Состояние модели
     */
    void info()
    {
        std::cout << "[LOG]: " << m_logMessage << std::endl;
        std::cout << "[STATE]: " << std::endl;
        std::cout << "    Document is empty..." << std::endl;
    }

private:
    std::string m_logMessage;
    std::list<IObserver *> m_observers;


};

#endif // MODEL_H
