//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Telefon {
//public:
//	string marca;
////private:
//	int memorie;
////protected:
//	float pret;
//
//	void modificarePret() {
//		this->pret = 8000;
//	}
//
//	void printare()//poate sa se numeasca si afisare
//	{
//		cout << marca << " are " << memorie << "GB si costa " << pret<<endl;
//	}
//};
//
//void afisare(Telefon tel) {
//	cout << tel.marca << " are o memorie de " << tel.memorie << "GB si costa " << tel.pret << endl;
//}
//
//void main() {
//	Telefon t; //declararea unui obiect de tipul Telefon
//	//Telefon t2;
//	t.marca = "Samsung";
//	t.memorie = 2;
//	t.pret = 2000;
//
//	Telefon * pt;
//	pt = new Telefon();
//	(*pt).marca = "Apple";
//	pt->memorie = 4;
//	pt->pret = 4000;
//
//	//Telefon *pt;
//	//pt = &t;
//
//	//afisare(t);
//	//afisare(*pt);
//
//	t.printare();
//	pt->printare();
//
//	pt->modificarePret();
//	t.printare();
//	pt->printare();
//
//	cout << "Dupa modificare:" << endl;
//	t.modificarePret();
//	t.printare();
//	pt->printare();
//
//
//	Telefon * vt;
//	int n = 3;
//	vt = new Telefon[n];
//
//	for (int i = 0; i < n; i++) {
//		vt[i].marca = "Telefon";
//		vt[i].memorie = i+1;
//		vt[i].pret = (i+1) * 1000;
//	}
//
//	cout << "vector:" << endl;
//	for (int i = 0; i < n; i++) {
//		vt[i].printare();
//	}
//
//	Telefon* *vpt;
//	vpt = new Telefon*[n];
//
//	for (int i = 0; i < n; i++) {
//		vpt[i] = new Telefon();
//		vpt[i]->marca = "Telefon";
//		vpt[i]->memorie = i + 1;
//		vpt[i]->pret = (i + 1) * 100;
//	}
//
//	for (int i = 0; i < n; i++) {
//		vpt[i]->printare();
//		afisare(*vpt[i]);
//	}
//
//trebuie sa adaugam stegerile.
//}