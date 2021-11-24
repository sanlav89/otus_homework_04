#pragma once

#include <memory>

namespace observer {

    class IObserver
    {
    public:
        virtual ~IObserver() {}
        virtual void update() = 0;
    };

    using IObserverPtr = std::shared_ptr<IObserver>;
}
