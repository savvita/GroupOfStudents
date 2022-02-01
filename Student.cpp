#include "Student.h"

Student::Student(const std::string& name) :name{ name }
{
}

Student::Student(const Student& student)
{
	this->name = student.name;
	this->grades = student.grades;
}

Student::Student(Student&& student) noexcept :name{ student.name }, grades{ student.grades }
{
}

unsigned int Student::getGrade(unsigned int index) const
{
	return this->grades[index];
}

void Student::addGrade(unsigned int grade)
{
	this->grades.add(grade);
}

double Student::avrgGrade() const
{
	unsigned int size = this->grades.size();

	double avrg = 0;

	for (unsigned int i = 0; i < size; i++)
	{
		avrg += this->grades[i];
	}

	return avrg / size;
}

Student& Student::operator=(const Student& student)
{
	this->name = student.name;
	this->grades = student.grades;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.name << ": ";

	unsigned int size = student.grades.size();

	for (unsigned int i = 0; i < size - 1; i++)
	{
		out << student.grades[i] << ", ";
	}

	out << student.grades[size - 1] << "\n";

	return out;
}
