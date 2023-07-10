#include "Header.h"

int checkLogIn(Account a, ifstream& AccountFile) {
	Account Temp;
	string buffer;
	while (getline(AccountFile,buffer)) {
		readStaffAccount(Temp, buffer);
		if (a.UserName == Temp.UserName && a.Password == Temp.Password) {
			AccountFile.seekg(ios::beg, 0);
			return 1;
		}
	}
	AccountFile.seekg(ios::beg,0);
	return 0;
}
void StaffLogin(Account& a) {
	//Nhap
	cin.ignore();
	ifstream AccountFile("SystemLogin.csv", ios_base::in);
	if (!AccountFile.is_open())
		cout << "Cant open" << endl;
	do {
		cout << "LOG IN" << endl;
		cout << "UserName: "; getline(cin, a.UserName);
		cout << "Password: "; getline(cin, a.Password);
		system("cls");
	} while (!checkLogIn(a, AccountFile));
	cout << "Successfully" << endl;
	AccountFile.close();
}

void StudentLogin(Account& a) {
	cin.ignore();
	ifstream AccountFile("StudentAccount.csv", ios_base::in);
	if (!AccountFile.is_open())
		cout << "Cant open" << endl;
	do {
		cout << "LOG IN" << endl;
		cout << "UserName: "; getline(cin, a.UserName);
		cout << "Password: "; getline(cin, a.Password);
		system("cls");
	} while (!checkLogIn(a, AccountFile));
	cout << "Successfully" << endl;
	AccountFile.close();
}

void StaffSignUp() {
	ofstream SystemLoginFile;
	SystemLoginFile.open("SystemLogin.csv", ios_base::app);
	if (!SystemLoginFile.is_open())
		cout << "Cant open" << endl;

	Account a;
	string codeStaff;
	cout << "SIGN UP" << endl;
	cin.ignore();
	cout << "UserName: "; getline(cin, a.UserName);
	cout << "Password: "; getline(cin, a.Password);
	do {
		cout << "Code: ";
		getline(cin, codeStaff);
	} while (codeStaff != CODE);

	SystemLoginFile << a.UserName << '\,' << a.Password << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\n';
	
	SystemLoginFile.close();
}

void viewStaffProfile(Account& a) {
	system("cls");
	ifstream AccountFile("SystemLogin.csv", ios::in);
	string temp;
	while (getline(AccountFile, temp)) {
		if (getNo(temp) == a.UserName) {
			readStaffAccount(a, temp);
			displayProfile(a);
			break;
		}
	}
	AccountFile.close();
}

void readStaffAccount(Account& a, string temp) {
	string token;
	int startPos = 0;
	getToken(token, temp, startPos);
	a.UserName = token;
	getToken(token, temp, startPos);
	a.Password = token;
	getToken(token, temp, startPos);
	a.Staff.ID = token;
	getToken(token, temp, startPos);
	a.Staff.FirstName = token;
	getToken(token, temp, startPos);
	a.Staff.LastName = token;
	getToken(token, temp, startPos);
	a.Staff.Gender = token;
	getToken(token, temp, startPos);
	a.Staff.DateOfBirth = token;
	getToken(token, temp, startPos);
	a.Staff.SocialID = token;
}

int getToken(string& token, string s, int& startPos) {
	string sep = "\n,";
	int fromPos, toPos, length = s.length(), tokenLength = 0;
	token = "";
	fromPos = s.find_first_not_of(sep, startPos);
	if (fromPos == string::npos)
		return tokenLength;
	toPos = s.find_first_of(sep, fromPos);
	if (toPos == string::npos)
		toPos = length;
	tokenLength = toPos - fromPos;
	token = s.substr(fromPos, tokenLength);
	startPos = toPos;
	return tokenLength;
}

void changeStaffProfile(Account& a, int NumLines) {
	viewStaffProfile(a);

	cin.ignore();
	updateProfile(a);
	
	ifstream AccountFile("SystemLogin.csv", ios::in);
	string* Lines = new string[NumLines];
	string temp;
	int n = 0;
	while (getline(AccountFile, temp)) {
		if (getNo(temp) != a.UserName) {
			Lines[n++] = temp;
		}
		else {
			string NewCourse;
			NewCourse = a.UserName + '\,' + a.Password + '\,' + a.Staff.ID + '\,' + a.Staff.FirstName + '\,' + a.Staff.LastName + '\,' + a.Staff.Gender + '\,' + a.Staff.DateOfBirth + '\,' + a.Staff.SocialID;
			temp = NewCourse;
			Lines[n++] = temp;
		}
	}
	AccountFile.close();

	ofstream SemesterOFile("SystemLogin.csv", ios::out);
	int t = 0;
	while (t <= n) {
		Lines[t] += '\n';
		SemesterOFile << Lines[t++];
	}
	delete[] Lines;
	SemesterOFile.close();
}

void updateProfile(Account& a) {
	string temp;
	cout << "NEW DATA" << endl;
	cout << "Password: "; getline(cin, temp); a.Password = temp;
	cout << "ID: "; getline(cin, temp); a.Staff.ID = temp;
	cout << "FirstName: "; getline(cin, temp); a.Staff.FirstName = temp;
	cout << "LastName: "; getline(cin, temp); a.Staff.LastName = temp;
	cout << "Gender: "; getline(cin, temp); a.Staff.Gender = temp;
	cout << "DayOfBirth: "; getline(cin, temp); a.Staff.DateOfBirth = temp;
	cout << "SocialID: "; getline(cin, temp); a.Staff.SocialID = temp;
}

void displayProfile(Account a) {
	cout << "PROFILE" << endl;
	cout << "Username: " << a.UserName << endl;
	cout << "Password: " << a.Password << endl;
	cout << "ID: " << a.Staff.ID << endl;
	cout << "FirstName: " << a.Staff.FirstName << endl;
	cout << "LastName: " << a.Staff.LastName << endl;
	cout << "Gender: " << a.Staff.Gender << endl;
	cout << "DayOfBirth: " << a.Staff.DateOfBirth << endl;
	cout << "SocialID: " << a.Staff.SocialID << endl;
}

void StudentSignUp() {
	system("cls");
	ofstream StudentLoginFile;
	StudentLoginFile.open("StudentAccount.csv", ios_base::app);
	if (!StudentLoginFile.is_open())
		cout << "Cant open" << endl;

	Account a;
	cout << "SIGN UP" << endl;
	cin.ignore();
	cout << "UserName: "; getline(cin, a.UserName);
	cout << "Password: "; getline(cin, a.Password);

	StudentLoginFile << a.UserName << '\,' << a.Password << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\,' << "x" << '\n';

	StudentLoginFile.close();
}

void viewStudentProfile(Account& a) {
	system("cls");
	ifstream AccountFile("StudentAccount.csv", ios::in);
	string temp;
	while (getline(AccountFile, temp)) {
		if (getNo(temp) == a.UserName) {
			readStudentAccount(a, temp);
			displayStudentProfile(a);
			break;
		}
	}
	AccountFile.close();
}

void readStudentAccount(Account& a, string temp) {
	string token;
	int startPos = 0;
	getToken(token, temp, startPos);
	a.UserName = token;
	getToken(token, temp, startPos);
	a.Password = token;
	getToken(token, temp, startPos);
	a.Student.StudentID = token;
	getToken(token, temp, startPos);
	a.Student.FirstName = token;
	getToken(token, temp, startPos);
	a.Student.LastName = token;
	getToken(token, temp, startPos);
	a.Student.Gender = token;
	getToken(token, temp, startPos);
	a.Student.DateOfBirth = token;
	getToken(token, temp, startPos);
	a.Student.SocialID = token;
	getToken(token, temp, startPos);
	a.Student.StudentClass = token;
	getToken(token, temp, startPos);
	a.Student.StudentYear = token;
}

void changeStudentProfile(Account& a, int NumLines) {
	viewStudentProfile(a);

	cin.ignore();
	updateStudentProfile(a);

	ifstream AccountFile("StudentAccount.csv", ios::in);
	string* Lines = new string[NumLines];
	string temp;
	int n = 0;
	while (getline(AccountFile, temp)) {
		if (getNo(temp) != a.UserName) {
			Lines[n++] = temp;
		}
		else {
			string NewCourse;
			NewCourse = a.UserName + '\,' + a.Password + '\,' + a.Student.StudentID + '\,' + a.Student.FirstName + '\,' + a.Student.LastName + '\,' + a.Student.Gender + '\,' + a.Student.DateOfBirth + '\,' + a.Student.SocialID + '\,' + a.Student.StudentClass + '\,' +a.Student.StudentYear;
			temp = NewCourse;
			Lines[n++] = temp;
		}
	}
	AccountFile.close();

	ofstream SemesterOFile("StudentAccount.csv", ios::out);
	int t = 0;
	while (t <= n) {
		Lines[t] += '\n';
		SemesterOFile << Lines[t++];
	}
	delete[] Lines;
	SemesterOFile.close();
}

void updateStudentProfile(Account& a) {
	string temp;
	cout << "NEW DATA" << endl;
	cout << "Password: "; getline(cin, temp); a.Password = temp;
	cout << "ID: "; getline(cin, temp); a.Student.StudentID = temp;
	cout << "FirstName: "; getline(cin, temp); a.Student.FirstName = temp;
	cout << "LastName: "; getline(cin, temp); a.Student.LastName = temp;
	cout << "Gender: "; getline(cin, temp); a.Student.Gender = temp;
	cout << "DayOfBirth: "; getline(cin, temp); a.Student.DateOfBirth = temp;
	cout << "SocialID: "; getline(cin, temp); a.Student.SocialID = temp;
	cout << "Class: "; getline(cin, temp); a.Student.StudentClass= temp;
	cout << "Year: "; getline(cin, temp); a.Student.StudentYear = temp;
}

void displayStudentProfile(Account a) {
	cout << "PROFILE" << endl;
	cout << "Username: " << a.UserName << endl;
	cout << "Password: " << a.Password << endl;
	cout << "ID: " << a.Student.StudentID << endl;
	cout << "FirstName: " << a.Student.FirstName << endl;
	cout << "LastName: " << a.Student.LastName << endl;
	cout << "Gender: " << a.Student.Gender << endl;
	cout << "DayOfBirth: " << a.Student.DateOfBirth << endl;
	cout << "SocialID: " << a.Student.SocialID << endl;
	cout << "Class: " << a.Student.StudentClass << endl;
	cout << "Year: " << a.Student.StudentYear << endl;
}