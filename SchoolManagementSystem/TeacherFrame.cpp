#include "TeacherFrame.h"

#include "Teacher.h"

TeacherFrame::TeacherFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
	SetupSizers();
	BindEventHandelers();
	AddSavedTeachers();
}

void TeacherFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	panel = new wxPanel(this, wxID_ANY);
	panel->SetFont(mainFont);
	panel->SetBackgroundColour(wxColor(105, 105, 105));

	headlineText = new wxStaticText(panel, wxID_ANY, wxT("Teachers"),
		wxDefaultPosition, wxDefaultSize);
	headlineText->SetFont(headlineFont);
	headlineText->SetForegroundColour(*wxWHITE);

	idLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"),
		wxDefaultPosition, wxDefaultSize);
	emailLabel = new wxStaticText(panel, wxID_ANY, wxT("Email:"),
		wxDefaultPosition, wxDefaultSize);
	fullNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Full Name:"),
		wxDefaultPosition, wxDefaultSize);
	phoneNumberLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"),
		wxDefaultPosition, wxDefaultSize);
	ageLabel = new wxStaticText(panel, wxID_ANY, wxT("Age:"),
		wxDefaultPosition, wxDefaultSize);

	idInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	emailInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	fullNameInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	phoneNumberInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);
	ageInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
		wxDefaultSize, wxTE_PROCESS_ENTER);

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

void TeacherFrame::SetupSizers()
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

void TeacherFrame::BindEventHandelers()
{
	Bind(wxEVT_SIZE, &TeacherFrame::OnSize, this);
	addButton->Bind(wxEVT_BUTTON, &TeacherFrame::OnAddButtonClicked, this);
	idInput->Bind(wxEVT_TEXT_ENTER, &TeacherFrame::onInputEnter, this);
	emailInput->Bind(wxEVT_TEXT_ENTER, &TeacherFrame::onInputEnter, this);
	fullNameInput->Bind(wxEVT_TEXT_ENTER, &TeacherFrame::onInputEnter, this);
	phoneNumberInput->Bind(wxEVT_TEXT_ENTER, &TeacherFrame::onInputEnter, this);
	ageInput->Bind(wxEVT_TEXT_ENTER, &TeacherFrame::onInputEnter, this);
	listView->Bind(wxEVT_KEY_DOWN, &TeacherFrame::onListKeyDown, this);
	removeButton->Bind(wxEVT_BUTTON, &TeacherFrame::OnRemoveButtonClicked, this);

	this->Bind(wxEVT_CLOSE_WINDOW, &TeacherFrame::OnWindowClose, this);
}

void TeacherFrame::AddSavedTeachers()
{
	std::vector<Teacher> teachers = LoadTeacherFromFile("teachers.txt");
	for (const Teacher& teacher : teachers)
	{

		std::string stdId = std::to_string(teacher.id);
		wxString id(stdId);
		long itemIndex = listView->InsertItem(0, id);
		listView->SetItem(itemIndex, 1, teacher.Email);
		listView->SetItem(itemIndex, 2, teacher.FullName);
		listView->SetItem(itemIndex, 3, teacher.PhoneNumber);
		wxString age = wxString::FromDouble(teacher.age);
		listView->SetItem(itemIndex, 4, age);
	}
}

void TeacherFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	addTeacherFromImput();
}

void TeacherFrame::addTeacherFromImput()
{
	wxString id = idInput->GetValue();
	wxString email = emailInput->GetValue();
	wxString fullName = fullNameInput->GetValue();
	wxString phoneNumber = phoneNumberInput->GetValue();
	wxString age = ageInput->GetValue();

	if (!IsEmpty())
	{
		long itemIndex = listView->InsertItem(0, id);
		listView->SetItem(itemIndex, 1, email);
		listView->SetItem(itemIndex, 2, fullName);
		listView->SetItem(itemIndex, 3, phoneNumber);
		listView->SetItem(itemIndex, 4, age);
		idInput->Clear();
		emailInput->Clear();
		fullNameInput->Clear();
		phoneNumberInput->Clear();
		ageInput->Clear();
	}
	idInput->SetFocus();
}

bool TeacherFrame::IsEmpty()
{
	return (idInput->IsEmpty() && emailInput->IsEmpty() &&
		phoneNumberInput->IsEmpty() && ageInput->IsEmpty());
}

void TeacherFrame::onInputEnter(wxCommandEvent& evt)
{
	addTeacherFromImput();
}

void TeacherFrame::onListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_DELETE:
		deleteSelectedTeacher();
		break;
	case WXK_UP:
		MoveSelection(-1);
		break;
	case WXK_DOWN:
		MoveSelection(1);
		break;
	}
}

void TeacherFrame::deleteSelectedTeacher()
{
	int selectedIndex = listView->GetFirstSelected();
	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}
	wxMessageDialog dialog(this, "Are you sure you want to delete this student?",
		"Remove", wxYES_NO | wxCANCEL);

	int result = dialog.ShowModal();

	if (result == wxID_YES)
	{

		listView->DeleteItem(selectedIndex);
	}

}

void TeacherFrame::MoveSelection(int offset)
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

void TeacherFrame::OnWindowClose(wxCloseEvent& evt)
{
	std::vector<Teacher> teachers;
	for (int i = 0; i < listView->GetItemCount(); i++)
	{
		Teacher teacher;
		listView->GetItemText(i, 0).ToLong(&teacher.id);
		teacher.Email = listView->GetItemText(i, 1);
		teacher.FullName = listView->GetItemText(i, 2);
		teacher.PhoneNumber = listView->GetItemText(i, 3);
		listView->GetItemText(i, 4).ToLong(&teacher.age);
		teachers.push_back(teacher);
	}
	AddTeacherToFile(teachers, "teachers.txt");
	evt.Skip();
}

void TeacherFrame::OnRemoveButtonClicked(wxCommandEvent& evt)
{
	deleteSelectedTeacher();
}

void TeacherFrame::InitializeListView()
{
	listView = new wxListView(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	listView->SetBackgroundColour(wxColor(105, 105, 105));
	listView->SetForegroundColour(*wxWHITE);

	listView->InsertColumn(0, "Id");
	listView->InsertColumn(1, "Email");
	listView->InsertColumn(2, "Full Name");
	listView->InsertColumn(3, "Phone Number");
	listView->InsertColumn(4, "Age");

	AdjustColumnWidths();
}

void TeacherFrame::AdjustColumnWidths()
{
	int totalWidth = listView->GetClientSize().GetWidth();
	int columnWidth = totalWidth / 5;

	// Set each column width dynamically
	for (int i = 0; i < 5; ++i)
	{
		listView->SetColumnWidth(i, columnWidth);
	}
}

void TeacherFrame::OnSize(wxSizeEvent& evt)
{
	AdjustColumnWidths();

	evt.Skip();
}

