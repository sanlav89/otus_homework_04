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
        std::cout << "New document was created" << std::endl;
    }

    /**
     * @brief Импорт документа из файла
     * @param filename[in] - имя файла
     */
    void importFromFile(const std::string &filename)
    {
        std::cout << "Document was imported from file " << filename << std::endl;
    }

    /**
     * @brief Экспорт документа в файл
     * @param filename[in] - имя файла
     */
    void exportToFile(const std::string &filename)
    {
        std::cout << "Document was exported to file " << filename << std::endl;
    }

    void createPrimitive()
    {

    }

    void deletePrimitive()
    {

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

private:
    std::list<IObserver *> m_observers;


};

#endif // MODEL_H
