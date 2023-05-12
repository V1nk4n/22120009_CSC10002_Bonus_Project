#include "Header.h"

void createClass(string SchoolYearPath, string SchoolYearName) {
	//Nhap ten lop
	string ClassName;
	cout << "Input Class: ";
	getline(cin, ClassName);

	//Kiem tra da co lop hoc chua neu chua thi tao file moi
	
	if (!checkFile(SchoolYearPath)) {
		fstream SchoolYearFile(SchoolYearPath + '\\'+ SchoolYearName + ".csv", ios_base::app);
		SchoolYearFile << ClassName << '\n';
		SchoolYearFile.close();

		SchoolYearPath += '\\' + ClassName;
		createFile(SchoolYearPath);
	}
}

void addStudentToClass(string ClassPath, Student a) {
	if (a.StudentYear == "1st") {
		fstream ClassFile(ClassPath + ".csv", ios_base::app);

		int NO = getNOofFile(ClassFile);
		ClassFile << NO << ',';
		inStudentToFile(ClassFile, a);

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
