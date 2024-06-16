#include "ExamFrame.h"

ExamFrame::ExamFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
	SetupSizers();
	BindEventHandelers();
}

void ExamFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	MainPanel = new wxPanel(this,wxID_ANY);
	MainPanel->SetFont(mainFont);
	MainPanel->SetBackgroundColour(wxColor(105, 105, 105));


	headlineText = new wxStaticText(MainPanel, wxID_ANY, wxT("Exams"));
	headlineText->SetFont(headlineFont);
	headlineText->SetForegroundColour(*wxWHITE);

	idLabel = new wxStaticText(MainPanel, wxID_ANY, wxT("Id:"));
	nameLabel = new wxStaticText(MainPanel, wxID_ANY, wxT("Name:"));


	idInput = new wxTextCtrl(MainPanel,wxID_ANY);
	nameInput = new wxTextCtrl(MainPanel, wxID_ANY);

	DaySpinCtrl = new wxSpinCtrl(MainPanel, wxID_ANY);
	DaySpinCtrl->SetRange(1,31);
	DaySpinCtrl->SetValue(1);

	MonthSpinCtrl = new wxSpinCtrl(MainPanel, wxID_ANY);
	MonthSpinCtrl->SetRange(1, 12);
	MonthSpinCtrl->SetValue(1);

	YearSpinCtrl = new wxSpinCtrl(MainPanel, wxID_ANY);
	YearSpinCtrl->SetRange(1900, 2100);
	YearSpinCtrl->SetValue(2024);

	HourSpinCtrl = new wxSpinCtrl(MainPanel, wxID_ANY);
	HourSpinCtrl->SetRange(0, 23);
	HourSpinCtrl->SetValue(12);

	MinuteSpinCtrl = new wxSpinCtrl(MainPanel, wxID_ANY);
	MinuteSpinCtrl->SetRange(0, 59);
	MinuteSpinCtrl->SetValue(0);

	addButton = new wxButton(MainPanel,wxID_ANY,wxT("Add"));
	addButton->SetBackgroundColour(*wxBLACK);
	addButton->SetForegroundColour(*wxWHITE);
	removeButton = new wxButton(MainPanel, wxID_ANY, wxT("Remove"));
	removeButton->SetBackgroundColour(*wxBLACK);
	removeButton->SetForegroundColour(*wxWHITE);
	editButton = new wxButton(MainPanel, wxID_ANY, wxT("Edit"));
	editButton->SetBackgroundColour(*wxBLACK);
	editButton->SetForegroundColour(*wxWHITE);

	InitializeListView();
}

void ExamFrame::SetupSizers()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* outerSizer = new wxGridSizer(1);
	outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

	mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
	mainSizer->AddSpacer(25);

	wxBoxSizer* labelSizer = new wxBoxSizer(wxHORIZONTAL);
	labelSizer->Add(idLabel, wxSizerFlags().Proportion(1));
	labelSizer->AddSpacer(15);
	labelSizer->Add(nameLabel, wxSizerFlags().Proportion(1));

	wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);
	inputSizer->Add(idInput, wxSizerFlags().Proportion(1));
	inputSizer->AddSpacer(15);
	inputSizer->Add(nameInput, wxSizerFlags().Proportion(1));

	wxBoxSizer* spinSizer = new wxBoxSizer(wxHORIZONTAL);

	spinSizer->Add(new wxStaticText(MainPanel,wxID_ANY,"Day:"), wxSizerFlags().CenterVertical());
	spinSizer->AddSpacer(5);
	spinSizer->Add(DaySpinCtrl, wxSizerFlags().Proportion(1));

	spinSizer->AddSpacer(15);

	spinSizer->Add(new wxStaticText(MainPanel, wxID_ANY, "Month:"), wxSizerFlags().CenterVertical());
	spinSizer->AddSpacer(5);
	spinSizer->Add(MonthSpinCtrl, wxSizerFlags().Proportion(1));

	spinSizer->AddSpacer(15);

	spinSizer->Add(new wxStaticText(MainPanel, wxID_ANY, "Year:"), wxSizerFlags().CenterVertical());
	spinSizer->AddSpacer(5);
	spinSizer->Add(YearSpinCtrl, wxSizerFlags().Proportion(1));

	spinSizer->AddSpacer(15);

	spinSizer->Add(new wxStaticText(MainPanel, wxID_ANY, "Hour:"), wxSizerFlags().CenterVertical());
	spinSizer->AddSpacer(5);
	spinSizer->Add(HourSpinCtrl, wxSizerFlags().Proportion(1));

	spinSizer->AddSpacer(15);

	spinSizer->Add(new wxStaticText(MainPanel, wxID_ANY, "Minutes:"), wxSizerFlags().CenterVertical());
	spinSizer->AddSpacer(5);
	spinSizer->Add(MinuteSpinCtrl, wxSizerFlags().Proportion(1));

	spinSizer->AddSpacer(15);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	buttonSizer->Add(addButton, wxSizerFlags().Proportion(1));
	buttonSizer->AddSpacer(15);
	buttonSizer->Add(removeButton, wxSizerFlags().Proportion(1));
	buttonSizer->AddSpacer(15);
	buttonSizer->Add(editButton, wxSizerFlags().Proportion(1));

	mainSizer->Add(labelSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(inputSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(spinSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(buttonSizer, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(listView, wxSizerFlags().Expand());

	MainPanel->SetSizer(outerSizer);
	outerSizer->SetSizeHints(this);
}

void ExamFrame::BindEventHandelers()
{

	Bind(wxEVT_SIZE, &ExamFrame::OnSize, this);

}

void ExamFrame::InitializeListView()
{
	listView = new wxListView(MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	listView->SetBackgroundColour(wxColor(105, 105, 105));
	listView->SetForegroundColour(*wxWHITE);

	listView->InsertColumn(0, "Id");
	listView->InsertColumn(1, "Name");
	listView->InsertColumn(2, "Date");
	listView->InsertColumn(3, "Time");

	AdjustColumnWidths();
}

void ExamFrame::AdjustColumnWidths()
{
	int totalWidth = listView->GetClientSize().GetWidth();
	int columnWidth = totalWidth / 4;

	// Set each column width dynamically
	for (int i = 0; i < 4; ++i)
	{
		listView->SetColumnWidth(i, columnWidth);
	}
}

void ExamFrame::OnSize(wxSizeEvent& evt)
{

	AdjustColumnWidths();

	evt.Skip();
}

