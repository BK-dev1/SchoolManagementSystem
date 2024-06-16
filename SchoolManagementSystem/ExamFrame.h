#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/listctrl.h>

class ExamFrame : public wxFrame
{
public:
	ExamFrame(const wxString& title);
private:

	void CreateControls();

	void SetupSizers();

	void BindEventHandelers();

	void InitializeListView();
	void AdjustColumnWidths();
	void OnSize(wxSizeEvent& evt);


	wxPanel* MainPanel;

	wxStaticText* headlineText;

	wxStaticText* idLabel;
	wxStaticText* nameLabel;

	wxTextCtrl* idInput;
	wxTextCtrl* nameInput;

	wxSpinCtrl* DaySpinCtrl;
	wxSpinCtrl* MonthSpinCtrl;
	wxSpinCtrl* YearSpinCtrl;

	wxSpinCtrl* HourSpinCtrl;
	wxSpinCtrl* MinuteSpinCtrl;

	wxButton* addButton;
	wxButton* removeButton;
	wxButton* editButton;
	
	wxListView* listView;

};