#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course;

class Student {
private:
    string name;
    int ID;
    vector<Course*> selectedCourses;

public:
    Student(string studentName, int studentID):name(studentName),ID(studentID){}

    void selectCourse(Course* course) {
        selectedCourses.push_back(course);
    }

    void printSelectedCourses() {
        cout << "Courses selected by " << name << " (ID: " << ID << "):" << endl;
        for (Course* course : selectedCourses) {
            cout << "- " << course->getName() << endl;
        }
    }
    string getName(){
        return name;
    }
};

class Course {
private:
    string name;
    int ID;
    int creditHours;
    vector<Student*> enrolledStudents;

public:
    Course(string courseName, int courseID, int credit):name(courseName),ID(courseID),creditHours(credit){}

    void enrollStudent(Student* student) {
        enrolledStudents.push_back(student);
        student->selectCourse(this);
    }

    string getName() {
        return name;
    }

    int getCreditHours() {
        return creditHours;
    }

    void printEnrolledStudents() {
        cout << "Students enrolled in " << name << " (ID: " << ID << "):" << endl;
        for (Student* student : enrolledStudents) {
            cout << "- " << student->getName() << " (ID: " << student->ID << ")" << endl;
        }
    }
};

int main() {
    Student student1("Alice", 1001);
    Student student2("Bob", 1002);

    Course math("Mathematics", 2001, 3);
    Course physics("Physics", 2002, 4);

    math.enrollStudent(&student1);
    math.enrollStudent(&student2);
    physics.enrollStudent(&student1);

    student1.printSelectedCourses();
    cout << endl;
    math.printEnrolledStudents();
    cout << "Total credit hours for " << math.getName() << ": " << math.getCreditHours() << endl;

    return 0;
}
