#pragma once
#include <string>
#include <vector>
#include "Course.h"
#include "Exam.h"

struct Student
{
	long id;
	std::string FullName;
	long age;
	std::string Email;
	std::string PhoneNumber;
	long year;
	//std::vector<Course> enrolledCourses;
	//std::vector<Exam> Exams;
};

void AddStudentToFile(const std::vector<Student>& Students, const std::string& fileName);

std::vector<Student> LoadStudentFromFile(const std::string& fileName);

