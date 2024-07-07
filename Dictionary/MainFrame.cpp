#include "MainFrame.h"
#include "GameFrame.h"

// Define an ID for the button
const int ID_OpenGameButton = 1001;

wxBEGIN_EVENT_TABLE(MainFrame, BaseFrame)
EVT_BUTTON(ID_OpenGameButton, MainFrame::OnOpenGameFrame)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : BaseFrame(title, wxSize(WIDTH, HEIGHT)) {

    // Get the panel created in BaseFrame
    wxPanel* panel = dynamic_cast<wxPanel*>(GetChildren()[0]);
    if (!panel) {
        wxLogError("Failed to retrieve the panel from BaseFrame.");
        return;
    }

    // Add the button to the panel
    wxButton* m_button = new wxButton(panel, ID_OpenGameButton, "Click Me", wxPoint(20, 450));

    // Layout the panel
    panel->Layout();
}

void MainFrame::OnOpenGameFrame(wxCommandEvent& event) {
    GameFrame* gameFrame = new GameFrame(wxT("Game Frame"));
    gameFrame->Show(true);
    Close(true);  // Close the MainFrame
}
