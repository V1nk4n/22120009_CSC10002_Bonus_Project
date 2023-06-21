#include "Header.h"


//void inDate(Date& a) {
//	cout << "Input day: "; cin >> a.dd;
//	cout << "Input month: "; cin >> a.mm;
//	cout << "Input year: "; cin >> a.yy;
//}

Student inStudent() {
	Student a;
	cin.ignore();
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