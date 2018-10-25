//#include<iostream>
//#include<string>
//using namespace std;
//
//class Carte {
//public:
//	const int idCarte;
//	const int codISBN;
//	string titlu;
//	unsigned int nrPagini;
//	double pret;
//	static double tva;//pentru toate cartile;
//	static int nrExemplare;
//	static int contor;
//
//	Carte(): idCarte(contor++),codISBN(1234) {
//		titlu = "Ion";
//		pret = 20;
//		nrExemplare++;
//		nrPagini = 300;
//	}
//
//	Carte(int isbn, string titlu, int nrPagini, double pret) : idCarte(contor++), codISBN(isbn) {
//		this->titlu = titlu;
//		this->nrPagini = nrPagini;
//		this->pret = pret;
//		nrExemplare++;
//	}
//
//	Carte(string s, double pret) :idCarte(contor++), codISBN(0) {
//		nrPagini = 300;
//		titlu = s;
//		this->pret = pret;
//		nrExemplare++;
//	}
//
//	void afisare() {
//		cout << "ID: " << idCarte << ". ISBN:" << codISBN << " TVA:" << tva << "%.";
//		cout << titlu << " costa " << pret << " si are " << nrPagini << " pagini." << endl;
//	}
//	~Carte() {
//		nrExemplare--;
//	}
//};
//double Carte::tva = 5;
//int Carte::nrExemplare = 0;
//int Carte::contor = 1;
//
//
//void main() {
//	Carte c1;
//	cout << c1.nrExemplare<<endl;
//	cout << Carte::tva<<endl;
//	Carte c2(3456,"Iona",80,10);
//	cout << Carte::nrExemplare<<endl;
//	{
//		Carte c5;
//		cout << "In corp:" << Carte::nrExemplare << endl;
//	}
//
//	cout << "In afara corpului:" << Carte::nrExemplare << endl;
//	c1.afisare();
//	c2.afisare();
//
//	Carte* pc1 = &c1;
//
//	Carte * pc2 = new Carte(5678, "Mara", 200, 15);
//	cout << Carte::nrExemplare;
//
//	Carte c3("Ana", 400);
//
//	c3.afisare();
//
//	delete pc2;
//}
