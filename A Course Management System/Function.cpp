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

fstream createFile(string Path) { //Sua thanh kieu void
	fstream File(Path+".csv", ios_base::out);
	if (!File) {
		cout << "Error creating class file." << endl;
		return File;
	}
	File.close();

	cout << "File created successfully." << endl;
	return File;
}

void createFolder(string& Path, string Name) {
	_mkdir(Path.c_str());
	Path += '\\' + Name;
	createFile(Path);
}

void copyFile(fstream& File1, fstream& File2) { //copy file1 to file2
	string line;
	while (!File1.eof()) {
		getline(File1, line);
		line += '\n';
		File2 << line;
	}
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
	for (Node* i = lst.pHead; i != NULL; i = i->pNext) {
		cout << i->info;
	}
}