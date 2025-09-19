#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course {
public:
	Course(const std::string &name, const std::string &location)
		: name(name), location(location) {}

	std::string name;
	std::string location;
    void PrintCourseInfo();
};

#endif 
