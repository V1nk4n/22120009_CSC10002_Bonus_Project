#include "Header.h"


//void inDate(Date& a) {
//	cout << "Input day: "; cin >> a.dd;
//	cout << "Input month: "; cin >> a.mm;
//	cout << "Input year: "; cin >> a.yy;
//}

void inStudent(Student& a) {
	cout << "Input StudentID: ";
	cin >> a.StudentID;
	cout << "Input FullName: ";
	cin.ignore(); 
	getline(cin, a.FullName);
	int pos = a.FullName.find(' '); 
	a.FirstName = a.FullName.substr(0, pos);
	a.LastName = a.FullName.substr(pos + 1);
	cout << "Input Gender: ";
	cin >> a.Gender;
	cout << "Input DateOfBirth" << endl;
	
	cout << "Input SocialID: ";
	cin >> a.SocialID;
	cout << "Input StudentYear: ";
	cin >> a.StudentYear;
	cout << "Input StudentClass: ";
	cin >> a.StudentClass;
}

void inStudentToFile(fstream& File, Student a) {
	File << a.StudentID <<','<< a.FirstName << ',' << a.LastName << ',' << a.Gender << ',' << a.DateOfBirth << ',' << a.SocialID << '\n';
}