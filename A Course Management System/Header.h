#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <direct.h> //Tao folder mkdir(ten folder)
#include "Menu.h"
#include "iomanip"
#include <Windows.h>
using namespace std;

struct Date {
	int dd;
	int mm;
	int yy;
};
struct Student {
	string No;
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
	string DayOfWeek;
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

struct CourseNode {
	Course a;
	CourseNode* pNext;
};

struct CourseList {
	CourseNode* pHead;
	CourseNode* pTail;
};

Student inStudent();
void outStudent(Student a);

void tokStr(string& Str);

int checkList(List lst, string des);
void importList(string SourcePath, string DesPath);
int checkFile(string FileName);
void createFile(string FileName);
void createFolder(string& Path, string Name);
void inStudentToFile(fstream& File, Student a);

void initList(List& lst);
Node* createNode(string data);
void addTail(List& lst, Node* p);
void outList(List lst);

int getNOofFile(ifstream& File);

void createSchoolYear();

void UserMenu();
void SchoolYearMenu(string SchoolYear);
void ClassMenu(string Class);
void SemesterMenu(string Semester);

string getCurrentPath();

void getSchoolYearList(List& SchoolYearList);
void chooseSchoolYear(string& SchoolYear);

void createClass();
void chooseClass(string& Class);
void getClassList(List& ClassList);
void viewClass(string Class);

void addStudentToClass(string Class);

void createSemester();
void chooseSemester(string& Semester);
void getSemesterList(List& SemesterList);

void createCourse(string Semester);
void outCourse(Course a);
void getCourseList(Course& temp, string Semester);

