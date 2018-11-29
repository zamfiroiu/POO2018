#include<iostream>
#include<string>

using namespace std;

class Telefon {
private:
	const int cod;//nu este unic
	static int tva;
	string model;
	int nrSenzori;
	double * pretSenzori;
public:
	Telefon() :cod(0), nrSenzori(2) {
		model = "Samsung";
		pretSenzori = new double[nrSenzori];
		pretSenzori[0] = 100;
		pretSenzori[1] = 130;
	}

	Telefon(string model, int nrSenzori, double *pretSenzori,
		int codNou) :cod(codNou) {

		this->model = model;
		this->nrSenzori = nrSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = pretSenzori[i];
		}
	}
	~Telefon() {
		delete[]pretSenzori;
	}

	string getModel() {
		return this->model;
	}
	void setModel(string model) {
		if (model.length() > 0) {
			this->model = model;
		}
	}

	void setNrSenzori(int nrSenzori, double *pretSenzori) {
		this->nrSenzori = nrSenzori;
		delete[] this->pretSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = pretSenzori[i];
		}
	}

	int getNrSenzori() {
		return nrSenzori;
	}
	double* getPretSenzori() {
		return pretSenzori;
	}

	double getPretSenzorPozitie(int index) {
		if (index >= 0 && index < nrSenzori) {
			return this->pretSenzori[index];
		}
		else {
			throw "index incorect";
		}
	}

	static int getTVA() {
		return tva;
	}

	Telefon(const Telefon& t) :cod(t.cod) {
		this->model = t.model;
		this->nrSenzori = t.nrSenzori;
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = t.pretSenzori[i];
		}
	}

	Telefon operator=(const Telefon &t) {
		this->model = t.model;
		this->nrSenzori = t.nrSenzori;

		if (this->pretSenzori != NULL) {
			delete[]this->pretSenzori;//evit apartia de memory leaks
		}
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++) {
			this->pretSenzori[i] = t.pretSenzori[i];
		}
		return *this;
	}

	Telefon operator+(const Telefon& t) {
		Telefon temp = *this;
		//temp.nrSenzori = this->nrSenzori + t.nrSenzori;
		temp.nrSenzori += t.nrSenzori;
		delete[]temp.pretSenzori;
		temp.pretSenzori = new double[temp.nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++) {
			temp.pretSenzori[i] = this->pretSenzori[i];
		}
		for (int i = this->nrSenzori; i < temp.nrSenzori; i++) {
			temp.pretSenzori[i] = t.pretSenzori[i - this->nrSenzori];
		}
		return temp;
	}

	Telefon operator+(int nrSenzori) {
		Telefon t = *this;
		t.nrSenzori += nrSenzori;
		delete[]t.pretSenzori;
		t.pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++) {
			t.pretSenzori[i] = this->pretSenzori[i];
		}
		for (int i = this->nrSenzori; i < t.nrSenzori; i++) {
			t.pretSenzori[i] = 1;
		}

		return t;
	}

	//preincrementare
	Telefon operator++() {
		for (int i = 0; i < this->nrSenzori; i++) {
			this->pretSenzori[i]++;
		}
		return *this;
	}

	//postincrementare
	Telefon operator++(int) {
		Telefon temporar = *this;
		for (int i = 0; i < this->nrSenzori; i++) {
			this->pretSenzori[i]++;
		}
		return temporar;
	}

	double calcularePretTotal() {
		double s = 0;
		for (int i = 0; i<this->nrSenzori; i++) {
			s += this->pretSenzori[i];
		}
		return s;
	}

	bool operator>(Telefon t) {
		return this->calcularePretTotal() > t.calcularePretTotal();
	}

	double& operator[](int index) {
		if (index >= 0 && index < nrSenzori) {
			return this->pretSenzori[index];
		}
		else {
			throw "index incorect";
		}
	}

	double operator()() {
		return calcularePretTotal();
	}

	explicit operator int() {
		return this->nrSenzori;
	}
	explicit operator float() {
		return calcularePretTotal();
	}

	friend ostream& operator<<(ostream& os, const Telefon& t);
	friend istream& operator>>(istream& os, Telefon& t) {
		cout << "Model telefon:";
		os >> t.model;
		cout << "Numar senzori:";
		os >> t.nrSenzori;
		delete[]t.pretSenzori;
		t.pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < t.nrSenzori; i++) {
			cout << "Pretul " << i << ":";
			os >> t.pretSenzori[i];
		}
		return os;
	}
};

int Telefon::tva = 19;

int operator+(int nr, Telefon t) {
	return nr + t.getNrSenzori();
}


void afisareModel(Telefon t) {
	cout << t.getModel() << endl;
}

ostream& operator<<(ostream& os, const Telefon& t) {
	os << t.model << " "<<t.nrSenzori<<":";
	for (int i = 0; i < t.nrSenzori; i++) {
		os << t.pretSenzori[i] << ", ";
	}
	os << endl;
	return os;
}

void main() {
	Telefon t;
	cout << t[0];
	t[0] = 13;

	float a = 5.9;
	int b = a;

	b = (int)t;//nr senzori
	a = (float)t;//pret total senzori;

	Telefon t2;
	cin >> t2;
	cout << t<<t2;
	Telefon **pv;
	pv = new Telefon*[2];
	pv[0] = new Telefon();
	pv[1] = new Telefon[2];
}