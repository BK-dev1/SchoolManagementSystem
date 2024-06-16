#include "Exam.h"
#include <iostream>


void AddExamToFile(const std::vector<Exam>& Exams, const std::string& fileName)
{
	std::ofstream ostream(fileName);
	ostream << Exams.size();
	for (const Exam& exam : Exams) {
		std::string FullName = exam.Name;
		std::replace(FullName.begin(), FullName.end(), ' ', '_');
		ostream << '\n' << exam.id << ' ' << FullName << ' ' << exam.Date << ' ' << exam.time << ' ' << exam.finished;
	}
}

std::vector<Exam> LoadExamFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName))
	{
		return std::vector<Exam>();
	}
	std::vector<Exam> exams;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++)
	{
		int id;
		std::string Name;
		std::string Date;
		std::string time;
		bool finished;

		istream >> id >> Name >> Date >> time >> finished;
		std::replace(Name.begin(), Name.end(), '_', ' ');

		exams.push_back(Exam{ id, Name, Date, time, finished });
	}
	std::cout << "File loaded";
	return exams;
}
