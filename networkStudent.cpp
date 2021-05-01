#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkingStudent::NetworkingStudent() : Student()
{
	degreeType = NETWORKING;
}

NetworkingStudent::NetworkingStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	degreeType = NETWORKING;
}

Degree NetworkingStudent::getDegreeType()
{
	return NETWORKING;
}

void NetworkingStudent::print()
{
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	//cout << left << setw(20) << emailAddress;
	cout << getAge() << "\t";
	cout << getDaysAt(0) << "\t";
	cout << getDaysAt(1) << "\t";
	cout << getDaysAt(2) << "\t";
	cout << "NETWORKING" << "\n";
}

NetworkingStudent::~NetworkingStudent()
{
	Student::~Student();
}
