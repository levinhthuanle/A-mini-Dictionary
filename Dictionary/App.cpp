#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("A Mini Dictionary");
    mainFrame->Show();

    return true;
}
