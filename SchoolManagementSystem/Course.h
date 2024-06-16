#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>


struct Course 
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
};

std::vector<Course>LoadCoursesFromFile(const std::string& filename);

