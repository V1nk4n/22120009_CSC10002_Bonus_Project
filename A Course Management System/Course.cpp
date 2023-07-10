#include "Header.h"

Course inCourse() {
	Course a;
	cin.ignore();
	cout << "Input CourseID: ";
	getline(cin, a.CourseID);
	cout << "Input CourseName: ";
	getline(cin, a.CourseName);
	cout << "Input ClassName: ";
	getline(cin, a.ClassName);
	cout << "Input TeacherName: ";
	getline(cin, a.TeacherName);
	cout << "Input NumOfCredits: ";
	getline(cin, a.NumOfCredits);
	cout << "Input MaxNumOfStudents: ";
	getline(cin, a.MaxNumOfStudents);
	cout << "Input Session: ";
	getline(cin, a.Session);
	cout << "Input Day Of Week: ";
	getline(cin, a.DayOfWeek);
	return a;
}

void outCourse(Course a) {
	cout << a.CourseID << "\t" << a.CourseName << "\t" << a.ClassName << "\t" << a.TeacherName << "\t" << a.NumOfCredits << "\t" << a.MaxNumOfStudents << "\t" << a.Session << "\t" << a.DayOfWeek << endl;
}

void createCourse(string Semester) {
	system("cls");
	Course a = inCourse();

	ofstream SemesterFile(Semester + ".csv", ios_base::app);
	SemesterFile << a.CourseID << '\,' << a.CourseName << '\,' << a.ClassName << '\,' << a.TeacherName << '\,' 
		<< a.NumOfCredits << '\,' << a.MaxNumOfStudents << '\,' << a.Session << '\,' << a.DayOfWeek << '\n';
	SemesterFile.close();

	string CourseName = a.CourseID + "\\" + a.CourseID + ".csv";

	ofstream CourseFile(a.CourseID +".csv", ios::out);
	CourseFile << "No" << '\,' << "StudentID" << '\,' << "FirstName" << '\,' << "LastName" << '\,' 
		<< "Gender" << '\,' << "DayOfBirth" << '\,' << "SocialID" << '\n';
	CourseFile.close();

	string ScoreBoardName = "ScoreBoard\\"+a.CourseID+".csv";
	ofstream ScoreBoardFile(ScoreBoardName, ios::out);
	ScoreBoardFile << "No" << '\,' << "StudentID" << '\,' << "FirstName" << '\,' << "LastName" << '\,' 
		<< "Total Mark" << '\,' << "Final Mark" << '\,' << "Midtern Mark" << '\,' << "Other Mark" << '\n';
	ScoreBoardFile.close();
}

void addStudentToCourse(string CourseID) {
	system("cls");

	/*CourseID += ".csv";*/
	ifstream CourseIFile(CourseID, ios::in);
	int No = getNOofFile(CourseIFile);
	CourseIFile.close();

	Student a = inStudent();

	a.No = to_string(No);
	ofstream CourseOFile(CourseID, ios::app);
	CourseOFile << a.No << '\,' << a.StudentID << '\,' << a.FirstName << '\,' 
		<< a.LastName << '\,' << a.Gender << '\,' << a.DateOfBirth << '\,' << a.SocialID << '\n';
	CourseOFile.close();
}

string getID(string Data) {
	int index = Data.find('\,') + 1;
	string token = Data.substr(index, Data.find('\,', index) - (index));
	return token;
}

string getNo(string Data) {
	int index = Data.find('\,');
	string token = Data.substr(0, index);
	return token;
}

string getNewNo(string Data) {
	int No = stoi(Data);
	No--;
	return to_string(No);
}

void removeStudentFromCourse(string CourseID, string StudentID, int NumLines) {
	
	ifstream CourseIFile(CourseID, ios::in);
	string* Lines = new string[NumLines - 1];
	string temp;
	/*CourseIFile.seekg(0,ios_base::beg);*/
	int n = 0;
	int flag = 0;
	while ( getline(CourseIFile, temp)){
		if (getID(temp) == StudentID) {
			flag = 1;
		}
		if (flag == 1) {
			string No = getNo(temp);
			temp.replace(0, No.length(), getNewNo(No));
		}
		if (getID(temp) != StudentID) {
			Lines[n++] = temp;
		}
	}
	CourseIFile.close();

	ofstream CourseOFile(CourseID, ios::out);
	int t = 0;
	while (t<=n) {
		Lines[t] += '\n';
		CourseOFile << Lines[t++];
	}
	delete[] Lines;
	CourseOFile.close();
}


void updateCourse(string SemesterFileName, string CourseID, int NumLines) {
	Course a = inCourse();
	ifstream SemesterIFile(SemesterFileName, ios::in);
	string* Lines = new string[NumLines];
	string temp;
	int n=0;
	while (getline(SemesterIFile, temp)) {
		if (getNo(temp) != CourseID) {
			Lines[n++] = temp;
		}
		else {
			string NewCourse;
			NewCourse = a.CourseID + '\,' + a.CourseName + '\,' + a.ClassName + '\,' + a.TeacherName 
				+ '\,' + a.NumOfCredits + '\,' + a.MaxNumOfStudents + '\,' + a.Session + '\,' + a.DayOfWeek;
			temp = NewCourse;
			Lines[n++] = temp;
		}
	}
	SemesterIFile.close();

	ofstream SemesterOFile(SemesterFileName, ios::out);
	int t = 0;
	while (t <= n) {
		Lines[t] += '\n';
		SemesterOFile << Lines[t++];
	}
	delete[] Lines;
	SemesterOFile.close();


	string imCourse =CourseID + ".csv";
	string exCourse =a.CourseID + ".csv";
	im_exFile(imCourse, exCourse);
	remove(imCourse.c_str());

	imCourse = "ScoreBoard\\" + CourseID + ".csv";
	exCourse = "ScoreBoard\\" + a.CourseID + ".csv";
	im_exFile(imCourse, exCourse);
	remove(imCourse.c_str());
}

void deleteCourse(string SemesterFileName, string CourseID, int NumLines) {
	ifstream SemesterIFile(SemesterFileName, ios::in);
	string* Lines = new string[NumLines - 1];
	string temp;
	int n = 0;
	
	while (getline(SemesterIFile, temp)) {
		if (getNo(temp) != CourseID) {
			Lines[n++] = temp;
		}
	}
	SemesterIFile.close();

	ofstream SemesterOFile(SemesterFileName, ios::out);
	int t = 0;
	while (t <= n) {
		Lines[t] += '\n';
		SemesterOFile << Lines[t++];
	}
	delete[] Lines;
	SemesterOFile.close();

	CourseID += ".csv";
	remove(CourseID.c_str());

	string ScoreBoardName = "ScoreBoard\\" + CourseID;
	remove(ScoreBoardName.c_str());
}

void im_exFile(string LinkIm, string LinkEx) {
	ifstream ImportFile(LinkIm, ios::in);
	ofstream ExportFile(LinkEx, ios::out);
	copyFile(ImportFile, ExportFile);
	ImportFile.close();
	ExportFile.close();
}

void updateStudentScore(string ScoreBoardName, string StudentID, int NumLines) { 
	string TotalMark;
	cout << "Input Total Mark: ";
	cin >> TotalMark;

	string FinalMark;
	cout << "Input Final Mark: ";
	cin >> FinalMark;

	string MidternMark;
	cout << "Input Midtern Mark: ";
	cin >> MidternMark;

	string OtherMark;
	cout << "Input Other Mark: ";
	cin >> OtherMark;

	ifstream ScoreBoardIFile(ScoreBoardName, ios::in);
	string* Lines = new string[NumLines];
	string temp;
	int n = 0;
	while (getline(ScoreBoardIFile, temp)) {
		if (getID(temp) != StudentID) {
			Lines[n++] = temp;
		}
		else {
			int t = temp.find('\,', temp.find('\,', temp.find('\,', temp.find('\,') + 1) + 1) + 1);
			string NewStudent = temp.substr(0, t) + '\,' + TotalMark + '\,' 
				+ FinalMark + '\,' + MidternMark + '\,' + OtherMark;
			temp = NewStudent;
			Lines[n++] = temp;
		}
	}
	ScoreBoardIFile.close();

	ofstream ScoreBoardOFile(ScoreBoardName, ios::out);
	int t = 0;
	while (t <= n) {
		Lines[t] += '\n';
		ScoreBoardOFile << Lines[t++];
	}
	delete[] Lines;
	ScoreBoardOFile.close();
}

