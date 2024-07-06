#include "MainFrame.h"
#include "GameFrame.h"

// Define an ID for the button
const int ID_OpenGameButton = 1001;

wxBEGIN_EVENT_TABLE(MainFrame, BaseFrame)
EVT_BUTTON(ID_OpenGameButton, MainFrame::OnOpenGameFrame)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : BaseFrame(title, wxSize(WIDTH, HEIGHT)) {

    //wxPanel* panel = new wxPanel(this);
    //panel->SetBackgroundColour(WHITE);

    ////// Create and position the button
    ////wxButton* openGameButton = new wxButton(panel, ID_OpenGameButton, wxT("Open Game Frame"), wxPoint(350, 450));
    ////panel->Layout();

    ////// Call LoadHeaderFooter after creating the panel and button

    //LoadHeaderFooter(panel);
}

void MainFrame::OnOpenGameFrame(wxCommandEvent& event) {
    GameFrame* gameFrame = new GameFrame(wxT("Game Frame"));
    gameFrame->Show(true);
    Close(true);  // Close the MainFrame
}
