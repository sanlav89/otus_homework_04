#include "view.h"

int main(void)
{
    model::ModelPtr model(new model::Model);
    controller::ControllerPtr controller(new controller::Controller(model));
    view::ViewPtr editor(new view::View(model, controller));

    editor->newAction();
    editor->addEllipseAction();
    editor->addRectangleAction();
    editor->addRectangleAction();
    editor->addTriangleAction();
    editor->addRectangleAction();
    editor->removeAction(3);
    editor->newAction();
    editor->addEllipseAction();
    editor->exportAction("my_file_out.txt");
    editor->importAction("my_file_in.txt");

    return 0;
}
