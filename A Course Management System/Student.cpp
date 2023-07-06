#include "Header.h"


//void inDate(Date& a) {
//	cout << "Input day: "; cin >> a.dd;
//	cout << "Input month: "; cin >> a.mm;
//	cout << "Input year: "; cin >> a.yy;
//}

Student inStudent() {
	Student a;
	cout << "Input StudentID: ";
	getline(cin, a.StudentID);
	/*cout << "Input FullName: ";
	getline(cin, a.FullName);
	int pos = a.FullName.find(' '); 
	a.FirstName = a.FullName.substr(0, pos);
	a.LastName = a.FullName.substr(pos + 1);*/
	cout << "Input First Name: ";
	getline(cin, a.FirstName);
	cout << "Input Last Name: ";
	getline(cin, a.LastName);
	cout << "Input Gender: ";
	getline(cin, a.Gender);
	cout << "Input DateOfBirth: ";
	getline(cin, a.DateOfBirth);
	cout << "Input SocialID: ";
	getline(cin, a.SocialID);
	return a;
}

void outStudent(Student a) {
	cout << a.No << "\t" << a.SocialID << "\t" << a.FirstName << "\t" << a.FullName << "\t" << a.Gender << "\t" << a.DateOfBirth << "\t" << a.SocialID << endl;
}
//
//void inStudentToFile(fstream& File, Student a) {
//	File << a.StudentID <<','<< a.FirstName << ',' << a.LastName << ',' << a.Gender << ',' << a.DateOfBirth << ',' << a.SocialID << '\n';
//}

void viewCourseListStudent(Student a) {
	string SchoolYear; 
	cout << "Input school year: ";
	getline(cin, SchoolYear);
	string CurrentPath = getCurrentPath();
	string MainPath = CurrentPath + "\\SchoolYear\\" + SchoolYear;
	SetCurrentDirectoryA(MainPath.c_str());
	string Semester;
	cout << "Input semester: ";
	getline(cin, Semester);
	List CourseIDList;
	initList(CourseIDList);
	getCourseList(Semester, CourseIDList);
	List CourseStudent;
	initList(CourseStudent);

	Node* i = CourseIDList.pHead;
	string Path = "Semester\\" + Semester + "\\";
	do {
		string CoursePath = Path + i->info + ".csv";
		ifstream CourseFile(CoursePath, ios::in);
		string temp;
		while (getline(CourseFile, temp)) {
			if (getID(temp) == a.StudentID) {
				addTail(CourseStudent, i);
			}
		}
		CourseFile.close();
		i = i->pNext;
	} while (i != NULL);
	string newPath = "Semester\\" + Semester + "\\" + Semester + ".csv";
	Node* newi = CourseStudent.pHead;
	string temp;
	do {
		ifstream SemesterFile(newPath, ios::in);
		while (getline(SemesterFile, temp)) {
			if (getNo(temp) ==newi->info) {
				newi->info = temp;
			}
		}
		SemesterFile.close();
		newi = newi->pNext;
	} while (newi != NULL);
	for (newi = CourseStudent.pHead; newi != NULL; newi = newi->pNext) {
		tString(newi->info);
	}
	outList(CourseStudent);
	SetCurrentDirectoryA(CurrentPath.c_str());
}

void viewScoreBoardStudent(Student a) {
	string SchoolYear;
	cout << "Input school year: ";
	getline(cin, SchoolYear);
	string CurrentPath = getCurrentPath();
	string MainPath = CurrentPath + "\\SchoolYear\\" + SchoolYear;
	SetCurrentDirectoryA(MainPath.c_str());

	string Semester;
	cout << "Input semester: ";
	getline(cin, Semester);

	List CourseIDList;
	initList(CourseIDList);
	getCourse(Semester, CourseIDList);
	
	List CourseStudent;
	initList(CourseStudent);

	Node* i = CourseIDList.pHead;
	string Path = "Semester\\" + Semester + "\\Scoreboard\\";
	do {
		string CoursePath = Path + getNo(i->info) + ".csv";
		ifstream CourseFile(CoursePath, ios::in);
		string temp;
		while (getline(CourseFile, temp)) {
			if (getID(temp) == a.StudentID) {
				int prevTotal = temp.find(',', temp.find(',', temp.find(',', temp.find(',') + 1) + 1) + 1);
				int nextTotal = temp.length();
				string buffer = temp.substr(prevTotal + 1, nextTotal - prevTotal - 1);
				i->info += buffer + '\n';
			}
		}
		CourseFile.close();
		i = i->pNext;
	} while (i != NULL);

	for (i = CourseIDList.pHead; i != NULL; i = i->pNext) {
		tString(i->info);
	}

	outList(CourseIDList);
	SetCurrentDirectoryA(CurrentPath.c_str());
	system("pause");
}

void getCourse(string Semester, List& CourseList) {
	ifstream SemesterFile;
	string Path = "Semester\\" + Semester + "\\" + Semester + ".csv";
	SemesterFile.open(Path, ios::in);
	if (!SemesterFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(SemesterFile, temp)) {
		Node* buffer = createNode(temp);
		addTail(CourseList, buffer);
	}

	SemesterFile.close();
}