#include "ThemeManager.h"
#include "Properties.h"
void ThemeManager::ApplyTheme(wxWindow* window, Theme theme) {
    switch (theme) {
    case Light:
        ApplyLightTheme(window);
        break;
    case Dark:
        ApplyDarkTheme(window);
        break;
    }
}
// NEED TO IMPLEMENT
void ThemeManager::ApplyLightTheme(wxWindow* window) {
    wxColour bgColor(255); 
    wxColour textColor(0, 0, 0); 

    window->SetBackgroundColour(WHITE);
    for (wxWindow* child : window->GetChildren()) {
        child->SetForegroundColour(textColor);
        child->SetBackgroundColour(bgColor);
    }
    window->Refresh();
}

void ThemeManager::ApplyDarkTheme(wxWindow* window) {
    wxColour bgColor(30, 30, 30); 
    wxColour textColor(255, 255, 255); 

    window->SetBackgroundColour(bgColor);
    for (wxWindow* child : window->GetChildren()) {
        child->SetForegroundColour(textColor);
        child->SetBackgroundColour(bgColor);
    }
    window->Refresh();
}
