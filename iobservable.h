#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include "iobserver.h"

/**
 * @brief Класс IObservable - интерфейс наблюдаемого объекта (паттерн "наблюдатель")
 */
class IObservable
{
public:
    virtual ~IObservable() {}
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify() = 0;
};

#endif // IOBSERVABLE_H
