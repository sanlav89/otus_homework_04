#ifndef IOBSERVER_H
#define IOBSERVER_H

/**
 * @brief Класс IObserver - интерфейс "наблюдателя" (паттерн "наблюдатель")
 */
class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update() = 0;
};

#endif // IOBSERVER_H
