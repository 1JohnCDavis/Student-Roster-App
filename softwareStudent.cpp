#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() : Student()
{
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t" << "\t";
	//cout << left << setw(20) << emailAddress;
	cout << getAge() << "\t";
	cout << getDaysAt(0) << "\t";
	cout << getDaysAt(1) << "\t";
	cout << getDaysAt(2) << "\t";
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
