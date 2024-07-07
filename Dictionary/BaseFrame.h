#pragma once

#include <wx/wx.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/image.h>
#include "Properties.h"

class BaseFrame : public wxFrame {
public:
    BaseFrame(const wxString& title, const wxSize& size);
    void LoadHeaderFooter(wxPanel* panel);

protected:
    void LoadImage(const wxString& imagePath, const wxPoint& position, wxPanel* panel);
    wxToolBar* CreateToolbar();

    void OnHome(wxCommandEvent& event);

    void OnDictionaries(wxCommandEvent& event);

    void OnGames(wxCommandEvent& event);

    void OnHistory(wxCommandEvent& event);

    void OnFavorite(wxCommandEvent& event);

    void OnMore(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};
