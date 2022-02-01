#include "Group.h"
#include<string>
#include<fstream>

Group::Group() :count{ 0 }
{
}

void Group::addStudent(const Student& student)
{
	this->students.add(student);
	this->count++;
}

const Student& Group::getStudent(unsigned int index) const
{
	return this->students[index];
}

void Group::print() const
{
	for (unsigned int i = 0; i < this->count; i++)
	{
		std::cout << this->students[i];
	}
}

void Group::writeToFile(const std::string& path) const
{
	std::ofstream file;

	file.open(path);

	if (!file.is_open())
		throw std::exception("Cannot open the file\n");

	for (unsigned int i = 0; i < this->count; i++)
	{
		file << this->students[i];
	}

	file.close();
}

void Group::readFromFile(const std::string& path)
{
	std::ifstream file;

	file.open(path);

	if (!file.is_open())
		throw std::exception("Cannot open the file\n");

	std::string str;

	while (std::getline(file, str))
	{
		size_t pos = 0;

		pos = str.find(':');
		std::string name = str.substr(0, pos);
		str.erase(0, pos + 1);

		this->students.add(Student(name));

		std::string sup = ", ";

		while ((pos = str.find(sup)) != std::string::npos)
		{
			this->students[count].addGrade(std::stoi(str.substr(0, pos)));
			str.erase(0, pos + sup.length());
		}

		this->students[count].addGrade(std::stoi(str.substr(0, pos)));

		count++;
	}

	file.close();
}
