#include "Header.h"

Course inCourse() {
	Course a;
	cin.ignore();
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
	cout << "Input MaxNumOfStudents: ";
	getline(cin, a.MaxNumofStudents);
	cout << "Input Session: ";
	getline(cin, a.Session);
	cout << "Input Day Of Week: ";
	getline(cin, a.DayOfWeek);
	return a;
}

void outCourse(Course a) {
	cout << a.CourseID << "\t" << a.CourseName << "\t" << a.ClassName << "\t" << a.TeacherName << "\t" << a.NumOfCredits << "\t" << a.MaxNumofStudents << "\t" << a.Session << "\t" << a.DayOfWeek << endl;
}

void createCourse(string Semester) {
	system("cls");
	Course a = inCourse();
	ofstream SemesterFile(Semester+".csv", ios_base::app);
	SemesterFile << a.CourseID << '\,' << a.CourseName << '\,' << a.ClassName << '\,' << a.TeacherName << '\,' << a.NumOfCredits << '\,' << a.MaxNumofStudents << '\,' << a.Session << '\,' << a.DayOfWeek << '\n';
	SemesterFile.close();
}

//void getCourseList(CourseList& CourseList) {
void getCourseList(Course& temp, string Semester){

	ifstream CourseFile;
	CourseFile.open(Semester+".csv", ios::in);
	if (!CourseFile.is_open()) {
		return;
	}

	/*Course temp;*/
	
	getline(CourseFile, temp.CourseID, ',');
	getline(CourseFile, temp.CourseName, ',');
	getline(CourseFile, temp.ClassName, ',');
	getline(CourseFile, temp.TeacherName, ',');
	getline(CourseFile, temp.NumOfCredits, ',');
	getline(CourseFile, temp.MaxNumofStudents, ',');
	getline(CourseFile, temp.Session, ',');
	getline(CourseFile, temp.DayOfWeek, '\n');

	CourseFile.close();
}


void addStudentToCourse(string CoursePath, Student a) {
	fstream CourseFile(CoursePath + ".csv", ios_base::app);
	//Ghi NO cua student
	//inStudentToFile(CourseFile, a);
	CourseFile.close();
}

void removeStudentFromCourse(string CoursePath, Student a) {

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