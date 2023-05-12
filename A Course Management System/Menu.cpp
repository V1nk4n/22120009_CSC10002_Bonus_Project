#include "Header.h";

void SystemLogInMenu() {
	int op{};
	do {
		cout << "0. End" << endl;
		cout << "1. Log in" << endl;
		cout << "2. Sign up" << endl;
		cout << "Enter your option: ";
		switch (op) {
		case 1:
			//LogIn
			break;
		case 2:

			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void UserMenu() {
	int op{};
	do {
		cout << "1. View profile" << endl;
		cout << "2. Change password" << endl;
		cout << "3. Log out" << endl;
		cout << "4. WorkSpace" << endl;
		cout << "Enter your option: ";
		switch (op) {
		case 1:
			//View profile
			break;
		case 2:
			//Change password (xoa 1 hang trong file r ghi lai)
			break;
		case 3:
			//LogIn
			break;
		case 4:
			//Neu la Staff vao StaffMenu
			//Neu la Student vao StudentMenu
			break;
		}
		system("pause");
		system("cls");
	} while (1);
}

void StaffMenu() {
	int op{};
	do {
		cout << "0. Back" << endl;
		cout << "1. Create a school year" << endl;
		cout << "2. Create a class" << endl;
		cout << "3. Add new 1st student to a class" << endl;
		cout << "4. Create a semester" << endl;
		cout << "5. Add a course to a semester" << endl;
		cout << "6. Update course information" << endl;
		cout << "7. Add a student to a course" << endl;
		cout << "8. Remove a student from a course" << endl;
		cout << "9. Delete a course" << endl;
		cout << "10. View the list of courses" << endl;
		cout << "11. View the list of classes" << endl;
		cout << "12. View a list of studetns in a class" << endl;
		cout << "13. View the list of students in a course" << endl;
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
	} while (op!=0);
}

void StudentMenu() {
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