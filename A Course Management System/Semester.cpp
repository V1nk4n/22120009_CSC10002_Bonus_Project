#include "Header.h"

void createSemester() {
	system("cls");
	Semester a;
	cout << "Input Semester: "; cin.ignore(); getline(cin, a.Semester);
	cout << "Input StartDate: "; cin.ignore(); getline(cin, a.StartDate);
	cout << "Input EndDate: "; cin.ignore(); getline(cin, a.EndDate);
	string SemesterPath = getCurrentPath() + "\\Semester";
	SetCurrentDirectoryA(SemesterPath.c_str());
	ofstream SemesterFile("Semester.csv",ios::out|ios::app);
	if (!SemesterFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	SemesterFile << a.Semester << '\,' << a.StartDate << '\,' << a.EndDate << '\n';
	SemesterFile.close();
	createFolder(SemesterPath, a.Semester);
	ofstream File(SemesterPath + ".csv", ios_base::out);
	if (!File) {
		cout << "Error opening file." << endl;
	}
	File << "CourseID" << '\,' << "CourseName" << '\,' << "ClassName" << '\,' << "TeacherName" << '\,' << "NumOfCredits" << '\,' << "MaxNumOfStudents" << '\,' << "Session" << '\,' << "DayOfWeek" << '\n';
	File.close();

	string ScoreBoardName = a.Semester + "\\ScoreBoard";
	_mkdir(ScoreBoardName.c_str());
	SetCurrentDirectoryA("..");
}

void chooseSemester(string& Semester) {
	system("cls");

	string ClassPath = getCurrentPath() + "\\Semester";

	if (SetCurrentDirectoryA(ClassPath.c_str()) == 0)
		cout << "Failed" << endl;
	cout << "SEMESTER" << endl;

	List SemesterList;
	initList(SemesterList);

	getSemesterList(SemesterList);
	outList(SemesterList);

	do {
		cout << "Input Semester: ";
		cin.ignore();
		getline(cin, Semester);
	} while (!checkList(SemesterList, Semester));

	SetCurrentDirectoryA("..");
}

void getSemesterList(List& SemesterList){
	ifstream SemesterFile;
	SemesterFile.open("Semester.csv", ios::in);
	if (!SemesterFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(SemesterFile, temp,',')) {
		Node* buffer = createNode(temp);
		addTail(SemesterList, buffer);
		getline(SemesterFile, temp);
	}

	SemesterFile.close();
}
