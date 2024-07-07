#include "BaseFrame.h"

enum {
    ID_Home = 1001,
    ID_Dictionaries,
    ID_Games,
    ID_History,
    ID_Favorite,
    ID_More
};

wxBEGIN_EVENT_TABLE(BaseFrame, wxFrame)
EVT_TOOL(ID_Home, BaseFrame::OnHome)
EVT_TOOL(ID_Dictionaries, BaseFrame::OnDictionaries)
EVT_TOOL(ID_Games, BaseFrame::OnGames)
EVT_TOOL(ID_History, BaseFrame::OnHistory)
EVT_TOOL(ID_Favorite, BaseFrame::OnFavorite)
EVT_TOOL(ID_More, BaseFrame::OnMore)
wxEND_EVENT_TABLE()

BaseFrame::BaseFrame(const wxString& title, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    SetSize(wxSize(WIDTH, HEIGHT));

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(WHITE);

    wxInitAllImageHandlers();

    LoadHeaderFooter(panel);

    wxToolBar* toolbar = CreateToolbar();
    // Position toolbar at (0, 400)
    toolbar->SetPosition(wxPoint(0, 400));
    SetToolBar(toolbar);
    toolbar->Realize();

    panel->Layout();
}

void BaseFrame::LoadHeaderFooter(wxPanel* panel) {
    LoadImage(HEADER_IMG, wxPoint(0, 0), panel);
    LoadImage(NAVIGATION_IMG, wxPoint(0, 150), panel);
    LoadImage(FOOTER_IMG, wxPoint(0, 885), panel);  // Adjust Y-coordinate as needed
}

void BaseFrame::LoadImage(const wxString& imagePath, const wxPoint& position, wxPanel* panel) {
    wxImage image(imagePath, wxBITMAP_TYPE_PNG);
    if (image.IsOk()) {
        wxBitmap bitmap(image);
        wxStaticBitmap* imageCtrl = new wxStaticBitmap(panel, wxID_ANY, bitmap);
        imageCtrl->SetPosition(position);
    }
    else {
        wxLogError("Failed to load image: %s", imagePath);
    }
}

wxToolBar* BaseFrame::CreateToolbar() {
    wxToolBar* toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL | wxNO_BORDER | wxTB_FLAT);

    // Set bitmap size to avoid scaling (match your image sizes)
    

    // Add buttons to the toolbar
    toolbar->AddTool(ID_Home, "Home", wxBitmap(HOMEICON_IMG, wxBITMAP_TYPE_PNG), "Home");
    toolbar->AddTool(ID_Dictionaries, "Dictionaries", wxBitmap(SEARCHICON_IMG, wxBITMAP_TYPE_PNG), "Dictionaries");
    toolbar->AddTool(ID_Games, "Games", wxBitmap(GAMEICON_IMG, wxBITMAP_TYPE_PNG), "Games");
    toolbar->AddTool(ID_History, "History", wxBitmap(HISTORYICON_IMG, wxBITMAP_TYPE_PNG), "History");
    toolbar->AddTool(ID_Favorite, "Favorite", wxBitmap(FAVORITEICON_IMG, wxBITMAP_TYPE_PNG), "Favorite");
    toolbar->AddTool(ID_More, "More", wxBitmap(MOREICON_IMG, wxBITMAP_TYPE_PNG), "More");

    return toolbar;
}

void BaseFrame::OnHome(wxCommandEvent& event) {
    wxLogMessage("Home button clicked");
}

void BaseFrame::OnDictionaries(wxCommandEvent& event) {
    wxLogMessage("Dictionaries button clicked");
}

void BaseFrame::OnGames(wxCommandEvent& event) {
    wxLogMessage("Games button clicked");
}

void BaseFrame::OnHistory(wxCommandEvent& event) {
    wxLogMessage("History button clicked");
}

void BaseFrame::OnFavorite(wxCommandEvent& event) {
    wxLogMessage("Favorite button clicked");
}

void BaseFrame::OnMore(wxCommandEvent& event) {
    wxLogMessage("More button clicked");
}
