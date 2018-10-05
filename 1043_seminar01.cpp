#include<iostream>

using namespace std;

struct Spital {
	int nrMedici;
	float salariuMediu;
	char* denumire;
};

void afisare(Spital s) {
	cout << s.denumire << " are " << s.nrMedici 
		<< " - " << s.salariuMediu << endl;
}

void main() {
	int a = 8;
	cout << a << endl;
	int * b = &a;
	cout << *b<<endl;
	//alta sectiune
	Spital s;
	s.nrMedici = 5;
	s.salariuMediu = 3000;
	//s.denumire = (char*)malloc(sizeof(char)*(strlen("Babes") + 1));
	s.denumire = new char[strlen("Babes") + 1];
	strcpy(s.denumire, "Babes");

	afisare(s);

	delete[]s.denumire;
}