#pragma once
#include"Student.h"

class Group
{
private:
	SLinkedList<Student> students;
	unsigned int count;

public:
	Group();

	void addStudent(const Student& student);

	const Student& getStudent(unsigned int index) const;

	void print() const;

	void writeToFile(const std::string& path) const;

	void readFromFile(const std::string& path);
};

