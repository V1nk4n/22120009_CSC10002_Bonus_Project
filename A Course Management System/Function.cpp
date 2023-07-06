#include "Header.h"

//Ham kiem tra 1 phan tu da xuat hien trong file chua

//Ham tao 1 file moi
int checkFile(string FileName) {
	fstream File(FileName + ".csv", ios_base::in);
	if (File.good()) {
		cout << "File already exitsts." << endl;
		File.close();
		return 1;
	}
	File.close();
	return 0;
}

void createFile(string Path) { //Sua thanh kieu void
	fstream File(Path+".csv", ios_base::out);
	if (!File) {
		cout << "Error creating class file." << endl;
	}
	File.close();

	cout << "File created successfully." << endl;
}

void createFolder(string& Path, string Name) {
	Path += "\\" + Name;
	_mkdir(Path.c_str());
	Path += "\\" + Name;
	createFile(Path);
}//Tai sao &Path

void copyFile(ifstream& File1, ofstream& File2) { 
	string line;
	while (getline(File1, line)) { 
		line += '\n';
		File2 << line;
	}
}

void normalizePath(string& Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] == '/') {
			Str[i] = '\\';
		}
	}
}

void importList(string SourcePath, string DesPath) {
	cout << "Input path source: ";
	cin >> SourcePath;
	ifstream SourceFile(SourcePath, ios::in);
	if (!SourceFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	ofstream DesFile(DesPath, ios::out);
	if (!DesFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	copyFile(SourceFile, DesFile);
	SourceFile.close();
	DesFile.close();

}

void initList(List& lst) {
	lst.pHead = lst.pTail = NULL;
}

int isEmpty(List lst) {
	return (lst.pHead == NULL);
}

Node* createNode(string data) {
	Node* p = new Node;
	p->info = data;
	p->pNext = NULL;
	return p;
}

void addTail(List& lst, Node* p) {
	if (isEmpty(lst)) {
		lst.pHead = lst.pTail = p;
	}
	else {
		lst.pTail->pNext = p;
		lst.pTail = p;
	}
}

void outList(List lst) {
	if (isEmpty(lst)) {
		cout << "List is empty" << endl;
		return;
	}
	for (Node* i = lst.pHead; i != NULL; i = i->pNext) {
		cout << i->info << endl;
	}
}

void viewFile(string FileName) {
	ifstream File;
	FileName += ".csv";
	File.open(FileName, ios::in);
	if (!File.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string temp;
	while (getline(File, temp)) {
		tString(temp);
		cout << temp << endl;
	}

	File.close();
}

int getNOofFile(ifstream& File) {
	int count = 0;
	string line;
	while (getline(File, line)) {
		count++;
	}
	if (count == 1)
		return count;
	else
		return (count+1);
}

void upStudentListToFile() {
	//NHAP LINK
	string SourceLink;
	cout << "Inputt link source file: ";
	cin >> SourceLink;
	ifstream SourceFile(SourceLink + ".csv", ios_base::in);
	if (!SourceFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	string DesLink;
	cout << "Input link destination file: ";
	cin >> DesLink;
	ofstream DesFile(DesLink + ".csv", ios_base::out);
	if (!DesFile.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	copyFile(SourceFile, DesFile);

	SourceFile.close();
	DesFile.close();

	//COPY FILE TREN SANG FILE HE THONG
	
}

void tString(string& Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] == ',') {
			Str[i] = '\t';
		}
	}
}

void nString(string& Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] == '\,') {
			Str[i] = '\n';
		}
	}
}


