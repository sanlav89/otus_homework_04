#pragma once

#include <list>
#include <cassert>
#include <memory>
#include "primitive.h"
#include "observer.h"

namespace model {

    class Model
    {
    public:
        Model()
        {
            m_logMessage = "";
            m_currentPrimitive = nullptr;
        }

        void createNew()
        {
            m_logMessage = "New document was created";
            removeOldPrimitives();
            notifyObservers();
        }

        void importFromFile(const std::string &filename)
        {
            m_logMessage = "Document was imported from file " + filename;
            removeOldPrimitives();
            notifyObservers();
        }

        void exportToFile(const std::string &filename)
        {
            m_logMessage = "Document was exported to file " + filename;
            notifyObservers();
        }

        void addPrimitive(const primitive::IPrimitivePtr &primitive)
        {
            m_logMessage = primitive->show() + " was added to document";
            m_primitives.push_back(primitive);
            m_currentPrimitive = m_primitives.back();
            notifyObservers();
        }

        void removePrimitive(const primitive::IPrimitivePtr &primitive)
        {
            m_logMessage = primitive->show() + " was removed from document";
            m_primitives.remove(primitive);
            m_currentPrimitive = m_primitives.size() > 0 ? m_primitives.back() : nullptr;
            notifyObservers();
        }

        void attachObserver(const observer::IObserverPtr &observer)
        {
            m_observers.push_back(observer);
        }

        void detachObserver(const observer::IObserverPtr &observer)
        {
            m_observers.remove(observer);
        }

        void notifyObservers()
        {
            for (auto &observer : m_observers) {
                observer->update();
            }
        }

        void selectPrimitive(int index)
        {
            if (index >= 0 && index < static_cast<int>(m_primitives.size())) {
                auto front = m_primitives.begin();
                std::advance(front, index);
                m_currentPrimitive = *front;
            }
        }

        std::string modelState() const
        {
            return "|-LOG---| " + m_logMessage + "\n" + primitivesState();
        }

        primitive::IPrimitivePtr currentPrimitive() const
        {
            return  m_currentPrimitive;
        }

    private:
        primitive::IPrimitivePtr m_currentPrimitive;
        std::list<observer::IObserverPtr> m_observers;
        std::list<primitive::IPrimitivePtr> m_primitives;
        std::string m_logMessage;

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

    using ModelPtr = std::shared_ptr<Model>;

}
