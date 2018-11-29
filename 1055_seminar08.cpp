//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Film {
//	string titlu;
//	int nrActori;
//	string *numeActori;
//	static int fps;
//	const float id;//nu este unic;
//public:
//
//	Film operator=(const Film& f) {
//		this->titlu = f.titlu;
//		this->nrActori = f.nrActori;
//		delete[]this->numeActori;//evitare memory leaks
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = f.numeActori[i];
//		}
//		return *this;
//	}
//	Film(const Film &film) :id(film.id) {
//		this->titlu = film.titlu;
//		this->nrActori = film.nrActori;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = film.numeActori[i];
//		}
//	}
//	Film() :id(1) {
//		titlu = "Ion";
//		nrActori = 2;
//		numeActori = new string[nrActori];
//		numeActori[0] = "Ion";
//		numeActori[1] = "Ana";
//	}
//
//	Film(string titlu, int nrActori, string *numeActori, float idNou) :id(idNou) {
//		this->titlu = titlu;
//		this->nrActori = nrActori;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = numeActori[i];
//		}
//	}
//
//	~Film() {
//		delete[]numeActori;
//	}
//	void setTitlu(string titluNou) {
//		if (titluNou.length() > 3) {
//			titlu = titluNou;
//		}
//	}
//	string getTitlu() {
//		return titlu;
//	}
//
//	void setActori(int nrActori, string*numeActori) {
//		this->nrActori = nrActori;
//		delete[]this->numeActori;//evitare memory leak;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = numeActori[i];
//		}
//	}
//	int getNrActori() {
//		return nrActori;
//	}
//	string*getNumeActori() {
//		return numeActori;
//	}
//
//	string getNumeActor(int index) {
//		if (index >= 0 && index<nrActori)
//			return numeActori[index];
//		else {
//			return "";
//		}
//	}
//	void setFPS(int fps) {
//		this->fps = fps;
//	}
//
//	static int getFPS() {
//		return fps;
//	}
//
//	Film operator+(const Film& f) {
//		Film t = f;
//		t.nrActori = this->nrActori + f.nrActori;
//		delete[]t.numeActori;
//		t.numeActori = new string[t.nrActori];
//		for (int i = 0; i<this->nrActori; i++) {
//			t.numeActori[i] = this->numeActori[i];
//		}
//		for (int i = this->nrActori; i < t.nrActori; i++) {
//			t.numeActori[i] = f.numeActori[i - this->nrActori];
//		}
//		return t;
//	}
//
//	Film operator+(int nrActori) {
//		Film f = *this;
//		f.nrActori = this->nrActori + nrActori;
//		delete[]f.numeActori;
//		f.numeActori = new string[f.nrActori];
//		for (int i = 0; i < this->nrActori; i++) {
//			f.numeActori[i] = this->numeActori[i];
//		}
//		for (int i = this->nrActori; i < f.nrActori; i++) {
//			f.numeActori[i] = "Figurant";
//		}
//		return f;
//	}
//
//	Film operator++() {
//		this->operator+(1);
//		(*this) = (*this) + 1;
//		return *this;
//	}
//
//	Film operator++(int) {
//		Film t = *this;
//		(*this) = (*this) + 1;
//		return t;
//	}
//
//	explicit operator int() {
//		//numarul de carcatere din numele tuturor actorilor
//		int s = 0;
//		for (int i = 0; i < nrActori; i++) {
//			s += numeActori[i].length();
//		}
//		return s;
//	}
//
//	bool operator==(Film f) {
//		return this->nrActori == f.nrActori;
//	}
//
//	string& operator[](int pozitie) {
//		return this->getNumeActor(pozitie);
//		return this->numeActori[pozitie];
//	}
//
//	int operator()() {
//		return this->nrActori;
//	}
//
//	void operator()(int val) {
//		(*this) = (*this) + val;
//	}
//
//	friend int operator+(int val, Film f);
//	friend ostream& operator<<(ostream& afisare, Film f);
//	friend istream& operator>>(istream& tasta, Film& f);
//};
//
//int Film::fps = 60;
//
//int operator+(int val, Film f) {
//	return val + f.nrActori;
//}
//
//void afisare(Film f) {
//	cout << f.getTitlu() << endl;
//}
//
//ostream& operator<<(ostream& afisar, Film f) {
//	afisar << f.titlu << endl;
//	afisar << f.nrActori << ": ";
//	for (int i = 0; i < f.nrActori; i++) {
//		afisar << f.numeActori[i] << ",";
//	}
//	return afisar;
//}
//
//istream& operator>>(istream& tasta, Film& f) {
//	cout << "Titlu filmului:";
//	tasta >> f.titlu;
//	cout << "Nr actori:";
//	tasta >> f.nrActori;
//	delete[]f.numeActori;
//	f.numeActori = new string[f.nrActori];
//	for (int i = 0; i < f.nrActori; i++) {
//		cout << "Nume actor " << i << ": ";
//		tasta >> f.numeActori[i];
//	}
//	return tasta;
//}
//
//void main() {
//	Film f;
//
//	Film f2 = f;
//	//afisare(f);
//	Film f3;
//	f2=f3 = f;
//
//	Film f4 = f + f3;
//	Film f5 = f + 2;
//	int numar = 2 + f;
//
//	f2 = f++;
//
//	int numar2 =(int)f;
//
//	cout << f<<f2;
//	cin >> f;
//	Film f;
//	Film f2;
//	cin >> f;
//	cout << f;
//
//	if (f == f2)
//		cout << "sunt egale";
//
//	cout << f[0];
//	f[0] = "Popescu";
//
//	cout << f();
//	f(2);
//}