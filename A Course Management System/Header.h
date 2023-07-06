#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <direct.h> //Tao folder mkdir(ten folder)
#include "Menu.h"
#include "iomanip"
#include <Windows.h>
#include <filesystem>
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
struct Person {
	string ID; //how about int?
	string FirstName;
	string LastName;
	string Gender;
	string DateOfBirth;
	string SocialID; //how about int?
};
struct Course {
	string CourseID;
	string CourseName;
	string ClassName;
	string TeacherName;
	string	NumOfCredits;
	string MaxNumOfStudents; //50
	string Session;
	string DayOfWeek;
};
struct Account {
	string UserName;
	string Password;
	string Title;
	Person Staff;
	Student Student;
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


const string CODE = "1412";


void StaffOrStudent();
void StaffLogin(Account& a);
void StaffLogSign();
void StudentLogSign();
void StaffMenu();
void SchoolYearMenu();
void StudentMenu();
void StudentLogin(Account& a);
void StaffSignUp();
void viewStaffProfile(Account& a);
void readStaffAccount(Account& a, string temp);
int getToken(string& token, string s, int& startPos);
void changeStaffProfile(Account& a, int NumLines);
void updateProfile(Account& a);
void displayProfile(Account a);
void StudentSignUp();
void viewStudentProfile(Account& a);
void readStudentAccount(Account& a, string temp);
void changeStudentProfile(Account& a, int NumLines);
void updateStudentProfile(Account& a);
void displayStudentProfile(Account a);

Student inStudent();
void outStudent(Student a);

void tString(string& Str);
void nString(string& Str);

void copyFile(ifstream& File1, ofstream& File2);
int checkList(List lst, string des);
void importList(string SourcePath, string DesPath);
int checkFile(string FileName);
void createFile(string FileName);
void createFolder(string& Path, string Name);
void inStudentToFile(fstream& File, Student a);
void viewFile(string FileName);

string getID(string Data);
string getNo(string Data);
double getTotalMark(string Data);

void initList(List& lst);
Node* createNode(string data);
void addTail(List& lst, Node* p);
void outList(List lst);

int getNOofFile(ifstream& File);

void createSchoolYear();

void StaffMenu();
void Class_SemesterMenu(string SchoolYear);
void ClassMenu(string SchoolYear, string Class);
void SemesterMenu(string SchoolYear, string Semester);

string getCurrentPath();

void getSchoolYearList(List& SchoolYearList);
void chooseSchoolYear(string& SchoolYear);

void createClass();
void chooseClass(string& Class);
void getClassList(List& ClassList);
void viewClassList(string Class);
void viewScoreBoardClass(string Class, int NumLines);

void addStudentToClass(string Class);

void createSemester();
void chooseSemester(string& Semester);
void getSemesterList(List& SemesterList);

void createCourse(string Semester);
void outCourse(Course a);
void viewCourseList(string Semester);
void addStudentToCourse(string CourseID);
void removeStudentFromCourse(string CourseID, string StudentID, int NumLines);
void updateCourse(string Semester, string CourseID, int NumLines);
void deleteCourse(string SemesterFileName, string CourseID, int NumLines);
void getMarkCourse(string StudentID, double& Mark, int& nMark, string Semester);
void getCourseList(string Semester, List& CourseList);
void getCourse(string Semester, List& CourseList);
void viewCourseListStudent(Student a);
void viewScoreBoardStudent(Student a);

void im_exFile(string LinkIm, string LinkEx);
void updateStudentScore(string CourseID, string StudentID, int NumLines);

void viewStaffProfile(Account a, ifstream& AccountFile);