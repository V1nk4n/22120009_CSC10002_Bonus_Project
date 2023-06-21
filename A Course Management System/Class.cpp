#include "Header.h"

void createClass() {
	system("cls");
	//Nhap ten lop
	string ClassName;
	cout << "Input Class: ";
	cin.ignore();
	getline(cin, ClassName);

	string ClassPath = getCurrentPath() + "\\Class";
	SetCurrentDirectoryA(ClassPath.c_str());

	//Kiem tra da co lop hoc chua neu chua thi tao file moi

	if (!checkFile(ClassPath)) {
		fstream SchoolYearFile("Class.csv", ios_base::app);
		SchoolYearFile << ClassName << '\n';
		SchoolYearFile.close();

		ClassPath += '\\' + ClassName;
		createFile(ClassPath);
	}

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
	int No = getNOofFile(ClassIFile);
	ClassIFile.close();
	
	Student a = inStudent();
	
	a.No = to_string(No);
	ofstream ClassOFile(Class, ios::app);
	ClassOFile << a.No << '\,' << a.StudentID << '\,' << a.FirstName << '\,' << a.LastName << '\,' << a.Gender << '\,' << a.DateOfBirth << '\,' << a.SocialID << '\n';
	ClassOFile.close();
}



void viewClass(string Class) {
	ifstream ClassXFile;
	Class += ".csv";
	ClassXFile.open(Class, ios::in);
	if (!ClassXFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(ClassXFile, temp)) {
		tokStr(temp);
		cout << temp<<endl;
	}

	ClassXFile.close();
}
