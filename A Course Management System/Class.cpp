#include "Header.h"

void createClass() {
	system("cls");
	string ClassName;
	cout << "Input Class: ";
	cin.ignore();
	getline(cin, ClassName);
	string ClassPath = getCurrentPath() + "\\Class";
	SetCurrentDirectoryA(ClassPath.c_str());
	if (!checkFile(ClassPath)) {
		fstream SchoolYearFile("Class.csv", ios_base::app);
		SchoolYearFile << ClassName << '\n';
		SchoolYearFile.close();

		createFile(ClassName);
	}
	ofstream ClassFile(ClassName + ".csv", ios::out);
	ClassFile << "No" << '\,' << "StudentID" << '\,' << "FirstName" << '\,' << "LastName" << '\,' << "Gender" << '\,' << "DayOfBirth" << '\,' << "SocialID" << '\,' << "TotalMark" << '\n';
	ClassFile.close();
	SetCurrentDirectoryA("..");
}

void chooseClass(string& Class) {
	system("cls");

	string ClassPath = getCurrentPath() + "\\Class";
	
	if (SetCurrentDirectoryA(ClassPath.c_str()) == 0)
		cout << "Failed" << endl;
	else
		cout << "Successful" << endl;

	List ClassList;
	initList(ClassList);

	getClassList(ClassList);
	outList(ClassList);

	do {
		cout << "Input class: ";
		cin.ignore();
		getline(cin, Class);
	} while (!checkList(ClassList, Class));

	SetCurrentDirectoryA("..");
}

void getClassList(List& ClassList) {
	ifstream ClassFile;
	ClassFile.open("Class.csv", ios::in);
	if (!ClassFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(ClassFile, temp)) {
		Node* buffer = createNode(temp);
		addTail(ClassList, buffer);
	}

	ClassFile.close();
}

void addStudentToClass(string Class) {
	system("cls");

	Class += ".csv";
	ifstream ClassIFile(Class, ios::in);
	int No = getNOofFile(ClassIFile)-1;
	ClassIFile.close();
	
	Student a = inStudent();
	
	a.No = to_string(No);
	ofstream ClassOFile(Class, ios::app);
	ClassOFile << a.No << '\,' << a.StudentID << '\,' << a.FirstName << '\,' << a.LastName << '\,' << a.Gender << '\,' << a.DateOfBirth << '\,' << a.SocialID << '\n';
	ClassOFile.close();
}

void viewClassList(string Class) {
	ifstream ClassXFile;
	Class += ".csv";
	ClassXFile.open(Class, ios::in);
	if (!ClassXFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(ClassXFile, temp)) {
		tString(temp);
		cout << temp<<endl;
	}

	ClassXFile.close();
}

void viewScoreBoardClass(string Class, int NumLines) {
	SetCurrentDirectoryA("..");
	string Semester;
	cout << "Input Semester: ";
	cin >> Semester;
	
	string temp;
	string* Lines = new string[NumLines];

	string ClassPath = "Class\\" + Class;
	ifstream ClassIFile(ClassPath, ios::in);
	int n = 0;
	while (getline(ClassIFile, temp)) {
		string StudentID = getID(temp);
		double Mark = 0;
		int nMark = 0;
		getMarkCourse(StudentID, Mark, nMark, Semester);
		if (nMark == 0) {
			Mark = 0;
		}
		else
			Mark = Mark / (double)nMark;
		temp +='\,' + to_string(Mark);
		Lines[n++] = temp;
	}
	ClassIFile.close();

	ofstream ClassOFile(ClassPath, ios::out);
	int t = 0;
	while (t < n) {
		Lines[t] += '\n';
		ClassOFile << Lines[t++];
	}
	delete[] Lines;
	ClassOFile.close();

	string newPath = getCurrentPath() + "\\Class";
	SetCurrentDirectoryA(newPath.c_str());
}

void getMarkCourse(string StudentID, double& Mark, int& nMark, string Semester) {

	List CourseList{};
	initList(CourseList);
	getCourseList(Semester, CourseList);

	Node* i = CourseList.pHead;
	string Path = "Semester\\" + Semester + "\\Scoreboard\\";
	do {
		string CoursePath = Path + i->info + ".csv";
		ifstream CourseFile(CoursePath, ios::in);
		string temp;
		while (getline(CourseFile, temp)) {
			if (getID(temp) == StudentID) {
				Mark += getTotalMark(temp);
				nMark++;
			}
		}
		CourseFile.close();
		i = i->pNext;
	} while (i != NULL);
}

double getTotalMark(string Data) {
	int prevTotal = Data.find(',', Data.find(',', Data.find(',', Data.find(',') + 1) + 1) + 1);
	int nextTotal = Data.find(',', Data.find(',', Data.find(',', Data.find(',', Data.find(',') + 1) + 1) + 1) + 1);
	string temp = Data.substr(prevTotal+1, nextTotal-prevTotal-1);
	double x = atof(temp.c_str());
	return x;
}
void getCourseList(string Semester, List& CourseList) {
	ifstream SemesterFile;
	string Path = "Semester\\" + Semester + "\\" + Semester + ".csv";
	SemesterFile.open(Path, ios::in);
	if (!SemesterFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	string temp;
	while (getline(SemesterFile, temp, ',')) {
		temp = getNo(temp);
		Node* buffer = createNode(temp);
		addTail(CourseList, buffer);
		getline(SemesterFile, temp);
	}
	SemesterFile.close();
}