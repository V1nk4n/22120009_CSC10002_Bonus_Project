#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <direct.h> //Tao folder mkdir(ten folder)
using namespace std;

struct Date {
	int dd;
	int mm;
	int yy;
};
struct Student {
	string StudentID; //how about int?
	string FirstName;
	string LastName;
	string FullName;
	string Gender;
	string DateOfBirth;
	string SocialID; //how about int?
	string StudentYear;
	string StudentClass;
};
struct Course {
	string CourseID;
	string CourseName;
	string ClassName;
	string TeacherName;
	string	NumOfCredits;
	string MaxNumofStudents; //50
	string Session;
	string Info;
};
struct Account {
	string UserName;
	string Password;
	string Title;
};

struct Semester {
	string Semester;
	string SchoolYear;
	string StartDate;
	string EndDate;
};

//struct Data {
//	Student Student;
//	Course Course;
//	string Class;
//};

struct Node {
	string info;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};



int checkFile(string FileName);
fstream createFile(string FileName);
void createFolder(string& Path, string Name);
void inStudentToFile(fstream& File, Student a);
Node* createNode(string data);
void addTail(List& lst, Node* p);
void outList(List lst);
int getNOofFile(fstream& File);