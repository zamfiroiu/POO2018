//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Productie {
//private:
//	float costProductie;
//public:
//	Productie(float cost) :costProductie(cost){
//	}
//	virtual float getCostProductie() {
//		return costProductie;
//	}
//	void setCostProductie(float value) {
//		if (value > 0) {
//			costProductie = value;
//		}
//	}
//	virtual int ActoriCareJoaca() = 0;
//};
//
//class Film:public Productie {
//	string titlu;
//	int nrActori;
//	string *numeActori;
//	static int fps;
//	const float id;//nu este unic;
//public:
//	float getCostProductie() {
//		return Productie::getCostProductie() + 10 * this->nrActori;
//	}
//	int ActoriCareJoaca() {
//		return getNrActori();
//	}
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
//	Film(const Film &film) : Productie(1000),id(film.id) {
//		this->titlu = film.titlu;
//		this->nrActori = film.nrActori;
//		this->numeActori = new string[nrActori];
//		for (int i = 0; i < nrActori; i++) {
//			this->numeActori[i] = film.numeActori[i];
//		}
//	}
//	Film() :Productie(1000),id(1) {
//		titlu = "Ion";
//		nrActori = 2;
//		numeActori = new string[nrActori];
//		numeActori[0] = "Ion";
//		numeActori[1] = "Ana";
//	}
//
//	Film(string titlu, int nrActori, string *numeActori, float idNou) :Productie(1000),id(idNou) {
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
//		//return this->getNumeActor(pozitie);
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
//class ExceptieParametru {
//public:
//	string mesaj;
//	ExceptieParametru(string mesaj) {
//		this->mesaj = mesaj;
//	}
//};
//
//class Scurtmetraj :public Film {
//private:
//	int durata;
//public:
//	float getCostProductie() {
//		return Film::getCostProductie() + 100 * this->durata;
//	}
//	int getDurata() {
//		return durata;
//	}
//	void setDurata(int value) {
//		if (value > 1) {
//			durata = value;
//		}
//		else {
//			throw new ExceptieParametru("parametru incorect");
//		}		
//	}
//	Scurtmetraj() :Film("ScurtMetraj", 2, new string[2]{"Popescu","Ionescu"},2) {
//		durata = 10;
//	}
//	Scurtmetraj(int durataN):Film(),durata(durataN){}
//
//	Scurtmetraj(int durata, string titlu, int nrActori, string*numeActori, int id) :Film(titlu, nrActori, numeActori, id) {
//		this->durata = durata;
//	}
//
//	Scurtmetraj(const Scurtmetraj & sm) :Film(sm) {
//		this->durata = sm.durata;
//	}
//	Scurtmetraj operator=(const Scurtmetraj sm) {
//		Film::operator=(sm);
//		this->durata = sm.durata;
//		return *this;
//	}
//
//	~Scurtmetraj() {
//
//	}
//
//};
//
//ostream& operator<<(ostream& monit,  Scurtmetraj& sm) {
//	monit << (Film)sm;
//	monit << sm.getDurata();
//	return monit;
//}
//
//void main() {
//	Productie* p;
//	Film *f;
//	p = new Film();
//	Scurtmetraj s;
//	//cout << p->getCostProductie()<<endl;
//	p = &s;
//	f = &s;
//	cout << f->getCostProductie();
//
//	Productie* *vp;
//	Productie *vps[4];
//	vp = new Productie*[4];
//	for (int i = 0; i < 2; i++) {
//		vp[i] = new Film("Titlu", 2, new string[2]{ "Ion","Ana" }, 1);
//	}
//
//	for (int i = 2; i < 4; i++) {
//		vp[i] = new Scurtmetraj((i + 1) * 10, "Titlu", 2, new string[2]{ "Ion","Ana" }, 1);
//	}
//	cout << endl;
//	for (int i = 0; i < 4; i++) {
//		cout << vp[i]->getCostProductie() << " ";
//	}
//
//
//}