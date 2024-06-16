#include "Course.h"
#include <iostream>

std::vector<Course> LoadCoursesFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName))
	{
		return std::vector<Course>();
	}
	std::vector<Course> courses;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++)
	{
		long id;
		std::string Name;
		std::string NumberOfLectureHours;
		std::string NumberOfTutorialHours;
		std::string NumberOfLabHours;
		long coefficient;
		long Credits;
		long CCEvaluation;
		long ExamEvaluation;

		istream >> id >> Name >> NumberOfLectureHours >> NumberOfTutorialHours >> 
			NumberOfLabHours >> coefficient >> Credits >> CCEvaluation >> ExamEvaluation ;
		std::replace(Name.begin(), Name.end(), '_', ' ');

		courses.push_back(Course{ id, Name, NumberOfLectureHours,
			NumberOfTutorialHours, NumberOfLabHours, coefficient,
			Credits,CCEvaluation,ExamEvaluation });
	}
	std::cout << "File loaded";
	return courses;
}
