#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
class StudentFrame : public wxFrame
{
public:
	StudentFrame(const wxString& title);
private:

	void CreateControls();
	void SetupSizers();
	void BindEventHandelers();
	void AddSavedStudents();


	void OnAddButtonClicked(wxCommandEvent& evt);
	void addStudentFromImput();
	bool IsEmpty();
	void onInputEnter(wxCommandEvent& evt);
	void onListKeyDown(wxKeyEvent& evt);
	void deleteSelectedStudent();
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
	wxStaticText* yearLabel;

	wxTextCtrl* idInput;
	wxTextCtrl* emailInput;
	wxTextCtrl* fullNameInput;
	wxTextCtrl* phoneNumberInput;
	wxTextCtrl* ageInput;
	wxTextCtrl* yearInput;

	wxButton* addButton;
	wxButton* removeButton;
	wxButton* editButton;

	wxListView* listView;
};

