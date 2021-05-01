#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "roster.h"

using namespace std;

const int MAX_STUDENT_CAPACITY = 5;

bool isValidEmail(string email);

//Roster class begins
Roster::Roster()
	:Roster(MAX_STUDENT_CAPACITY)
{

}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity - 1) {
		//lastIndex++;
		Degree degreeType;
		

		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sFirstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sLastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sEmailAddress = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sAge = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day1 = stod(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day2 = stod(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day3 = stod(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string degreeName = row.substr(lhs, rhs - lhs);

		if (degreeName.compare("SECURITY") == 0) 
			degreeType = SECURITY;
		else if (degreeName.compare("NETWORK") == 0) 
			degreeType = NETWORKING;
		else if (degreeName.compare("SOFTWARE") == 0) 
			degreeType = SOFTWARE;
		else {
			cerr << "Invalid degree type!  Exiting now!\n";
			exit(-1);
		}

		add(sID, sFirstName, sLastName, sEmailAddress, sAge, day1, day2, day3, degreeType);
	}
	else
	{
		cerr << "Error!  List has exceeded maximum capacity!\n  Exiting now!";
		exit(-1);
	}
	   
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmailAddress, int sAge, int sD1, int sD2, int sD3, Degree sD)
{
	Student* student = nullptr;
	int studentDays[NUM_DAYS_COURSE];
	studentDays[0] = sD1;
	studentDays[1] = sD2;
	studentDays[2] = sD3;

	if (lastIndex < (capacity - 1))
	{
		lastIndex++;

		if (sD == SECURITY)
			classRosterArray[lastIndex] = new SecurityStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, studentDays, sD);
		else if (sD == NETWORKING)
			classRosterArray[lastIndex] = new NetworkingStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, studentDays, sD);
		else if (sD == SOFTWARE)
		{
			classRosterArray[lastIndex] = new SoftwareStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, studentDays, sD);
		}
		else
			lastIndex--;
	}
}

void Roster::print_All()
{
	for (int i = 0; i <= lastIndex; i++) {
		((Student*)classRosterArray[i])->print();
	}
}

bool Roster::remove(string sID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == sID)
		{
			found = true;
			delete this->classRosterArray[i];
			for (int j = i; j < lastIndex; j++)
				classRosterArray[j] = classRosterArray[j + 1];
			classRosterArray[lastIndex] = nullptr;
			lastIndex--;
			break;
		}
	}
	return found;
}

void Roster::printAverageDays(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* d = classRosterArray[i]->getDays();
			double avg = ((double)(d[0] + d[1] + d[2])) / 3.0;
			cout << "Average days in course for " << studentID << " is " << avg << endl;
			break;
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:\n";
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		//any = false;
		Student* student = classRosterArray[i];

		if (!isValidEmail(student->getEmailAddress())) {
			cout << student->getStudentID() << " " << student->getEmailAddress() << endl;
			any = true;
		}

	}
	if (!any) cout << "NONE";
}

void Roster::printByDegreeType(Degree s)
{
	cout << "Printing by degrees of type " << degreeTypeStrings[s] << "\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getDegreeType() == s) this->classRosterArray[i]->print();
	}
	cout << endl;
}

int Roster::size() {
	return lastIndex + 1;
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

int main()
{
	
	cout << "Course title:  C867 Scripting and Programming - Applications" << endl;
	cout << "Programming language used:  C++" << endl;
	cout << "Student ID:  #001246977" << endl;
	cout << "Student name:  John Davis" << endl << endl;
	
	string studentData[MAX_STUDENT_CAPACITY] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,John,Davis,jda1128@wgu.edu,38,50,58,40,SOFTWARE"
	};

	Roster* Ros = new Roster(MAX_STUDENT_CAPACITY);
	cout << "Parsing data and adding students:\t";
	for (int i = 0; i < MAX_STUDENT_CAPACITY; i++)
	{
		Ros->parseThenAdd(studentData[i]);
	}
	cout << "DONE.\n";
	Ros->print_All();
	cout << endl;

	cout << "Removing A3:\n";
	if (Ros->remove("A3"))
	{
		Ros->print_All();
		
	}
	else cout << "Student not found!\n";
	cout << endl;

	cout << "Removing A3:\n";
	if (Ros->remove("A3")) Ros->print_All();
	else cout << "Student not found!\n";
	cout << endl;

	cout << "Printing average days for all courses:\n";
	for (int i = 0; i < Ros->size(); i++)
	{
		Ros->printAverageDays(Ros->getStudentAt(i)->getStudentID());
	}
	cout << endl;
	Ros->printInvalidEmails();
	cout << endl;

	for (int i = 0; i < 3; i++) 
		Ros->printByDegreeType((Degree)i);
	
	system("pause");
	return 0;
}

bool isValidEmail(string email) {
	bool result = true;
	int pos = email.find('@');

	if (pos == string::npos)
		result = false;
	else if (email.substr(pos, email.size()).find('.') == string::npos)
		result = false;
	else if (email.find(' ') != string::npos)
		result = false;
	else if (email.find('\t') != string::npos)
		result = false;
	
	return result;
}
