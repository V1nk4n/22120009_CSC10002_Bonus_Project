#include "Header.h";
Account acc;

void StaffOrStudent() {
	system("cls");
	int op{};
	do {
		cout << "STAFF OR STUDENT" << endl;
		cout << "0. End" << endl;
		cout << "1. Staff" << endl;
		cout << "2. Student" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			return;
		case 1:
			StaffLogSign();
			break;
		case 2:
			StudentLogSign();
			break;
		}
		system("pause");
		system("cls");
	} while (1);
}

void StaffLogSign() {
	system("cls");
	int op{};
	do {
		cout << "STAFF LOG SIGN" << endl;
		cout << "0. Back" << endl;
		cout << "1. Log in" << endl;
		cout << "2. Sign up" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			StaffOrStudent();
			break;
		case 1:
			system("cls");
			StaffLogin(acc);
			StaffMenu();
			break;
		case 2:
			system("cls");
			StaffSignUp();
			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void StaffMenu() {
	system("cls");
	int op{};
	do {
		
		cout << "STAFF MENU" << endl;
		cout << "0. Back" << endl;
		cout << "1. View profile" << endl;
		cout << "2. Change profile" << endl;
		cout << "3. Log out" << endl;
		cout << "4. WorkSpace" << endl;
		cout << "Enter your option: ";
		cin >> op;
		system("cls");
		switch (op) {
		case 0:
			StaffLogSign();
			break;
		case 1: {
			viewStaffProfile(acc);
			break;
		}
		case 2: {
			ifstream AccountFile("SystemLogin.csv", ios::in);
			int NumLines = getNOofFile(AccountFile);
			AccountFile.close();
			changeStaffProfile(acc, NumLines);
			break;
		}
		case 3:
			StaffLogSign();
			break;
		case 4:
			SchoolYearMenu();
			break;
		}
		system("pause");
		system("cls");
	} while (1);
}


void StudentLogSign() {
	system("cls");
	int op{};
	do {
		cout << "STUDENT LOG SIGN" << endl;
		cout << "0. Back" << endl;
		cout << "1. Log in" << endl;
		cout << "2. Sign up" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			StaffOrStudent();
			break;
		case 1:
			system("cls");
			StudentLogin(acc);
			StudentMenu();
			break;
		case 2:
			StudentSignUp();
			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void StudentMenu() {
	system("cls");
	int op{};
	do {
		ifstream AccountFile("StudentAccount.csv", ios::in);
		string temp;
		while (getline(AccountFile, temp)) {
			if (getNo(temp) == acc.UserName) {
				readStudentAccount(acc, temp);
				break;
			}
		}
		AccountFile.close();
		cout << "STUDENT MENU" << endl;
		cout << "0. Back" << endl;
		cout << "1. View profile" << endl;
		cout << "2. Change profile" << endl;
		cout << "3. Log out" << endl;
		cout << "4. View the list of courses" << endl;
		cout << "5. View the scoreboard" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			StudentLogSign();
			break;
		case 1:
			viewStudentProfile(acc);
			break;
		case 2: {
			ifstream AccountFile("StudentAccount.csv", ios::in);
			int NumLines = getNOofFile(AccountFile);
			AccountFile.close();
			changeStudentProfile(acc, NumLines);
			break;
		}
		case 3:
			StudentLogSign();
			break;
		case 4:
			cin.ignore();
			viewCourseListStudent(acc.Student);
			break;
		case 5:
			cin.ignore();
			viewScoreBoardStudent(acc.Student);
			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void SchoolYearMenu() {
	system("cls");
	string CurrentPath = getCurrentPath();
	CurrentPath += "\\SchoolYear";
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;

	int op{};
	do {
		cout << "SCHOOL YEAR MENU" << endl;
		cout << "0. Back" << endl;
		cout << "1. Create a school year" << endl;
		cout << "2. Choose a school year" << endl;
		cout << "Enter your option: ";
		cin >> op;
		system("cls");
		switch (op) {
		case 0:
			SetCurrentDirectoryA("..");
			SetCurrentDirectoryA("..");
			StaffMenu();
			break;
		case 1:
			createSchoolYear();
			break;
		case 2:	
			string SchoolYear;
			chooseSchoolYear(SchoolYear);
			Class_SemesterMenu(SchoolYear);
			break;
		}
		system("pause");
		system("cls");
	} while (op!=0);
}

void Class_SemesterMenu(string SchoolYear) {
	system("cls");

	string CurrentPath = getCurrentPath();
	CurrentPath += "\\"+SchoolYear;
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;

	int op{};
	do {
		cout << "SCHOOL YEAR " << SchoolYear << endl;
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
			SetCurrentDirectoryA("..");
			SchoolYearMenu();
			break;
		case 1:
			createClass();
			break;
		case 2: {
			string Class;
			chooseClass(Class);
			ClassMenu(SchoolYear, Class);
			break;
		}
		case 3:
			createSemester();
			break;
		case 4: 
			string Semester;
			chooseSemester(Semester);
			SemesterMenu(SchoolYear, Semester);
			break;
		}
		system("pause");
		system("cls");
		
	} while (1);
	
}

void ClassMenu(string SchoolYear, string Class) {
	system("cls");

	string CurrentPath = getCurrentPath()+ "\\Class";
	
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;
	
	int op{};
	do {
		system("cls");
		cout << Class << endl;
		cout << "0. Back" << endl;
		cout << "1. Import the student list" << endl;
		cout << "2. Add new 1st student to a class" << endl;
		cout << "3. View the list of students in the class" << endl;
		cout << "4. View the scoreboard of the class" << endl;
		cout << "Enter your option: ";
		cin >> op;
		switch (op) {
		case 0:
			SetCurrentDirectoryA("..");
			SetCurrentDirectoryA("..");
			Class_SemesterMenu(SchoolYear);
			break;
		case 1: {
			string SourcePath;
			string DesPath = Class + ".csv";
			importList(SourcePath, DesPath);
			break;
		}
		case 2:
			cin.ignore();
			addStudentToClass(Class);
			break;
		case 3:
			viewFile(Class);
			system("pause");
			break;
		case 4: {
			ifstream ClassFile(Class + ".csv", ios::in);
			int NumLines = getNOofFile(ClassFile);
			ClassFile.close();
			string ClassPath = Class + ".csv";
			viewScoreBoardClass(ClassPath, NumLines);
			viewFile(Class);
			system("pause");
			break;
		}
		}
		
		
		
		
	} while (1);
}

void SemesterMenu(string SchoolYear, string Semester) {

	string CurrentPath = getCurrentPath();
	CurrentPath += "\\Semester\\" + Semester;
	if (SetCurrentDirectoryA(CurrentPath.c_str()) == 0)
		cout << "Failed" << endl;

	int op{};
	do {
		system("cls");
		cout << "SEMESTER " << Semester << endl;
		cout << "0. Back" << endl;
		cout << "1. Create a course" << endl;
		cout << "2. View the list of courses" << endl;
		cout << "3. Import the student list to a course" << endl;
		cout << "4. Add a student to a course" << endl;
		cout << "5. View the list of students in a course" << endl;
		cout << "6. Remove a student from a course" << endl;
		cout << "7. Update course information" << endl;
		cout << "8. Delete a course" << endl;
		cout << "9. Export a list of students in a course to a CSV file" << endl;
		cout << "10. Import the scoreboard of a course" << endl;
		cout << "11. View the scoreboard of a course" << endl;
		cout << "12. Update a student's result" << endl;
		cout << "Enter your option: ";
		cin >> op;
		system("cls");
		switch (op) {
		case 0:
			SetCurrentDirectoryA("..");
			SetCurrentDirectoryA("..");
			Class_SemesterMenu(SchoolYear);
			break;
		case 1:
			createCourse(Semester);
			break;
		case 2: {
			viewFile(Semester);
			system("pause");
			break;
		}
		case 3: {
			viewFile(Semester);
			string SourcePath;
			string DesPath;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, DesPath);
			DesPath += ".csv";
			importList(SourcePath, DesPath);
			break;
		}
		case 4: {
			
			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			CourseID += ".csv";
			addStudentToCourse(CourseID);
			break;
		}
		case 5: {

			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			viewFile(CourseID);
			system("pause");
			break;
		}
		case 6: {
			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			system("cls");

			cout << CourseID << endl;
			viewFile(CourseID);

			string StudentID;
			cout << "Input the StudentID: ";
			getline(cin, StudentID);
			CourseID += ".csv";
			ifstream CourseIFile(CourseID, ios::in);
			int NumLines = getNOofFile(CourseIFile);
			CourseIFile.close();

			removeStudentFromCourse(CourseID, StudentID, NumLines);
			break;
		}
		case 7: {

			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			string SemesterFileName = Semester + ".csv";
			ifstream SemesterFile(SemesterFileName, ios::in);
			int NumLines = getNOofFile(SemesterFile);
			SemesterFile.close();
			updateCourse(SemesterFileName,CourseID,NumLines); //Update xong thi doi ten file
			break;
		}
		case 8: {

			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			string SemesterFileName = Semester + ".csv";
			ifstream SemesterFile(SemesterFileName, ios::in);
			int NumLines = getNOofFile(SemesterFile);
			SemesterFile.close();
			deleteCourse(SemesterFileName, CourseID, NumLines);
			break;
		}
		case 9: {
			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			CourseID += ".csv";
			string LinkEx;
			cout << "Input the link to export: ";
			getline(cin, LinkEx);
			im_exFile(CourseID, LinkEx);
			break;
		}
		case 10: {
			viewFile(Semester);
			cin.ignore();
			string CourseID;
			cout << "Input the CourseID: ";
			getline(cin, CourseID);
			string LinkIm;
			cout << "Input link import: ";
			getline(cin, LinkIm);
			string ScoreBoardName = "ScoreBoard\\" + CourseID + ".csv";
			im_exFile(LinkIm, ScoreBoardName);
			break;
		}
		case 11: {
			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			string ScoreBoardName = "ScoreBoard\\" + CourseID;
			viewFile(ScoreBoardName);
			system("pause");
			break;
		}
		case 12: {
			viewFile(Semester);
			string CourseID;
			cout << "Input the CourseID: ";
			cin.ignore();
			getline(cin, CourseID);
			viewFile("ScoreBoard\\" + CourseID);
			string StudentID;
			cout << "Input the StudentID: ";
			getline(cin, StudentID);

			string ScoreBoardName = "ScoreBoard\\" + CourseID + ".csv";

			ifstream SemesterFile(ScoreBoardName, ios::in);
			int NumLines = getNOofFile(SemesterFile);
			SemesterFile.close();
			updateStudentScore(ScoreBoardName, StudentID, NumLines);
			break;
		}
		}
	} while (1);
}


string getCurrentPath() {
	char cwd[MAX_PATH];
	GetCurrentDirectoryA(sizeof(cwd), cwd);
	string CurrentPath(cwd);
	return CurrentPath;
}

int main() {
	StaffOrStudent();
	return 0;
}