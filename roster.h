#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"


class Roster
{

private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string sID, string sFirstName, string sLastName, string sEmailAddress, int sAge, int sD1, int sD2, int sD3, Degree sD);
	void print_All();
	bool remove(string id);
	void printAverageDays(string id);
	void printInvalidEmails();
	void printByDegreeType(Degree s);
	int size();
	~Roster();
	   
};