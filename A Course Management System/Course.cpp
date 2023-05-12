#include "Header.h"

Course inCourse() {
	Course a;
	cout << "Input CourseID: ";
	getline(cin, a.CourseID);
	cout << "Input CourseName: ";
	getline(cin, a.CourseName);
	cout << "Input ClassName: ";
	getline(cin, a.ClassName);
	cout << "Input TeacherName: ";
	getline(cin, a.TeacherName);
	cout << "Input NumOfCredits: ";
	getline(cin, a.NumOfCredits);
	cout << "Input Session: ";
	getline(cin, a.Session);
	cout << "Input Infomation: ";
	getline(cin, a.Info);
	return a;
}

void addCourseToSemester(string SemesterPath, Course a) {
	fstream SemesterFile(SemesterPath + ".csv", ios_base::app);
	SemesterFile << a.CourseID << ',' << a.ClassName << ',' << a.ClassName << ',' << a.TeacherName << ',' << a.NumOfCredits << ',' << a.Session << ','<<a.Info<<'\n';
	SemesterFile.close();
	string CoursePath = SemesterPath + '\\' + a.CourseID;
	createFolder(CoursePath, a.CourseID);
}

void addCourseToSemester(string SemesterPath) {
	Course a = inCourse();
	addCourseToSemester(SemesterPath, a);
}

void addStudentToCourse(string CoursePath, Student a) {
	fstream CourseFile(CoursePath + ".csv", ios_base::app);
	//Ghi NO cua student
	inStudentToFile(CourseFile, a);
	CourseFile.close();
}

void removeStudentFromCourse(string CoursePath, Student a) {

}



void outCourse(Course a) {
	
}
//void viewCourse(string SemesterPath) {
//	List CourseList{};
//	string line;
//	fstream SemesterFile(SemesterPath + ".csv", ios_base::in);
//	while (!SemesterFile.eof()) {
//		getline(SemesterFile, line);
//		line += '\n';
//		addTail(CourseList, createNode(line));
//	}
//	SemesterFile.close();
//	outList(CourseList);
//}