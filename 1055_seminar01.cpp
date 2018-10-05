#include<iostream>
//
using namespace std;

struct Profesor {
	char* nume;
	int varsta;
	float salariu;
};

void afisare(Profesor prof) {

	cout << "Profesorul " << prof.nume << " are " 
		<< prof.varsta << " ani si un salariu de " 
		<< prof.salariu << endl;
}

void functie(int* p) {
	*p = 4;
}

void main() {
	int v = 7;
	cout << v;

	int* b = &v;
	cout << v<<endl;
	cout << *b<<endl<<endl;

	functie(&v);
	cout << "Dupa apel:" << v<<endl;

	Profesor prof;
	//prof.nume = (char*)malloc(sizeof(char)*(strlen("Ion")+1));
	prof.nume = new char[strlen("Ion") + 1];
	strcpy(prof.nume, "Ion");
	prof.varsta = 45;
	prof.salariu = 1200;

	afisare(prof);
	delete[]prof.nume;
}