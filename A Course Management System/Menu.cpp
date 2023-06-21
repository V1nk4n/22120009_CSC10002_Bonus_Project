#include "Header.h";


void SystemLogInMenu() {
	int op{};
	do {
		cout << "0. End" << endl;
		cout << "1. Log in" << endl;
		cout << "2. Sign up" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 1:
			system("cls");
			UserMenu();
			break;
		case 2:

			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void UserMenu() {
	system("cls");
	int op{};
	do {
		cout << "1. View profile" << endl;
		cout << "2. Change password" << endl;
		cout << "3. Log out" << endl;
		cout << "4. WorkSpace" << endl;
		cout << "Enter your option: ";
		cin >> op;
		system("cls");
		switch (op) {
		case 1:
			//View profile
			break;
		case 2:
			//Change password (xoa 1 hang trong file r ghi lai)
			break;
		case 3:
			SystemLogInMenu();
			break;
		case 4:
			StaffMenu();
			//Neu la Student vao StudentMenu
			break;
		}
		system("pause");
		system("cls");
	} while (1);
}

void StaffMenu() {
	system("cls");
	string CurrentPath = getCurrentPath();
	CurrentPath += "\\SchoolYear";
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;
	else
		cout << "Successful" << endl;

	int op{};
	do {
		cout << "School Year Menu" << endl;
		cout << "0. Back" << endl;
		cout << "1. Create a school year" << endl;
		cout << "2. Choose a school year" << endl;
		cout << "Enter your option: ";
		cin >> op;
		system("cls");
		switch (op) {
		case 0:
			SetCurrentDirectoryA("..");
			UserMenu();
			break;
		case 1:
			createSchoolYear();
			break;
		case 2:	
			string SchoolYear;
			chooseSchoolYear(SchoolYear);
			SchoolYearMenu(SchoolYear);
			break;
		}
		system("pause");
		system("cls");
	} while (op!=0);
}

void SchoolYearMenu(string SchoolYear) {
	system("cls");

	string CurrentPath = getCurrentPath();
	CurrentPath += "\\"+SchoolYear;
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;
	else
		cout << "Successful" << endl;

	int op{};
	do {
		cout << "School Year " << SchoolYear << endl;
		cout << "0. Back" << endl;
		cout << "1. Create a class" << endl;
		cout << "2. View the list of classes and choose a class" << endl;
		cout << "3. Create a semester" << endl;
		cout << "4. View the list of semesters and choose a semester" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			SetCurrentDirectoryA("..");
			StaffMenu();
			break;
		case 1:
			createClass();
			break;
		case 2: {
			string Class;
			chooseClass(Class);
			ClassMenu(Class);
			break;
		}
		case 3:
			createSemester();
			break;
		case 4: 
			string Semester;
			chooseSemester(Semester);
			SemesterMenu(Semester);
			break;
		}
		system("pause");
		system("cls");
		
	} while (1);
	
}

void ClassMenu(string Class) {
	system("cls");

	string CurrentPath = getCurrentPath()+ "\\Class";
	
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;
	else
		cout << "Successful" << endl;

	int op{};
	do {
		system("cls");
		cout << Class << endl;
		cout << "0. Back" << endl;
		cout << "1. Import the student list" << endl;
		cout << "2. Add new 1st student to a class" << endl;
		cout << "3. View the list of students in the class" << endl;
		cout << "4. Remove a student from a course" << endl;
		cout << "5. View the scoreboard of the class" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			break;
		case 1: {
			string SourcePath;
			string SourceDes = Class + ".csv";
			importList(SourcePath, SourceDes);
			break;
		}
		case 2:
			addStudentToClass(Class);
			break;
		case 3:
			viewClass(Class);
			system("pause");
			break;
		}
		
		
		
		
	} while (1);
}

void SemesterMenu(string Semester) {

	string CurrentPath = getCurrentPath();
	CurrentPath += "\\Semester\\" + Semester;
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;
	else
		cout << "Successful" << endl;

	int op{};
	do {
		system("cls");
		cout << "Semester " << Semester << endl;
		cout << "0. Back" << endl;
		cout << "1. Create a course" << endl;
		cout << "2. View the list of courses" << endl;
		cout << "3. Import the student list" << endl;
		cout << "4. Add a student to a course" << endl;
		cout << "5. View the list of students in a course" << endl;
		cout << "6. Update course information" << endl;
		cout << "7. Delete a course" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			break;
		case 1:
			createCourse(Semester);
			break;
		case 2: {
			Course a;
			getCourseList(a, Semester);
			outCourse(a);
			system("pause");
			break;
		}
		case 3:
			break;
		}
	} while (1);
}

void StudentMenu() {
	system("cls");
	int op{};
	do {
		cout << "0. Back" << endl;
		cout << "1. View the list of courses" << endl;
		cout << "2. View the scoreboard" << endl;
		cout << "Enter your option: ";
		switch (op) {
		case 0:
			UserMenu();
			break;
		case 1:

			break;
		case 2:

			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

string getCurrentPath() {
	char cwd[MAX_PATH];

	GetCurrentDirectoryA(sizeof(cwd), cwd);

	string CurrentPath(cwd);
	
	return CurrentPath;
}

int main() {
	cout << setw(20);
	StaffMenu();
	return 0;
}