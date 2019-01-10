//#include<iostream>
//
//using namespace std;
//
//
////int aduna(int a, int b)
////{
////	return a + b;
////}
////
////double aduna(double a, double b) {
////	return a + b;
////}
//class Moneda {
//	int anEmitere;
//	string tara;
//	float valoare;
//public:
//	Moneda() {
//		this->anEmitere = 0;
//		this->tara = "";
//		this->valoare = 0;
//	}
//	Moneda(int anEmitere, string tara,float valoare) {
//		this->anEmitere = anEmitere;
//		this->tara = tara;
//		this->valoare = valoare;
//	}
// float getValoare() {
//	 return valoare;
//	}
// explicit operator float() {
//	 return valoare;
// }
//
// Moneda operator+(Moneda m) {
//	 Moneda moneda = *this;
//	 moneda.valoare = this->valoare + m.valoare;
//	 return moneda;
// }
//
//};
//template<class T>
//T aduna(T a, T b) {
//	return a + b;
//}
//
//template<class TEM>
//class Colectionar {
//	string nume;
//	TEM *colectie;
//	int nrElemente;
//public:
//	Colectionar() {
//		nume = "Popescu";
//		nrElemente = 0;
//		colectie = NULL;
//	}
//
//	Colectionar(string nume, int nrElemente,TEM *colectie) {
//		this->nume = nume;
//		this->nrElemente = nrElemente;
//		this->colectie = new TEM[nrElemente];
//		for (int i = 0; i < nrElemente; i++) {
//			this->colectie[i] = colectie[i];
//		}
//	}
//	Colectionar( const Colectionar& c) {
//		this->nume = c.nume;
//		this->nrElemente = c.nrElemente;
//		this->colectie = new TEM[c.nrElemente];
//		for (int i = 0; i < c.nrElemente; i++) {
//			this->colectie[i] = c.colectie[i];
//		}
//	}
//	Colectionar operator=( Colectionar& c) {
//		this->nume = c.nume;
//		this->nrElemente = c.nrElemente;
//		if (this->colectie != NULL) {
//			delete[]this->colectie;
//		}
//		this->colectie = new TEM[c.nrElemente];
//		for (int i = 0; i < c.nrElemente; i++) {
//			this->colectie[i] = c.colectie[i];
//		}
//		return *this;
//	}
//	~Colectionar() {
//		if (colectie != NULL) {
//			delete[]colectie;
//		}
//	}
//	float calcularePretColectie() {
//		float val = 0;
//		for (int i = 0; i < nrElemente; i++)
//		{
//			val =val + (float)colectie[i];
//		}
//		return val;
//	}
//};
//
//void main() {
//	cout << aduna(3, 9) << endl;
//	cout << aduna(3.7, 9.6)<<endl;
//
//	Moneda m1(2019, "Romania", 50);
//	Moneda m2(2019, "Romania", 10);
//
//	Moneda m3 = aduna(m1, m2);
//	cout << m3.getValoare()<<endl;
//
//	Colectionar<int> c1;
//	Colectionar<float> c2("Alex", 3, new float[3]{ 3,2,7 });
//	cout << c2.calcularePretColectie()<<endl;
//
//	Colectionar<Moneda> c3("Vasilescu", 2, new Moneda[2]{ m1,m2 });
//
//	cout << c3.calcularePretColectie() << endl;
//	//de facut o noua clasa pe care sa o folosim pentru colectionar:
//	//timbre
//	//servetele
//	//capace
//	//bilete
//	//etc
//}