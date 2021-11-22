#ifndef IMODEL_H
#define IMODEL_H

#include "iprimitive.h"
#include "iobserver.h"

/**
 * @brief Класс IModel - интерфейс модели (MVC)
 */
class IModel
{
public:
    virtual ~IModel() = default;
    virtual void createNew() = 0;
    virtual void importFromFile(const std::string &) = 0;
    virtual void exportToFile(const std::string &) = 0;
    virtual void addPrimitive(IPrimitive *) = 0;
    virtual void removePrimitive(IPrimitive *) = 0;
    virtual void attachObserver(IObserver *) = 0;
    virtual void detachObserver(IObserver *) = 0;
    virtual void notifyObservers() = 0;
    virtual void selectPrimitive(int) = 0;
    virtual IPrimitive *currentPrimitive() const = 0;
    virtual std::string modelState() const = 0;
};

#endif // IMODEL_H
