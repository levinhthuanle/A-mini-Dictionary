#include "BaseFrame.h"

BaseFrame::BaseFrame(const wxString& title, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    SetSize(wxSize(WIDTH, HEIGHT));

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(WHITE);

    wxInitAllImageHandlers();

    LoadHeaderFooter(panel);
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
