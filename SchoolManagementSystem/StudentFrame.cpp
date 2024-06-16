#include "StudentFrame.h"

#include "Student.h"


StudentFrame::StudentFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title)
{
	CreateControls();
	SetupSizers();
	BindEventHandelers();
	AddSavedStudents();
}

void StudentFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	panel = new wxPanel(this,wxID_ANY);
	panel->SetFont(mainFont);
	panel->SetBackgroundColour(wxColor(105, 105, 105));
	headlineText = new wxStaticText(panel, wxID_ANY, wxT("Students"),
		wxDefaultPosition, wxDefaultSize);
	headlineText->SetFont(headlineFont);
	headlineText->SetForegroundColour(*wxWHITE);

	idLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"),
		wxDefaultPosition, wxDefaultSize);
	idLabel->SetForegroundColour(*wxBLACK);

	emailLabel = new wxStaticText(panel, wxID_ANY, wxT("Email:"),
		wxDefaultPosition, wxDefaultSize);
	emailLabel->SetForegroundColour(*wxBLACK);

	fullNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Full Name:"),
		wxDefaultPosition, wxDefaultSize);
	fullNameLabel->SetForegroundColour(*wxBLACK);

	phoneNumberLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"),
		wxDefaultPosition, wxDefaultSize);
	phoneNumberLabel->SetForegroundColour(*wxBLACK);

	ageLabel = new wxStaticText(panel, wxID_ANY, wxT("Age:"),
		wxDefaultPosition, wxDefaultSize);
	ageLabel->SetForegroundColour(*wxBLACK);

	yearLabel = new wxStaticText(panel, wxID_ANY, wxT("Year:"),
		wxDefaultPosition, wxDefaultSize);
	yearLabel->SetForegroundColour(*wxBLACK);

	idInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//idInput->SetBackgroundColour(wxColor(0, 0, 0));
	//idInput->SetForegroundColour(*wxWHITE);

	emailInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//emailInput->SetBackgroundColour(wxColor(0, 0, 0));
	//emailInput->SetForegroundColour(*wxWHITE);

	fullNameInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//fullNameInput->SetBackgroundColour(wxColor(0, 0, 0));
	//fullNameInput->SetForegroundColour(*wxWHITE);

	phoneNumberInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//phoneNumberInput->SetBackgroundColour(wxColor(0, 0, 0));
	//phoneNumberInput->SetForegroundColour(*wxWHITE);

	ageInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//ageInput->SetBackgroundColour(wxColor(0, 0, 0));
	//ageInput->SetForegroundColour(*wxWHITE);

	yearInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	//yearInput->SetBackgroundColour(wxColor(0, 0, 0));
	//yearInput->SetForegroundColour(*wxWHITE);

	InitializeListView();
	addButton = new wxButton(panel, wxID_ANY, wxT("Add"));
	addButton->SetBackgroundColour(*wxBLACK);
	addButton->SetForegroundColour(*wxWHITE);

	removeButton = new wxButton(panel, wxID_ANY, wxT("Remove"));
	removeButton->SetBackgroundColour(*wxBLACK);
	removeButton->SetForegroundColour(*wxWHITE);

	editButton = new wxButton(panel, wxID_ANY, wxT("Edit"));
	editButton->SetBackgroundColour(*wxBLACK);
	editButton->SetForegroundColour(*wxWHITE);



}

void StudentFrame::SetupSizers()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* outerSizer = new wxGridSizer(1);
	outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

	mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
	mainSizer->AddSpacer(25);

	wxBoxSizer* labelSizer = new wxBoxSizer(wxHORIZONTAL);
	labelSizer->Add(idLabel, wxSizerFlags().Proportion(1));
	labelSizer->AddSpacer(5);
	labelSizer->Add(emailLabel, wxSizerFlags().Proportion(2));
	labelSizer->AddSpacer(5);
	labelSizer->Add(fullNameLabel, wxSizerFlags().Proportion(2));
	labelSizer->AddSpacer(5);
	labelSizer->Add(phoneNumberLabel, wxSizerFlags().Proportion(2));
	labelSizer->AddSpacer(5);
	labelSizer->Add(ageLabel, wxSizerFlags().Proportion(1));
	labelSizer->AddSpacer(5);
	labelSizer->Add(yearLabel, wxSizerFlags().Proportion(1));


	wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);
	inputSizer->Add(idInput, wxSizerFlags().Proportion(1));
	inputSizer->AddSpacer(5);
	inputSizer->Add(emailInput, wxSizerFlags().Proportion(2));
	inputSizer->AddSpacer(5);
	inputSizer->Add(fullNameInput, wxSizerFlags().Proportion(2));
	inputSizer->AddSpacer(5);
	inputSizer->Add(phoneNumberInput, wxSizerFlags().Proportion(2));
	inputSizer->AddSpacer(5);
	inputSizer->Add(ageInput, wxSizerFlags().Proportion(1));
	inputSizer->AddSpacer(5);
	inputSizer->Add(yearInput, wxSizerFlags().Proportion(1));


	mainSizer->Add(labelSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(5);
	mainSizer->Add(inputSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(10);
	
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	buttonSizer->Add(addButton, wxSizerFlags().Proportion(1));
	buttonSizer->AddSpacer(5);
	buttonSizer->Add(removeButton, wxSizerFlags().Proportion(1));
	buttonSizer->AddSpacer(5);
	buttonSizer->Add(editButton, wxSizerFlags().Proportion(1));

	
	mainSizer->Add(buttonSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(listView, wxSizerFlags().Expand());

	panel->SetSizer(outerSizer);
	outerSizer->SetSizeHints(this);
}

void StudentFrame::BindEventHandelers()
{
	Bind(wxEVT_SIZE, &StudentFrame::OnSize, this);
	addButton->Bind(wxEVT_BUTTON, &StudentFrame::OnAddButtonClicked, this);
	idInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	emailInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	fullNameInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	phoneNumberInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	ageInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	yearInput->Bind(wxEVT_TEXT_ENTER, &StudentFrame::onInputEnter, this);
	listView->Bind(wxEVT_KEY_DOWN, &StudentFrame::onListKeyDown, this);
	removeButton->Bind(wxEVT_BUTTON,&StudentFrame::OnRemoveButtonClicked,this);

	this->Bind(wxEVT_CLOSE_WINDOW, &StudentFrame::OnWindowClose, this);
}

void StudentFrame::AddSavedStudents()
{
	std::vector<Student> students = LoadStudentFromFile("students.txt");
	for (const Student& student : students)
	{

		std::string stdId = std::to_string(student.id);
		wxString id(stdId);
		long itemIndex = listView->InsertItem(0,id);
		listView->SetItem(itemIndex, 1, student.Email);
		listView->SetItem(itemIndex, 2, student.FullName);
		listView->SetItem(itemIndex, 3, student.PhoneNumber);
		wxString age = wxString::FromDouble(student.age);
		listView->SetItem(itemIndex, 4, age);
		wxString year = wxString::FromDouble(student.year);
		listView->SetItem(itemIndex, 5, year);
	}
}

void StudentFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	addStudentFromImput();
}

void StudentFrame::addStudentFromImput()
{
	wxString id = idInput->GetValue();
	wxString email = emailInput->GetValue();
	wxString fullName = fullNameInput->GetValue();
	wxString phoneNumber = phoneNumberInput->GetValue();
	wxString age = ageInput->GetValue();
	wxString year = yearInput->GetValue();

	if (!IsEmpty())
	{
		long itemIndex = listView->InsertItem(0, id);
		listView->SetItem(itemIndex, 1, email);
		listView->SetItem(itemIndex, 2, fullName);
		listView->SetItem(itemIndex, 3, phoneNumber);
		listView->SetItem(itemIndex, 4, age);
		listView->SetItem(itemIndex, 5, year);
		idInput->Clear();
		emailInput->Clear();
		fullNameInput->Clear();
		phoneNumberInput->Clear();
		ageInput->Clear();
		yearInput->Clear();
	}
	idInput->SetFocus();
}

bool StudentFrame::IsEmpty()
{
	return (idInput->IsEmpty() && emailInput->IsEmpty() &&
		phoneNumberInput->IsEmpty() && ageInput->IsEmpty() &&
		yearInput->IsEmpty());
}

void StudentFrame::onInputEnter(wxCommandEvent& evt)
{
	addStudentFromImput();
}

void StudentFrame::onListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_DELETE:
		deleteSelectedStudent();
		break;
	case WXK_UP:
		MoveSelection(-1);
		break;
	case WXK_DOWN:
		MoveSelection(1);
		break;
	}
}

void StudentFrame::deleteSelectedStudent()
{
	int selectedIndex = listView->GetFirstSelected();
	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}
	wxMessageDialog dialog(this,"Are you sure you want to delete this student?",
		"Remove",wxYES_NO | wxCANCEL );
	
	int result = dialog.ShowModal();

	if (result == wxID_YES)
	{

		listView->DeleteItem(selectedIndex);
	}

}

void StudentFrame::MoveSelection(int offset)
{
	int selectedIndex = listView->GetFirstSelected();
	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}
	int newIndex = selectedIndex + offset;

	if (newIndex >= 0 && newIndex < listView->GetItemCount())
	{
		listView->Select(newIndex, true);
		listView->Select(selectedIndex, false);
	}

}

void StudentFrame::OnWindowClose(wxCloseEvent& evt)
{
	std::vector<Student> students;
	for (int i = 0; i < listView->GetItemCount(); i++)
	{
		Student student;
		listView->GetItemText(i,0).ToLong(&student.id);
		student.Email = listView->GetItemText(i, 1);
		student.FullName = listView->GetItemText(i, 2);
		student.PhoneNumber = listView->GetItemText(i, 3);
		listView->GetItemText(i, 4).ToLong(&student.age);
		listView->GetItemText(i, 5).ToLong(&student.year);
		students.push_back(student);
	}
	AddStudentToFile(students,"students.txt");
	evt.Skip();
}

void StudentFrame::OnRemoveButtonClicked(wxCommandEvent& evt)
{
	deleteSelectedStudent();
}

void StudentFrame::InitializeListView()
{
	listView = new wxListView(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	listView->SetBackgroundColour(wxColor(105, 105, 105));
	listView->SetForegroundColour(*wxWHITE);

	listView->InsertColumn(0, "Id");
	listView->InsertColumn(1, "Email");
	listView->InsertColumn(2, "Full Name");
	listView->InsertColumn(3, "Phone Number");
	listView->InsertColumn(4, "Age");
	listView->InsertColumn(5, "Year");

	AdjustColumnWidths();
}

void StudentFrame::AdjustColumnWidths()
{
	int totalWidth = listView->GetClientSize().GetWidth();
	int columnWidth = totalWidth / 6;

	// Set each column width dynamically
	for (int i = 0; i < 6; ++i)
	{
		listView->SetColumnWidth(i, columnWidth);
	}
}

void StudentFrame::OnSize(wxSizeEvent& evt)
{
	AdjustColumnWidths();

	evt.Skip();
}
