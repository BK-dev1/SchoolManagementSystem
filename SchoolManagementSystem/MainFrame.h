#pragma once
#include <wx/wx.h>


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:

	void CreateControls();
	void BindEventHandlers();
	void SetupSizers();


	wxButton* CreateNavButton(wxPanel* parent, const wxString& label, const wxString& iconPath);


	void onAdminButtonClicked(wxCommandEvent& evt);
	void onStudentButtonClicked(wxCommandEvent& evt);

	void onTeachersButtonClicked(wxCommandEvent& evt);
	void onCoursesButtonClicked(wxCommandEvent& evt);
	void onExamsButtonClicked(wxCommandEvent& evt);
	void onSettingsButtonClicked(wxCommandEvent& evt);


	wxPanel* mainPanel;
	wxPanel* navPanel;
	wxPanel* contentPanel;
	wxPanel* bannerPanel;
	

	wxStaticText* welcome;
	wxButton* AdminButton;
	wxButton* StudentsButton;
	wxButton* TeachersButton;
	wxButton* CoursesButton;
	wxButton* ExamsButton;
	wxButton* AttendanceButton;
	wxButton* SettingsButton;

};