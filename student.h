#pragma once
#include <string>
#include "degree.h"
using std::string;


const static int NUM_DAYS_COURSE = 3;

class Student
{

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[NUM_DAYS_COURSE];
	

protected:
	//virtual void setDegree(Degree dt) = 0;
	Degree degreeType;

public:
	Student(); //empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[]);

	//the destructor
	virtual ~Student();
	
	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	int getDaysAt(int index);
	virtual Degree getDegreeType() = 0;

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	
	virtual void print() = 0;

	
};
