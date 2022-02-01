#pragma once
#include<iostream>
#include"SLinkedList.h"

class Student
{
private:
	std::string name;
	SLinkedList<unsigned int> grades;

public:
	//ctor
	Student() = default;
	explicit Student(const std::string& name);
	Student(const Student& student);
	Student(Student&& student) noexcept;
	//=======================

	//gets
	inline const std::string& getName() const
	{
		return this->name;
	}
	unsigned int getGrade(unsigned int index) const;
	//=======================

	//add a grade
	void addGrade(unsigned int grade);

	//get an average grade
	double avrgGrade() const;


	friend std::ostream& operator<<(std::ostream& out, const Student& student);

	Student& operator=(const Student& student);
};

