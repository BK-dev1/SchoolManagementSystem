#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>


struct Exam
{
	int id;
	std::string Name;
	std::string Date;
	std::string time;
	bool finished;
};

void AddExamToFile(const std::vector<Exam>& Exams, const std::string& fileName);

std::vector<Exam> LoadExamFromFile(const std::string& fileName);
