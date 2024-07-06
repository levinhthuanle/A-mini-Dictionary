#pragma once

#include "BaseFrame.h"

class MainFrame : public BaseFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnOpenGameFrame(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
