#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"

int main(void)
{
    std::cout << "Hello from Amazing Vector Editor!" << std::endl << std::endl;

    Model editor;
    View view(&editor);
    Controller controller(&editor);

    controller.performCommand(Controller::Create);
    controller.performCommand(Controller::CreateEllipse);
    controller.performCommand(Controller::CreateRectangle);
    controller.performCommand(Controller::CreateRectangle);
    controller.performCommand(Controller::CreateTriangle);
    controller.performCommand(Controller::CreateRectangle);
    controller.performCommand(Controller::DeleteByIndex, 3);
    controller.performCommand(Controller::Create);
    controller.performCommand(Controller::CreateEllipse);
    controller.performCommand(Controller::Export);
    controller.performCommand(Controller::Import);

    return 0;
}
