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

void addStudentToClass(string ClassPath, Student a) {
	if (a.StudentYear == "1st") {
		fstream ClassFile(ClassPath + ".csv", ios_base::app);

		int NO = getNOofFile(ClassFile);
		ClassFile << NO << ',';
		//inStudentToFile(ClassFile, a);

		ClassFile.close();
	}
}

//void viewClass(string ClassPath) {
//	List ClassList{};
//	string line;
//	fstream ClassFile(ClassPath+".csv", ios_base::in);
//	if (!ClassFile.is_open()) {
//		while (!ClassFile.eof()) {
//			getline(ClassFile, line);
//			line += '\n';
//			addTail(ClassList, createNode(line));
//		}
//	}
//}
