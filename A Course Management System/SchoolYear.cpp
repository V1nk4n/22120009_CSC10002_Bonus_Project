#include "Header.h"

void createSchoolYear() {
	fstream SchoolYearFile;
	SchoolYearFile.open("SchoolYear\\SchoolYear.csv", ios_base::in | ios_base::app);
	if (!SchoolYearFile.is_open()) {
		cout << "Cant open" << endl;
	}
	string SchoolYearName;
	cout << "Input SchoolYear: ";
	cin >> SchoolYearName;
	if (!checkFile(SchoolYearName)) {
		SchoolYearFile << SchoolYearName << "\n";
		SchoolYearFile.close();
		string SchoolYearPath = "SchoolYear\\" + SchoolYearName;
		createFolder(SchoolYearPath, SchoolYearName);
	}
}



