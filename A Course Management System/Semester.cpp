#include "Header.h"

void createSemester(string SchoolYearPath, string SchoolYear) {
	Semester a;
	cout << "Input Semester:"; getline(cin, a.Semester);
	a.SchoolYear = SchoolYear;
	cout << "Input StartDate: "; getline(cin, a.StartDate);
	cout << "Input EndDate :"; getline(cin, a.EndDate);

	fstream SchoolYearFile(SchoolYearPath + ".csv", ios_base::app);
	SchoolYearFile << a.Semester <<','<< a.StartDate <<','<< a.EndDate << '\n';
	SchoolYearFile.close();

	string SemeterPath = SchoolYearPath + '\\' + a.Semester;
	if (!checkFile(SemeterPath)) {
		createFile(SemeterPath);
	}
	
}
