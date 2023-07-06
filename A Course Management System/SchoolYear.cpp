#include "Header.h"


void createSchoolYear() {
	ofstream SchoolYearFile;
	SchoolYearFile.open("SchoolYear.csv", ios_base::out | ios_base::app);
	if (!SchoolYearFile.is_open()) {
		cout << "Cant open" << endl;
	}
	string SchoolYearName;
	cout << "Input SchoolYear: ";
	cin >> SchoolYearName;
	if (!checkFile(SchoolYearName)) {
		SchoolYearFile << SchoolYearName << "\n";
		SchoolYearFile.close();
		string SchoolYearPath = getCurrentPath()+"\\"+SchoolYearName;
		_mkdir(SchoolYearPath.c_str());
		createFolder(SchoolYearPath,"Class");
		SchoolYearPath = getCurrentPath() + "\\" + SchoolYearName +"\\Semester";
		_mkdir(SchoolYearPath.c_str());
	}
}

int checkList(List lst, string des) {
	for (Node* i = lst.pHead; i != NULL; i = i->pNext) {
		if (i->info == des)
			return 1;
	}
	return 0;
}
void chooseSchoolYear(string& SchoolYear) {
	cout << "SCHOOLYEAR" << endl;
	List SchoolYearList;
	initList(SchoolYearList);

	getSchoolYearList(SchoolYearList);
	outList(SchoolYearList);

	do {
		cout << "Input school year: ";
		cin.ignore();
		getline(cin, SchoolYear);
	} while (!checkList(SchoolYearList, SchoolYear));
}

void getSchoolYearList(List& SchoolYearList) {
	ifstream SchoolYearFile("SchoolYear.csv", ios::in);
	if (!SchoolYearFile.is_open()) {
		cout << "Cant open" << endl;
		return;
	}

	string temp;
	while(getline(SchoolYearFile, temp)) {
		Node* buffer = createNode(temp);
		addTail(SchoolYearList, buffer);
	}

	SchoolYearFile.close();
}




