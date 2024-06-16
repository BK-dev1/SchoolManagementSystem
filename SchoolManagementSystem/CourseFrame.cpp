#include "CourseFrame.h"
#include "Course.h"

CourseFrame::CourseFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
	SetupSizers();
	BindEventHandelers();
	AddSavedFirstYearCourses();
	AddSavedSecondYearCourses();
	AddSavedThirdYearCourses();
}

void CourseFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
	scrolledWindow->SetScrollRate(10, 10);
	scrolledWindow->SetFont(mainFont);
	scrolledWindow->SetBackgroundColour(wxColor(105, 105, 105));


	headlineText = new wxStaticText(scrolledWindow, wxID_ANY, wxT("Courses"),
		wxDefaultPosition, wxDefaultSize);
	headlineText->SetFont(headlineFont);
	headlineText->SetForegroundColour(*wxWHITE);

	FirstYearLabel = new wxStaticText(scrolledWindow, wxID_ANY, wxT("First Year Courses:"),
		wxDefaultPosition, wxDefaultSize);
	FirstYearLabel->SetForegroundColour(*wxWHITE);
	FirstYearEditButton = new wxButton(scrolledWindow,wxID_ANY,"Edit");
	FirstYearEditButton->SetBackgroundColour(*wxBLACK);
	FirstYearEditButton->SetForegroundColour(*wxWHITE);


	InitializeListView1();

	SecondYearLabel = new wxStaticText(scrolledWindow, wxID_ANY, wxT("Second Year Courses:"),
		wxDefaultPosition, wxDefaultSize);
	SecondYearLabel->SetForegroundColour(*wxWHITE);

	SecondYearEditButton = new wxButton(scrolledWindow, wxID_ANY, "Edit");
	SecondYearEditButton->SetBackgroundColour(*wxBLACK);
	SecondYearEditButton->SetForegroundColour(*wxWHITE);

	InitializeListView2();


	ThirdYearLabel = new wxStaticText(scrolledWindow, wxID_ANY, wxT("Third Year Courses:"),
		wxDefaultPosition, wxDefaultSize);
	ThirdYearLabel->SetForegroundColour(*wxWHITE);

	
	ThirdYearEditButton = new wxButton(scrolledWindow, wxID_ANY, "Edit");
	ThirdYearEditButton->SetBackgroundColour(*wxBLACK);
	ThirdYearEditButton->SetForegroundColour(*wxWHITE);

	InitializeListView3();


}

void CourseFrame::SetupSizers()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* outerSizer = new wxGridSizer(1);
	outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

	mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
	mainSizer->AddSpacer(15);
	mainSizer->Add(FirstYearLabel, wxSizerFlags().CenterHorizontal());
	
	mainSizer->Add(FirstYearListView, wxSizerFlags().Expand());
	mainSizer->Add(FirstYearEditButton, wxSizerFlags().Expand());
	mainSizer->AddSpacer(15);
	mainSizer->Add(SecondYearLabel, wxSizerFlags().CenterHorizontal());

	mainSizer->Add(SecondYearListView, wxSizerFlags().Expand());
	mainSizer->Add(SecondYearEditButton, wxSizerFlags().Expand());

	mainSizer->AddSpacer(15);
	mainSizer->Add(ThirdYearLabel, wxSizerFlags().CenterHorizontal());

	mainSizer->Add(ThirdYearListView, wxSizerFlags().Expand());
	mainSizer->Add(ThirdYearEditButton, wxSizerFlags().Expand());

	scrolledWindow->SetSizer(outerSizer);
	outerSizer->SetSizeHints(this);
}

void CourseFrame::BindEventHandelers()
{
	Bind(wxEVT_SIZE, &CourseFrame::OnSize, this);
	FirstYearListView->Bind(wxEVT_KEY_DOWN, &CourseFrame::onListKeyDown, this);

}

void CourseFrame::AddSavedFirstYearCourses()
{
	std::vector<Course> courses = LoadCoursesFromFile("FirstYearCourse.txt");
	for (const Course& course : courses)
	{
		std::string stdId = std::to_string(course.id);
		wxString id(stdId);
		long itemIndex = FirstYearListView->InsertItem(0, id);
		FirstYearListView->SetItem(itemIndex, 1, course.Name);
		FirstYearListView->SetItem(itemIndex, 2, course.NumberOfLectureHours);
		FirstYearListView->SetItem(itemIndex, 3, course.NumberOfTutorialHours);
		FirstYearListView->SetItem(itemIndex, 4, course.NumberOfLabHours);
		
		wxString coefficient = wxString::FromDouble(course.coefficient);
		FirstYearListView->SetItem(itemIndex, 5, coefficient);

		wxString credits = wxString::FromDouble(course.Credits);
		FirstYearListView->SetItem(itemIndex, 6, credits);
		wxString CCEvaluation = wxString::FromDouble(course.CCEvaluation);
		FirstYearListView->SetItem(itemIndex, 7, CCEvaluation);
		wxString ExamEvaluation = wxString::FromDouble(course.ExamEvaluation);
		FirstYearListView->SetItem(itemIndex, 8, ExamEvaluation);
	}
}

void CourseFrame::AddSavedSecondYearCourses()
{
	std::vector<Course> courses = LoadCoursesFromFile("SecondYearCourse.txt");
	for (const Course& course : courses)
	{
		std::string stdId = std::to_string(course.id);
		wxString id(stdId);
		long itemIndex = SecondYearListView->InsertItem(0, id);
		SecondYearListView->SetItem(itemIndex, 1, course.Name);
		SecondYearListView->SetItem(itemIndex, 2, course.NumberOfLectureHours);
		SecondYearListView->SetItem(itemIndex, 3, course.NumberOfTutorialHours);
		SecondYearListView->SetItem(itemIndex, 4, course.NumberOfLabHours);

		wxString coefficient = wxString::FromDouble(course.coefficient);
		SecondYearListView->SetItem(itemIndex, 5, coefficient);

		wxString credits = wxString::FromDouble(course.Credits);
		SecondYearListView->SetItem(itemIndex, 6, credits);
		wxString CCEvaluation = wxString::FromDouble(course.CCEvaluation);
		SecondYearListView->SetItem(itemIndex, 7, CCEvaluation);
		wxString ExamEvaluation = wxString::FromDouble(course.ExamEvaluation);
		SecondYearListView->SetItem(itemIndex, 8, ExamEvaluation);
	}
}

void CourseFrame::AddSavedThirdYearCourses()
{
	std::vector<Course> courses = LoadCoursesFromFile("ThirdYearCourse.txt");
	for (const Course& course : courses)
	{
		std::string stdId = std::to_string(course.id);
		wxString id(stdId);
		long itemIndex = ThirdYearListView->InsertItem(0, id);
		ThirdYearListView->SetItem(itemIndex, 1, course.Name);
		ThirdYearListView->SetItem(itemIndex, 2, course.NumberOfLectureHours);
		ThirdYearListView->SetItem(itemIndex, 3, course.NumberOfTutorialHours);
		ThirdYearListView->SetItem(itemIndex, 4, course.NumberOfLabHours);

		wxString coefficient = wxString::FromDouble(course.coefficient);
		ThirdYearListView->SetItem(itemIndex, 5, coefficient);

		wxString credits = wxString::FromDouble(course.Credits);
		ThirdYearListView->SetItem(itemIndex, 6, credits);
		wxString CCEvaluation = wxString::FromDouble(course.CCEvaluation);
		ThirdYearListView->SetItem(itemIndex, 7, CCEvaluation);
		wxString ExamEvaluation = wxString::FromDouble(course.ExamEvaluation);
		ThirdYearListView->SetItem(itemIndex, 8, ExamEvaluation);
	}
}



void CourseFrame::onListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_UP:
		MoveSelection(-1);
		break;
	case WXK_DOWN:
		MoveSelection(1);
		break;
	}
}

void CourseFrame::MoveSelection(int offset)
{
	int selectedIndex = FirstYearListView->GetFirstSelected();
	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}
	int newIndex = selectedIndex + offset;

	if (newIndex >= 0 && newIndex < FirstYearListView->GetItemCount())
	{
		FirstYearListView->Select(newIndex, true);
		FirstYearListView->Select(selectedIndex, false);
	}
}



void CourseFrame::InitializeListView1()
{
	FirstYearListView = new wxListView(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	FirstYearListView->SetBackgroundColour(wxColor(128, 128, 128));
	FirstYearListView->SetForegroundColour(*wxWHITE);


	FirstYearListView->InsertColumn(0, "Id");
	FirstYearListView->InsertColumn(1, "Name");
	FirstYearListView->InsertColumn(2, "Number of Lecture Hours");
	FirstYearListView->InsertColumn(3, "Number of Tutorial Hours");
	FirstYearListView->InsertColumn(4, "Number of Lab Hours");
	FirstYearListView->InsertColumn(5, "Coefficient");
	FirstYearListView->InsertColumn(6, "Credits");
	FirstYearListView->InsertColumn(7, "C.C Evaluation");
	FirstYearListView->InsertColumn(8, "Exam Evaluation");

	AdjustColumnWidths1();
}
void CourseFrame::InitializeListView2()
{
	SecondYearListView = new wxListView(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	SecondYearListView->SetBackgroundColour(wxColor(128, 128, 128));
	SecondYearListView->SetForegroundColour(*wxWHITE);

	SecondYearListView->InsertColumn(0, "Id");
	SecondYearListView->InsertColumn(1, "Name");
	SecondYearListView->InsertColumn(2, "Number of Lecture Hours");
	SecondYearListView->InsertColumn(3, "Number of Tutorial Hours");
	SecondYearListView->InsertColumn(4, "Number of Lab Hours");
	SecondYearListView->InsertColumn(5, "Coefficient");
	SecondYearListView->InsertColumn(6, "Credits");
	SecondYearListView->InsertColumn(7, "C.C Evaluation");
	SecondYearListView->InsertColumn(8, "Exam Evaluation");

	AdjustColumnWidths2();
}
void CourseFrame::InitializeListView3()
{
	ThirdYearListView = new wxListView(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	ThirdYearListView->SetBackgroundColour(wxColor(128, 128, 128));
	ThirdYearListView->SetForegroundColour(*wxWHITE);

	ThirdYearListView->InsertColumn(0, "Id");
	ThirdYearListView->InsertColumn(1, "Name");
	ThirdYearListView->InsertColumn(2, "Number of Lecture Hours");
	ThirdYearListView->InsertColumn(3, "Number of Tutorial Hours");
	ThirdYearListView->InsertColumn(4, "Number of Lab Hours");
	ThirdYearListView->InsertColumn(5, "Coefficient");
	ThirdYearListView->InsertColumn(6, "Credits");
	ThirdYearListView->InsertColumn(7, "C.C Evaluation");
	ThirdYearListView->InsertColumn(8, "Exam Evaluation");

	AdjustColumnWidths3();
}

void CourseFrame::AdjustColumnWidths1()
{
	int totalWidth = FirstYearListView->GetClientSize().GetWidth();
	int columnWidth = 2*(totalWidth / 9);

	// Set each column width dynamically
	for (int i = 0; i < 9; ++i)
	{
		FirstYearListView->SetColumnWidth(i, columnWidth);
	}
}
void CourseFrame::AdjustColumnWidths2()
{
	int totalWidth = SecondYearListView->GetClientSize().GetWidth();
	int columnWidth = 2 * (totalWidth / 9);

	// Set each column width dynamically
	for (int i = 0; i < 9; ++i)
	{
		SecondYearListView->SetColumnWidth(i, columnWidth);
	}
}
void CourseFrame::AdjustColumnWidths3()
{
	int totalWidth = ThirdYearListView->GetClientSize().GetWidth();
	int columnWidth = 2 * (totalWidth / 9);

	// Set each column width dynamically
	for (int i = 0; i < 9; ++i)
	{
		ThirdYearListView->SetColumnWidth(i, columnWidth);
	}
}

void CourseFrame::OnSize(wxSizeEvent& evt)
{
	AdjustColumnWidths1();
	AdjustColumnWidths2();
	AdjustColumnWidths3();

	evt.Skip();
}
