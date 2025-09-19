// TO DO:  Student class definition  here.

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include "Course.hpp"

class Student {
public:
	Student(int id, const std::string &name, double gpa)
		: id(id), name(name), gpa(gpa) {}

	int id;
	std::string name;
	double gpa;
	std::vector<Course> courses;
	friend std::ostream& operator<<(std::ostream &os, const Student &s);

	void AddCourse(const Course &c);
	void DisplayAllCourses();
};

#endif // STUDENT_HPP
