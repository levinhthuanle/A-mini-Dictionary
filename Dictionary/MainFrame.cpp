#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    SetSize(wxSize(WIDTH, HEIGHT));

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(WHITE);

    wxInitAllImageHandlers();

    // Load and position header image
    wxImage headerImg(HEADER_IMG, wxBITMAP_TYPE_PNG);
    if (headerImg.IsOk()) {
        wxBitmap headerBitmap(headerImg);
        wxStaticBitmap* headerCtrl = new wxStaticBitmap(panel, wxID_ANY, headerBitmap);

        headerCtrl->SetPosition(wxPoint(0, 0));
    }
    else {
        wxLogError("Failed to load header.");
    }

    // Load and position footer image
    wxImage footerImg(FOOTER_IMG, wxBITMAP_TYPE_PNG);
    if (footerImg.IsOk()) {
        wxBitmap footerBitmap(footerImg);
        wxStaticBitmap* footerCtrl = new wxStaticBitmap(panel, wxID_ANY, footerBitmap);

        footerCtrl->SetPosition(wxPoint(0, 885));
    }
    else {
        wxLogError("Failed to load footer.");
    }

    panel->Layout();
}
