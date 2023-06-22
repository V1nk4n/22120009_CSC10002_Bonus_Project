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
	getline(cin, a.MaxNumOfStudents);
	cout << "Input Session: ";
	getline(cin, a.Session);
	cout << "Input Day Of Week: ";
	getline(cin, a.DayOfWeek);
	return a;
}

void outCourse(Course a) {
	cout << a.CourseID << "\t" << a.CourseName << "\t" << a.ClassName << "\t" << a.TeacherName << "\t" << a.NumOfCredits << "\t" << a.MaxNumOfStudents << "\t" << a.Session << "\t" << a.DayOfWeek << endl;
}

void createCourse(string Semester) {
	system("cls");
	Course a = inCourse();
	ofstream SemesterFile(Semester+".csv", ios_base::app);
	SemesterFile << a.CourseID << '\,' << a.CourseName << '\,' << a.ClassName << '\,' << a.TeacherName << '\,' << a.NumOfCredits << '\,' << a.MaxNumOfStudents << '\,' << a.Session << '\,' << a.DayOfWeek << '\n';
	SemesterFile.close();

	ofstream CourseFile(a.CourseID + ".csv", ios::out);
	CourseFile << "No" << '\,' << "StudentID" << '\,' << "FirstName" << '\,' << "LastName" << '\,' << "Gender" << '\,' << "DayOfBirth" << '\,' << "SocialID" << '\n';
	CourseFile.close();
}

//void getCourseList(CourseList& CourseList) {
//void viewCourseList(Course& temp, string Semester){
//
//	ifstream CourseFile;
//	CourseFile.open(Semester+".csv", ios::in);
//	if (!CourseFile.is_open()) {
//		return;
//	}
//
//	/*Course temp;*/
//	
//	getline(CourseFile, temp.CourseID, ',');
//	getline(CourseFile, temp.CourseName, ',');
//	getline(CourseFile, temp.ClassName, ',');
//	getline(CourseFile, temp.TeacherName, ',');
//	getline(CourseFile, temp.NumOfCredits, ',');
//	getline(CourseFile, temp.MaxNumofStudents, ',');
//	getline(CourseFile, temp.Session, ',');
//	getline(CourseFile, temp.DayOfWeek, '\n');
//
//	CourseFile.close();
//}

void viewCourseList(string Semester) {
	ifstream CourseFile;
	Semester += ".csv";
	CourseFile.open(Semester, ios::in);
	if (!CourseFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(CourseFile, temp)) {
		tokStr(temp);
		cout << temp << endl;
	}

	CourseFile.close();
}


void addStudentToCourse(string CourseID) {
	system("cls");

	CourseID += ".csv";
	ifstream CourseIFile(CourseID, ios::in);
	int No = getNOofFile(CourseIFile);
	CourseIFile.close();

	Student a = inStudent();

	a.No = to_string(No);
	ofstream CourseOFile(CourseID, ios::app);
	CourseOFile << a.No << '\,' << a.StudentID << '\,' << a.FirstName << '\,' << a.LastName << '\,' << a.Gender << '\,' << a.DateOfBirth << '\,' << a.SocialID << '\n';
	CourseOFile.close();
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