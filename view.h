#ifndef VIEW_H
#define VIEW_H

#include "model.h"

class View : public IObserver
{
public:
    View(Model *model) : m_model{model}
    {
        m_model->attach(this);
    }

    void update() override
    {
        m_model->info();
    }

private:
    Model *m_model;
};

#endif // VIEW_H
