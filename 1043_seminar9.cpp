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



	Apartament() :id(contor++), etaj(3) {
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
			<< etaj << " cu suprafetele ";
		for (int i = 0; i < nrCamere; i++) {
			cout << suprafataCamera[i] << ", ";
		}
		cout << endl;
	}

	void setAdresa(string nouaAdresa) {
		if (nouaAdresa.length() > 2)
			this->adresa = nouaAdresa;
	}

	string getAdresa() {
		return adresa;
	}
	void setNrCamere(int nrCamere, float* suprafete) {
		this->nrCamere = nrCamere;
		delete[]this->suprafataCamera;
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
			b.suprafataCamera[i] = a.suprafataCamera[i - this->nrCamere];
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

	float& operator[](int index) {
		//return this->getSuprafataCameraData(index);
		if (index < nrCamere && index >= 0) {
			return this->suprafataCamera[index];
		}
		else {
			throw "index incorect";
		}
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

	explicit operator int() {
		return this->nrCamere;
	}
	explicit operator float() {
		return calculareSUprafataTotala();
	}

	friend ostream& operator<<(ostream& afisar, const Apartament& a);
	friend istream& operator>>(istream& citir, Apartament& a) {
		cout << "Adresa:";
		citir >> a.adresa;
		cout << "numarul de camere:";
		citir >> a.nrCamere;
		delete[]a.suprafataCamera;//evitare memory-leaks
		a.suprafataCamera = new float[a.nrCamere];
		for (int i = 0; i < a.nrCamere; i++) {
			cout << "Suprafata" << i << ":";
			citir >> a.suprafataCamera[i];
		}
		return citir;
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

ostream& operator<<(ostream& afisar, const Apartament& a) {
	afisar << a.id << ". In " << a.adresa << " se afla un apartament cu " << a.nrCamere << " la etajul "
		<< a.etaj << " cu suprafetele ";
	for (int i = 0; i < a.nrCamere; i++) {
		afisar << a.suprafataCamera[i] << ", ";
	}
	afisar << endl;
	return afisar;
}

class ExceptieValoare {
public:
	string mesaj;
	ExceptieValoare(string mesaj) {
		this->mesaj = mesaj;
	}
};

class SuperApartament :public Apartament {
private:
	int nrIntrari;
public:
	SuperApartament() :Apartament("Adresa", 2, new float[2]{23.4,29.4},2) {
		this->nrIntrari = 1;
	}
	SuperApartament(int nr):Apartament(),nrIntrari(nr) {
	}
	SuperApartament(int nrIntrari, string adresa, int nrCamere, float* suprafete, int etaj):Apartament(adresa,nrCamere,suprafete,etaj) {
		this->nrIntrari = nrIntrari;
	}
	SuperApartament(const SuperApartament& sa) :Apartament(sa) {
		this->nrIntrari = sa.nrIntrari;
	}

	SuperApartament operator=(const SuperApartament& sa) {
		Apartament::operator=(sa);
		this->nrIntrari = sa.nrIntrari;
		return *this;
	}
	~SuperApartament() {

	}

	int getNrIntrari() {
		return nrIntrari;
	}

	void setNrIntrari(int value) {
		if (value > 0) {
			nrIntrari = value;
		}
		else {
			throw ExceptieValoare("Parametru incorect");
		}
	}
};

ostream& operator<<(ostream& out,  SuperApartament& sa) {
	out << (Apartament)sa;
	out << sa.getNrIntrari();
	return out;
}

void main() {
	SuperApartament sa;
	//cout << sa.getNrIntrari()<<endl<<sa.getAdresa();
	Apartament a;
	a = sa;
	cout << sa<<a;
}