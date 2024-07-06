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

private:
    void LoadImage(const wxString& imagePath, const wxPoint& position, wxPanel* panel);
};
