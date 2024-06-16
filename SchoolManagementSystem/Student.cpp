#include "Student.h"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <iostream>


void AddStudentToFile(const std::vector<Student>& Students, const std::string& fileName)
{
	std::ofstream ostream(fileName);
	ostream << Students.size();
	for (const Student& student : Students ) {
		std::string FullName = student.FullName;
		std::replace(FullName.begin(),FullName.end(),' ', '_');
		ostream << '\n' << student.id << ' ' << FullName << ' ' << student.age << ' ' << student.Email <<
			' ' << student.PhoneNumber << ' ' << student.year;
	}
}

std::vector<Student> LoadStudentFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName))
	{
		return std::vector<Student>();
	}
	std::vector<Student> students;
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
		int Year;
		
		istream >> id >> FullName >> Age >> Email >> PhoneNumber >> Year;
		std::replace(FullName.begin(), FullName.end(),'_' , ' ');

		students.push_back(Student{id, FullName, Age, Email, PhoneNumber, Year});
	}
	std::cout << "File loaded";
	return students;
}
