#include "MainFrame.h"
#include "StudentFrame.h"
#include "TeacherFrame.h" 
#include "CourseFrame.h"
#include "ExamFrame.h"

// Constructor
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1024, 768))
{
    CreateControls();
    SetupSizers();
    BindEventHandlers();
}

// Create all the controls
void MainFrame::CreateControls()
{
    wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 24)));

    // Main panel
    mainPanel = new wxPanel(this, wxID_ANY);
    mainPanel->SetFont(mainFont);
    mainPanel->SetBackgroundColour(wxColor(0,0,0));

    // Navigation panel and content panel
    navPanel = new wxPanel(mainPanel, wxID_ANY);

    navPanel->SetBackgroundColour(wxColor(105, 105, 105));

    contentPanel = new wxPanel(mainPanel, wxID_ANY);
    contentPanel->SetBackgroundColour(wxColor(105, 105, 105));

    bannerPanel = new wxPanel(contentPanel, wxID_ANY);
    bannerPanel->SetBackgroundColour(wxColor(0,0,0));

    // Welcome text
    welcome = new wxStaticText(bannerPanel, wxID_ANY, "Welcome To ENSIA School Management System");
    welcome->SetFont(headlineFont);
    welcome->SetForegroundColour(*wxWHITE);

    // Navigation buttons with icons
    AdminButton = new wxButton(navPanel,wxID_ANY,"Admin");
    AdminButton->SetBackgroundColour(wxColor(128, 128, 128));

    StudentsButton = new wxButton(navPanel, wxID_ANY, "Students");
    StudentsButton->SetBackgroundColour(wxColor(128, 128, 128));

    TeachersButton = new wxButton(navPanel, wxID_ANY, "Teachers");
    TeachersButton->SetBackgroundColour(wxColor(128, 128, 128));

    CoursesButton = new wxButton(navPanel, wxID_ANY, "Courses");
    CoursesButton->SetBackgroundColour(wxColor(128, 128, 128));

    ExamsButton = new wxButton(navPanel, wxID_ANY, "Exams");
    ExamsButton->SetBackgroundColour(wxColor(128, 128, 128));

    AttendanceButton = new wxButton(navPanel, wxID_ANY, "Attendance");
    AttendanceButton->SetBackgroundColour(wxColor(128, 128, 128));


    SettingsButton = new wxButton(navPanel, wxID_ANY, "Settings");
    SettingsButton->SetBackgroundColour(wxColor(128, 128, 128));

}



// Bind event handlers to buttons
void MainFrame::BindEventHandlers()
{
    AdminButton->Bind(wxEVT_BUTTON, &MainFrame::onAdminButtonClicked, this);
    StudentsButton->Bind(wxEVT_BUTTON, &MainFrame::onStudentButtonClicked, this);
    TeachersButton->Bind(wxEVT_BUTTON, &MainFrame::onTeachersButtonClicked, this);
    CoursesButton->Bind(wxEVT_BUTTON, &MainFrame::onCoursesButtonClicked, this);
    ExamsButton->Bind(wxEVT_BUTTON, &MainFrame::onExamsButtonClicked, this);
    SettingsButton->Bind(wxEVT_BUTTON, &MainFrame::onSettingsButtonClicked, this);
}

// Set up the sizers for layout
void MainFrame::SetupSizers()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

    // Navigation sizer
    wxBoxSizer* navSizer = new wxBoxSizer(wxVERTICAL);

    navSizer->Add(AdminButton, 0, wxALL | wxEXPAND, 5);
    navSizer->Add(StudentsButton, 0, wxALL | wxEXPAND, 5);
    navSizer->Add(TeachersButton, 0, wxALL | wxEXPAND, 5);
    navSizer->Add(CoursesButton, 0, wxALL | wxEXPAND, 5);
    navSizer->Add(ExamsButton, 0, wxALL | wxEXPAND, 5);
    navSizer->Add(AttendanceButton, 0, wxALL | wxEXPAND, 5);
    navSizer->AddStretchSpacer(1); // Add a spacer to push the Settings button to the bottom
    navSizer->Add(SettingsButton, 0, wxALL | wxEXPAND, 5);
    navPanel->SetSizer(navSizer);

    // Content sizer
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bannerSizer = new wxBoxSizer(wxHORIZONTAL);
    bannerSizer->AddStretchSpacer(1); // Add a spacer to center-align the welcome text
    bannerSizer->Add(welcome, 0, wxALL | wxALIGN_CENTER_VERTICAL, 10);
    bannerSizer->AddStretchSpacer(1); // Add a spacer to center-align the welcome text
    bannerPanel->SetSizer(bannerSizer);
    contentSizer->Add(bannerPanel, 0, wxEXPAND | wxALL, 10);

    contentPanel->SetSizer(contentSizer);

    // Add panels to main sizer
    mainSizer->Add(navPanel, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(contentPanel, 1, wxEXPAND | wxALL, 5);

    // Set sizer for the main panel
    mainPanel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);
}

// Event handlers for buttons
void MainFrame::onAdminButtonClicked(wxCommandEvent& evt)
{
    // Placeholder for Admin button event
}

void MainFrame::onStudentButtonClicked(wxCommandEvent& evt)
{
    StudentFrame* studentFrame = new StudentFrame("Students");
    studentFrame->Show();
}

void MainFrame::onTeachersButtonClicked(wxCommandEvent& evt)
{
    TeacherFrame* teacherFrame = new TeacherFrame("Teachers");
    teacherFrame->Show();
}

void MainFrame::onCoursesButtonClicked(wxCommandEvent& evt)
{
    CourseFrame* courseFrame = new CourseFrame("Courses");
    courseFrame->Show();
}

void MainFrame::onExamsButtonClicked(wxCommandEvent& evt)
{
    ExamFrame* examFrame = new ExamFrame("Exam");
    examFrame->Show();
}

void MainFrame::onSettingsButtonClicked(wxCommandEvent& evt)
{
    // Placeholder for Settings button event
}
