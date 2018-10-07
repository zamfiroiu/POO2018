#include<iostream>

using namespace std;

struct Carte {
	int nrPagini;
	char *titlu;
	float pret;
};

void afisare(Carte c) {
	cout << c.titlu << " are " << c.nrPagini 
		<< " pagini si costa " << c.pret << endl;
}

void main() {
	int a = 4;
	cout << a<<endl;
	int* b = &a;
	cout << *b << endl;
	Carte c;
	c.nrPagini = 200;
	int n = strlen("ION")+1;
	//c.titlu = (char*)malloc(sizeof(char)*n);
	c.titlu = new char[n];
	strcpy(c.titlu, "ION");
	c.pret = 30;

	afisare(c);

	delete[]c.titlu;
}