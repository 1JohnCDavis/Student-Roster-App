#pragma once
#include <string>
#include "student.h"

class NetworkingStudent : public Student
{
public:
	NetworkingStudent();
	NetworkingStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree degreeType);

	Degree getDegreeType();
	virtual void print();

	virtual ~NetworkingStudent();

};