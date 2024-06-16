#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "Course.h"
#include "Exam.h"


struct Teacher
{
	long id;
	std::string FullName;
	long age;
	std::string Email;
	std::string PhoneNumber;
	//std::vector<Course> teachingCourses;
};



void AddTeacherToFile(const std::vector<Teacher>& Teachers, const std::string& fileName);

std::vector<Teacher> LoadTeacherFromFile(const std::string& fileName);


