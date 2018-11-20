#include<iostream>
#include<string>

using namespace std;

class Apartament {


private:

	static double tva;

	const int id;
	const int etaj;
	int nrCamere;
	float *suprafataCamera;
	string adresa;
	static int contor;
	static int nrApartamenteExistente;

public:
	


	Apartament():id(contor++),etaj(3) {
		nrCamere = 3;
		suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			suprafataCamera[i] = 10;
		}
		adresa = "piata Romana";
		nrApartamenteExistente++;
	}
	Apartament(string adresa, int nrCamere, float* suprafataCamera, int etajPrimit) :id(contor++), etaj(etajPrimit) {
		this->nrCamere = nrCamere;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = suprafataCamera[i];
		}
		this->adresa = adresa;
		nrApartamenteExistente++;
	}

	~Apartament() {
		delete[]suprafataCamera;
		nrApartamenteExistente--;
	}

	void afisare() {
		cout << id << ". In " << adresa << " se afla un apartament cu " << nrCamere << " la etajul "
			<< etaj <<" cu suprafetele ";
		for (int i = 0; i < nrCamere; i++) {
			cout << suprafataCamera[i] << ", ";
		}
		cout << endl;
	}

	void setAdresa(string nouaAdresa) {
		if(nouaAdresa.length()>2)
			this->adresa = nouaAdresa;
	}

	string getAdresa() {
		return this->adresa;
	}
	void setNrCamere(int nrCamere,float* suprafete) {
		this->nrCamere = nrCamere;
		delete []this->suprafataCamera;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = suprafete[i];
		}
	}

	int getNrCamere() {
		return nrCamere;
	}

	float* getSuprafeteCamere() {
		return this->suprafataCamera;
	}

	float getSuprafataCameraData(int index) {
		if (index < nrCamere && index >= 0) {
			return this->suprafataCamera[index];
		}
		else {
			throw "index incorect";
		}
	}

	static void setTVA(double tvaNou) {
		tva = tvaNou;
	}

	static double getTVA() {
		return tva;
	}

	Apartament(const Apartament &a) :id(contor++), etaj(a.etaj) {
		this->nrCamere = a.nrCamere;
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = a.suprafataCamera[i];
		}
		this->adresa = a.adresa;
		nrApartamenteExistente++;		
	}

	Apartament operator=(const Apartament &a) {
		this->nrCamere = a.nrCamere;
		if (this->suprafataCamera != NULL) {
			delete[]this->suprafataCamera;//evit aparitia de memory leaks;
		}
		this->suprafataCamera = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->suprafataCamera[i] = a.suprafataCamera[i];
		}
		this->adresa = a.adresa;

		return *this;
	}

	Apartament operator+(const Apartament &a) {
		Apartament b;
		b.adresa = this->adresa;
		b.nrCamere = this->nrCamere + a.nrCamere;
		b.suprafataCamera = new float[b.nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			b.suprafataCamera[i] = this->suprafataCamera[i];
		}
		for (int i = this->nrCamere; i < b.nrCamere; i++) {
			b.suprafataCamera[i] = a.suprafataCamera[i-this->nrCamere];
		}

		return b;
	}

	Apartament operator+(int nrCamere) {
		Apartament t = *this;
		t.nrCamere = this->nrCamere + nrCamere;
		delete[]t.suprafataCamera;
		t.suprafataCamera = new float[t.nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			t.suprafataCamera[i] = this->suprafataCamera[i];
		}
		for (int i = this->nrCamere; i < t.nrCamere; i++) {
			t.suprafataCamera[i] = 10;
		}
		return t;
	}

	float operator[](int index) {
		return this->getSuprafataCameraData(index);
		//if (index < nrCamere && index >= 0) {
		//	return this->suprafataCamera[index];
		//}
		//else {
		//	throw "index incorect";
		//}
	}

	float calculareSUprafataTotala() {
		float s = 0;
		for (int i = 0; i < this->nrCamere; i++) {
			//s += this->suprafataCamera[i];
			s += (*this)[i];
		}
		return s;
	}

	bool operator>(Apartament a) {
		//return this->nrCamere > a.nrCamere;
		//float s = 0;
		//for (int i = 0; i < this->nrCamere; i++) {
		//	//s += this->suprafataCamera[i];
		//	s += (*this)[i];
		//}

		return this->calculareSUprafataTotala() > a.calculareSUprafataTotala();

	}

	//preincrementare
	Apartament operator++() {
		for (int i = 0; i < this->nrCamere; i++) {
			this->suprafataCamera[i]++;
		}
		return *this;
	}

	//postincrementare
	Apartament operator++(int) {
		Apartament temporar = *this;
		for (int i = 0; i < this->nrCamere; i++) {
			this->suprafataCamera[i]++;
		}
		return temporar;
	}

	float operator()() {
		return calculareSUprafataTotala();
	}

	float operator()(int index) {
		//return (*this)[index];
		return getSuprafataCameraData(index);
	}

	bool operator()(int c1, int c2) {
		return this->getSuprafataCameraData(c1) < this->getSuprafataCameraData(c2);
	}

};
int Apartament::contor = 1;
double Apartament::tva = 19;
int Apartament::nrApartamenteExistente = 0;


void afisareAdresa(Apartament a) {
	cout << a.getAdresa();
}

Apartament operator+(int nrCamere, Apartament a) {
	Apartament t;
	t = a + nrCamere;
	return t;
	//return a+nrCamere;
}

void main() {

	//float * v = new float[3]{ 30,20,40 };
	//Apartament a("Romana", 3, v, 3);
	////Apartament b = a;
	///*Apartament c;
	//c = a;*/

	//afisareAdresa(a);

	Apartament a1;
	Apartament a2;
	Apartament a3;
	a3 = a1 + a2;
	Apartament a4 = a1 + 2;
	Apartament a5 = 3 + a1;
	cout << a5.getSuprafataCameraData(0);
	cout << a5[0];

	if (a4 > a5) {//< > == != <= >=
		cout << "A4 mai mare";
	}
	else {
		cout << "A5 mai mare";
	}

	a5 = ++a4;
	a3 = a5++;
	cout <<endl<< a3.calculareSUprafataTotala() << "<" << a5.calculareSUprafataTotala() << endl;

	cout << a5();//suprafata totala
	cout << a5(6);//suprafata camerei 6 sau arunca exceptie
	cout << a5(2, 6);//0/ 1 daca suprafata camerei  2 este mai mica decat csuprafata camerei 6
	//delete[]v;

	a5.afisare();
	//cout << a5;
}