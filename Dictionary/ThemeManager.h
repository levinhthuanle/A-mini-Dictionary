#pragma once
#include <wx/wx.h>
// USE TO CHANGE BETWEEN TWO THEMES
enum Theme {
    Light,
    Dark
};

class ThemeManager {
public:
    static void ApplyTheme(wxWindow* window, Theme theme);

private:
    static void ApplyLightTheme(wxWindow* window);
    static void ApplyDarkTheme(wxWindow* window);
};


