#include "Student.hpp"
#include <iostream>

// Add a course to this student
void Student::AddCourse(const Course &course)
{
	courses.push_back(course);
}

// Display all courses for this student (prints "None" if no courses)
void Student::DisplayAllCourses()
{
	if (courses.empty()) {
		std::cout << "None" << std::endl;
		return;
	}

	for (size_t i = 0; i < courses.size(); ++i) 
		courses[i].PrintCourseInfo();
	
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Student &s)
{
	os << "Found: " << s.id << " " << s.name << " " << s.gpa << std::endl;
	// if (s.courses.empty()) {
	// 	os << "  Courses: None" << std::endl;
	// } else {
	// 	os << "  Courses: " ;
	// 	for (size_t i = 0; i < s.courses.size(); ++i) {
	// 		os << s.courses[i].name << " " << s.courses[i].location;
	// 		if (i + 1 < s.courses.size()) os << std::endl << "           ";
	// 	}
	// 	os << std::endl;
	// }
	return os;
}
