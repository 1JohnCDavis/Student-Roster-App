#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() : Student()
{
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeType()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t" << "\t";
	//cout << left << setw(20) << emailAddress;
	cout << getAge() << "\t";
	cout << getDaysAt(0) << "\t";
	cout << getDaysAt(1) << "\t";
	cout << getDaysAt(2) << "\t";
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}
