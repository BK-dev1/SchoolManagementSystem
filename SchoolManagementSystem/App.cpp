#include "App.h"
//#include "MainFrame.h"
#include <wx/wx.h>
#include "LoginFrame.h"

wxIMPLEMENT_APP(App);


bool App::OnInit()
{
    LoginFrame* loginFrame = new LoginFrame("Login");
    loginFrame->SetClientSize(600, 400);
    loginFrame->Center();
    loginFrame->Show();
    return true;
}
