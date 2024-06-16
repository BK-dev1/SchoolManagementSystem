#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
class TeacherFrame : public wxFrame
{
public:
	TeacherFrame(const wxString& title);
private:

	void CreateControls();
	void SetupSizers();
	void BindEventHandelers();
	void AddSavedTeachers();


	void OnAddButtonClicked(wxCommandEvent& evt);
	void addTeacherFromImput();
	bool IsEmpty();
	void onInputEnter(wxCommandEvent& evt);
	void onListKeyDown(wxKeyEvent& evt);
	void deleteSelectedTeacher();
	void MoveSelection(int offset);

	void OnWindowClose(wxCloseEvent& evt);

	void OnRemoveButtonClicked(wxCommandEvent& evt);

	void InitializeListView();
	void AdjustColumnWidths();
	void OnSize(wxSizeEvent& evt);


	wxPanel* panel;

	wxStaticText* headlineText;

	wxStaticText* idLabel;
	wxStaticText* emailLabel;
	wxStaticText* fullNameLabel;
	wxStaticText* phoneNumberLabel;
	wxStaticText* ageLabel;

	wxTextCtrl* idInput;
	wxTextCtrl* emailInput;
	wxTextCtrl* fullNameInput;
	wxTextCtrl* phoneNumberInput;
	wxTextCtrl* ageInput;

	wxButton* addButton;
	wxButton* removeButton;
	wxButton* editButton;

	wxListView* listView;
};

