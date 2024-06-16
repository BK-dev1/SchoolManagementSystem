#include "LoginFrame.h"
#include "MainFrame.h"

LoginFrame::LoginFrame(const wxString& title) 
    :wxFrame(nullptr, wxID_ANY, title,wxDefaultPosition,wxSize(1000,600),
        wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
    CreateControls();
    SetupSizers();
    BindEventHandlers();
}

void LoginFrame::CreateControls()
{

    wxFont headlineFont(wxFontInfo(wxSize(0,36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0,24)));

    panel = new wxPanel(this, wxID_ANY);
    panel->SetFont(mainFont);
    panel->SetBackgroundColour(wxColor(105, 105, 105));
    
    headerText = new wxStaticText(panel, wxID_ANY, wxT("LOGIN TO ENSIA SCHOOL MANAGEMENT SYSTEM"));
    headerText->SetFont(headlineFont);
    headerText->SetForegroundColour(*wxWHITE);

    userLabel = new wxStaticText(panel, wxID_ANY, wxT("Username:"));
    userLabel->SetForegroundColour(*wxWHITE);
    usernameCtrl = new wxTextCtrl(panel, wxID_ANY);
    usernameCtrl->SetBackgroundColour(wxColor(0, 0, 0));
    usernameCtrl->SetForegroundColour(*wxWHITE);

    passLabel = new wxStaticText(panel, wxID_ANY, wxT("Password:"));
    passLabel->SetForegroundColour(*wxWHITE);


    passwordCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    passwordCtrl->SetBackgroundColour(wxColor(0, 0, 0));
    passwordCtrl->SetForegroundColour(*wxWHITE);

    loginButton = new wxButton(panel, wxID_ANY, wxT("Login"));
    loginButton->SetBackgroundColour(wxColor(0, 0, 0));
    loginButton->SetForegroundColour(*wxWHITE);
    exitButton = new wxButton(panel, wxID_ANY, wxT("Exit"));
    exitButton->SetBackgroundColour(wxColor(0, 0, 0));
    exitButton->SetForegroundColour(*wxWHITE);

}

void LoginFrame::BindEventHandlers()
{
    loginButton->Bind(wxEVT_BUTTON, &LoginFrame::onLoginClicked, this);
    exitButton->Bind(wxEVT_BUTTON, &LoginFrame::onExitClicked, this);
}

void LoginFrame::SetupSizers()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(headerText, wxSizerFlags().CenterHorizontal());
    mainSizer->AddSpacer(25);

    wxBoxSizer* userSizer = new wxBoxSizer(wxHORIZONTAL);
    userSizer->Add(userLabel, wxSizerFlags().CenterVertical());
    userSizer->AddSpacer(2);
    userSizer->Add(usernameCtrl, wxSizerFlags().Proportion(3));

    wxBoxSizer* passSizer = new wxBoxSizer(wxHORIZONTAL);
    passSizer->Add(passLabel, wxSizerFlags().CenterVertical());
    passSizer->AddSpacer(7);
    passSizer->Add(passwordCtrl, wxSizerFlags().Proportion(3));

    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);
    controlSizer->Add(loginButton);
    controlSizer->AddSpacer(20);
    controlSizer->Add(exitButton);


    wxGridSizer* outerSizer = new wxGridSizer(1);
    outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

    mainSizer->Add(userSizer, wxSizerFlags().Expand());
    mainSizer->AddSpacer(5);
    mainSizer->Add(passSizer, wxSizerFlags().Expand());
    mainSizer->AddSpacer(25);
    mainSizer->Add(controlSizer, wxSizerFlags().CenterHorizontal());




    panel->SetSizer(outerSizer);
    outerSizer->SetSizeHints(this);

}



void LoginFrame::onLoginClicked(wxCommandEvent& evt)
{
    wxString username = usernameCtrl->GetValue();
    wxString password = passwordCtrl->GetValue();
    if (username == "admin" && password == "admin")
    {
        this->Close(true);

        MainFrame* mainFrame = new MainFrame("MainFrame");
        mainFrame->SetClientSize(600, 400);
        mainFrame->Center();
        mainFrame->Show();
    }
}

void LoginFrame::onExitClicked(wxCommandEvent& evt)
{
    this->Close(true);
}
