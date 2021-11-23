#include "model.h"
#include "view.h"
#include "controller.h"

int main(void)
{
    model::ModelPtr model(new model::Model);
    controller::ControllerPtr controller(new controller::Controller(model));
    view::ViewPtr editor(new view::View(model, controller));

    editor->execute(view::Action::Create);
    editor->execute(view::Action::CreateEllipse);
    editor->execute(view::Action::CreateRectangle);
    editor->execute(view::Action::CreateRectangle);
    editor->execute(view::Action::CreateTriangle);
    editor->execute(view::Action::CreateRectangle);
    editor->execute(view::Action::SelectPrimitive, 3);
    editor->execute(view::Action::RemovePrimitive);
    editor->execute(view::Action::Create);
    editor->execute(view::Action::CreateEllipse);
    editor->execute(view::Action::Export, "my_file_out.txt");
    editor->execute(view::Action::Import, "my_file_in.txt");

    return 0;
}
