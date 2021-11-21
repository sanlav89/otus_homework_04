#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"

int main(void)
{
    std::cout << "Hello from Amazing Vector Editor!" << std::endl << std::endl;

    Model *model = new Model;
    Controller *controller = new Controller(model);
    View *editor = new View(model, controller);

    editor->execute(View::Action::Create);
    editor->execute(View::Action::CreateEllipse);
    editor->execute(View::Action::CreateRectangle);
    editor->execute(View::Action::CreateRectangle);
    editor->execute(View::Action::CreateTriangle);
    editor->execute(View::Action::CreateRectangle);
    editor->execute(View::Action::SelectPrimitive, 3);
    editor->execute(View::Action::RemovePrimitive);
    editor->execute(View::Action::Create);
    editor->execute(View::Action::CreateEllipse);
    editor->execute(View::Action::Export, "my_file_out.txt");
    editor->execute(View::Action::Import, "my_file_in.txt");

    return 0;
}
