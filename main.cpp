#include <iostream>

#include "vectoreditor.h"

int main(void)
{
    std::cout << "Hello from Amazing Vector Editor!" << std::endl << std::endl;

    VectorEditor vectorEditor;

    vectorEditor.performCommand(Controller::Create);
    vectorEditor.performCommand(Controller::CreateEllipse);
    vectorEditor.performCommand(Controller::CreateRectangle);
    vectorEditor.performCommand(Controller::CreateRectangle);
    vectorEditor.performCommand(Controller::CreateTriangle);
    vectorEditor.performCommand(Controller::CreateRectangle);
    vectorEditor.performCommand(Controller::DeleteByIndex, 3);
    vectorEditor.performCommand(Controller::Create);
    vectorEditor.performCommand(Controller::CreateEllipse);
    vectorEditor.performCommand(Controller::Export);
    vectorEditor.performCommand(Controller::Import);

    return 0;
}
