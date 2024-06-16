#pragma once
#include <wx/wx.h>


class LoginFrame : public wxFrame
{
public:
	LoginFrame(const wxString& title);
private:
    void CreateControls();
    void BindEventHandlers();
    void SetupSizers();


    void onLoginClicked(wxCommandEvent& evt);
    void onExitClicked(wxCommandEvent& evt);


    wxPanel* panel;
    wxStaticText* headerText;
    wxStaticText* userLabel;
    wxStaticText* passLabel;
    wxTextCtrl* usernameCtrl;
    wxTextCtrl* passwordCtrl;
    wxButton* loginButton;
    wxButton* exitButton;
};

