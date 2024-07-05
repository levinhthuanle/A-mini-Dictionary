#include "MainFrame.h"
#include "Properties.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    SetSize(wxSize(WIDTH, HEIGHT));

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(WHITE);
}
