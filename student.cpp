#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < NUM_DAYS_COURSE; i++) this->days[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[])
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < NUM_DAYS_COURSE; i++) this->days[i] = days[i];
}


//getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int * Student::getDays()
{
	return days;
}

int Student::getDaysAt(int index) {
	if (index < NUM_DAYS_COURSE) {
		return days[index];
	}
	else 
		return 0;
}

//setters

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDays(int days[])
{
	for (int i = 0; i < NUM_DAYS_COURSE; i++) this->days[i] = days[i];
}


void Student::print()
{
	cout << studentID << "\t";
	cout << firstName << "\t";
	cout << lastName << "\t";
	//cout << left << setw(20) << emailAddress;
	cout << age << "\t";
	cout << days[0] << "\t";
	cout << days[1] << "\t";
	cout << days[2] << "\t";
}


Student::~Student()
{

}
