#include <iostream>
#include"Group.h"

int main()
{
	Student s("John Smith");
	s.addGrade(10);
	s.addGrade(12);
	s.addGrade(8);
	s.addGrade(9);
	
	Student s2("Jane Doe");
	s2.addGrade(5);
	s2.addGrade(7);
	s2.addGrade(8);
	s2.addGrade(12);

	Group group;
	group.addStudent(s);
	group.addStudent(s2);

	group.print();
	std::cout << "======================\n";

	std::cout << group.getStudent(1);
	std::cout << "======================\n";

	group.writeToFile("44.txt");

	group.readFromFile("44.txt");

	group.print();
	std::cout << "======================\n";
}
