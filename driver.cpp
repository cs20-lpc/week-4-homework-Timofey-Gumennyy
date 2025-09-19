#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

static void printSeparator(const string &title) {
  cout << "\n===== " << title << " =====" << endl;
}

static void printList(LinkedList<Student> &students) {
  int len = students.getLength();
  cout << "Students in List (count=" << len << "):" << endl;
  for (int i = 0; i < len; ++i) {
    Student cur = students.getElement(i);
    cout << cur;
    cur.DisplayAllCourses();
    cout << endl;
  }
}

int main()
{
  LinkedList<Student> students;

  // Scenario 1: Insert One Student, Display, Count
  printSeparator("Scenario 1: Insert One Student, Display, Count");
  students.append(Student(101, "John Doe", 3.2));
  printList(students);
  cout << "Total students: " << students.getLength() << endl;

  // Scenario 2: Insert Multiple Students, Display Order
  printSeparator("Scenario 2: Insert Multiple Students, Display Order");
  students.append(Student(100, "Alice", 3.8));
  students.append(Student(200, "Bob", 2.9));
  printList(students);

  // Scenario 3: Search Existing and Non-Existing Student
  printSeparator("Scenario 3: Search Existing and Non-Existing Student");
  {
    int id = 100; // should find Alice
    bool found = false;
    for (int i = 0; i < students.getLength(); ++i) {
      Student cur = students.getElement(i);
      if (cur.id == id) {
        cout << "Found (id=" << id << "): ";
        cout << cur;
        cout << "  Courses: "; cur.DisplayAllCourses(); cout << endl;
        found = true; break;
      }
    }
    if (!found) cout << "Student not found for id=" << id << endl;

    id = 999; // should not find
    found = false;
    for (int i = 0; i < students.getLength(); ++i) {
      Student cur = students.getElement(i);
      if (cur.id == id) { found = true; break; }
    }
    if (!found) cout << "Student not found for id=" << id << endl;
  }

  // Scenario 4: Add a Course to a Student, Then Display / Search
  printSeparator("Scenario 4: Add a Course to a Student, Then Display / Search");
  {
    int id = 200; // add course to Bob
    bool added = false;
    for (int i = 0; i < students.getLength(); ++i) {
      Student cur = students.getElement(i);
      if (cur.id == id) {
        Course c("CS101", "Room 1");
        cur.courses.push_back(c);
        // ensure we write the modified student back into the list
        students.replace(i, cur);
        added = true; break;
      }
    }
    if (!added) cout << "Student not found for adding course (id=" << id << ")" << endl;
    // display and search
    printList(students);
  }

  // Scenario 5: Delete Student (existing and non-existing)
  printSeparator("Scenario 5: Delete Student (existing and non-existing)");
  {
    int id = 100; // delete Alice
    bool deleted = false;
    for (int i = 0; i < students.getLength(); ++i) {
      Student cur = students.getElement(i);
      if (cur.id == id) { students.remove(i); cout << "Deleted student with ID " << id << endl; deleted = true; break; }
    }
    if (!deleted) cout << "Student not found id=" << id << endl;
    // attempt to delete non-existing
    id = 999;
    deleted = false;
    for (int i = 0; i < students.getLength(); ++i) {
      Student cur = students.getElement(i);
      if (cur.id == id) { students.remove(i); deleted = true; break; }
    }
    if (!deleted) cout << "Student not found id=" << id << endl;
    cout << "After deletions: "; printList(students);
  }

  // Scenario 6: Edge Cases - invalid inputs cannot be simulated easily here, but we can show count
  printSeparator("Scenario 6: Final Count / Exit");
  cout << "Total students: " << students.getLength() << endl;

  cout << "\nAll scenarios completed." << endl;
  return 0;
}
