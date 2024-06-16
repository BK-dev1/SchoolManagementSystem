#include "Teacher.h"
#include <iostream>
void AddTeacherToFile(const std::vector<Teacher>& Teachers, const std::string& fileName)
{
	std::ofstream ostream(fileName);
	ostream << Teachers.size();
	for (const Teacher& teacher : Teachers) {
		std::string FullName = teacher.FullName;
		std::replace(FullName.begin(), FullName.end(), ' ', '_');
		ostream << '\n' << teacher.id << ' ' << FullName << ' ' << teacher.age << ' ' << teacher.Email <<
			' ' << teacher.PhoneNumber;
	}
}




std::vector<Teacher> LoadTeacherFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName))
	{
		return std::vector<Teacher>();
	}
	std::vector<Teacher> teachers;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++)
	{
		int id;
		std::string FullName;
		int Age;
		std::string Email;
		std::string PhoneNumber;

		istream >> id >> FullName >> Age >> Email >> PhoneNumber ;
		std::replace(FullName.begin(), FullName.end(), '_', ' ');

		teachers.push_back(Teacher{ id , FullName,Age, Email, PhoneNumber});
	}
	std::cout << "File loaded";
	return teachers;
}
