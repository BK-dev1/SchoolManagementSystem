#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
class CourseFrame : public wxFrame 
{
public:
	CourseFrame(const wxString& title);
private:
	void CreateControls();
	void SetupSizers();
	void BindEventHandelers();

	void AddSavedFirstYearCourses();
	void AddSavedSecondYearCourses();
	void AddSavedThirdYearCourses();


	void onListKeyDown(wxKeyEvent& evt);
	void MoveSelection(int offset);


	void InitializeListView1();
	void InitializeListView2();
	void InitializeListView3();

	void AdjustColumnWidths1();
	void AdjustColumnWidths2();
	void AdjustColumnWidths3();
	void OnSize(wxSizeEvent& evt);


	wxScrolledWindow* scrolledWindow;

	wxStaticText* headlineText;

	wxStaticText* FirstYearLabel;
	wxButton* FirstYearEditButton;
	wxListView* FirstYearListView;

	wxStaticText* SecondYearLabel;
	wxButton* SecondYearEditButton;
	wxListView* SecondYearListView;

	wxStaticText* ThirdYearLabel;
	wxButton* ThirdYearEditButton;
	wxListView* ThirdYearListView;
};

