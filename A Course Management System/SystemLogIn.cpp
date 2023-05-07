#include "Header.h"

int checkLogIn(Account a) {
	fstream SystemLoginFile;
	SystemLoginFile.open("SystemLogin.csv", ios_base::in | ios_base::app);
	if (!SystemLoginFile.is_open())
		cout << "Cant open" << endl;

	Account Temp;
	getline(SystemLoginFile, Temp.UserName, ',');
	getline(SystemLoginFile, Temp.Password, ',');
	getline(SystemLoginFile, Temp.Title, ',');

	if (a.UserName == Temp.UserName && a.Password == Temp.Password && a.Title == Temp.Title)
		return 1;
	return 0;
}
void LogIn() {
	//Nhap
	Account a;
	cout << "Log In" << endl;
	cout << "UserName: "; getline(cin, a.UserName);
	cout << "Password: "; getline(cin, a.Password);
	cout << "Title: "; getline(cin, a.Title);

	//CheckLogIn
	//Thong bao -> vao chuong trinh

	//BACK
}
void SignUp() {
	fstream SystemLoginFile;
	SystemLoginFile.open("SystemLogin.csv", ios_base::in | ios_base::app);
	if (!SystemLoginFile.is_open())
		cout << "Cant open" << endl;

	Account a;
	cout << "Sign Up" << endl;
	cout << "UserName: "; getline(cin, a.UserName);
	cout << "Password: "; getline(cin, a.Password);
	cout << "Title: "; getline(cin, a.Title);

	SystemLoginFile << a.UserName << ',' << a.Password << ',' << a.Title << endl;
	
	SystemLoginFile.close();
}


