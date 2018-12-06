// SEMINARUL 9 29.11.2018
#include<iostream>
#include<string>
using namespace std;

class Film {

	string titlu;
	int nrActori;
	string* numeActori;  //vector de nume
	static int fps;
	const float id;  //nu este unic

public:
	Film operator=(const Film &f) {      //operatorul egal --transmitere prin referinta ptc se doreste evitarea apelarii constr de copiere
		this->titlu = f.titlu;
		this->nrActori = f.nrActori;
		delete[]this->numeActori;       //evitare memory-leaks
		this->numeActori = new string[nrActori];
		for (int i = 0; i < nrActori; i++) {
			this->numeActori[i] = f.numeActori[i];
		}
		return *this;   //se face deferentierea

	}



	Film(const Film &film) :id(film.id) {    //constructor de copiere
		this->titlu = film.titlu;
		this->nrActori = film.nrActori;
		this->numeActori = new string[nrActori];
		for (int i = 0; i < nrActori; i++) {
			this->numeActori[i] = film.numeActori[i];
		}

	}


	Film() :id(1) {
		titlu = "Ion";
		nrActori = 2;
		numeActori = new string[nrActori];
		numeActori[0] = "Ion";
		numeActori[1] = "Ana";
	}
	Film(string titlu, int nrActori, string* numeActori, float idNou) :id(idNou) {
		this->titlu = titlu;
		this->nrActori = nrActori;
		this->numeActori = new string[nrActori];
		for (int i = 0; i < nrActori; i++)
			this->numeActori[i] = numeActori[i];
	}
	~Film() {
		delete[]numeActori;
	}
	void setTitlu(string titluNou) {
		if (titluNou.length() > 3) {
			titlu = titluNou;      //set este o metoda care acceseaza si modifica atributele din zona privata
		}
	}
	string getTitlu() {
		return titlu;     //get este o metoda care acceseaza atributele din zona privata
	}
	void setActori(int nrActori, string* numeActori) {
		this->nrActori = nrActori;
		delete[]this->numeActori;   //stergem vechiul vector --- evitare memory leak
		this->numeActori = new string[nrActori];  //noul vector
		for (int i = 0; i < nrActori; i++)
			this->numeActori[i] = numeActori[i];

	}

	int getNrActori()
	{
		return nrActori;
	}
	string*getNumeActori()
	{
		return numeActori;
	}
	string getNumeActor(int index)  //returnarea unui singur actor
	{
		if (index >= 0 && index < nrActori)
			return numeActori[index];
		else
			return "";
	}
	void setFPS(int fps) {
		this->fps = fps;
	}
	static int getFPS() {  //functie statica lucreaza doar cu atributele statice
		return fps;

	}
	Film operator+(const Film &f) {
		Film temp = f;  //apelare constr de copiere
		temp.nrActori = this->nrActori + f.nrActori;
		delete[]temp.numeActori;  //dezalocarea spatiului alocat de constructorul de copiere de mai sus
		temp.numeActori = new string[temp.nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			temp.numeActori[i] = this->numeActori[i];
		}
		for (int i = this->nrActori; i < temp.nrActori; i++) {
			temp.numeActori[i] = f.numeActori[i - this->nrActori];
		}
		return temp;

	}
	Film operator+(int nrActori) {
		Film f = *this;
		f.nrActori = this->nrActori + nrActori;
		delete[]f.numeActori;
		f.numeActori = new string[f.nrActori];
		for (int i = 0; i < this->nrActori; i++) {
			f.numeActori[i] = this->numeActori[i];
		}
		for (int i = this->nrActori; i < f.nrActori; i++) {
			f.numeActori[i] = "Figurant";
		}
		return f;

	}
	Film operator++() // preincrementare 
	{
		//this->nrActori++;
		//this->operator+(1);
		(*this) = (*this) + 1;
		return *this;
	}

	Film operator++(int) {      //post incrementare primeste un param de tip int pt a asigura polimorfisul dintre cele 2
		Film t = *this;          // constructorul de copiere
		(*this) = (*this) + 1;      // "--" va decrementa ; este exact la fel
		return t;                 // returneaza starea initiala(=2) this=3 
	}

	//operatorul cast:
	/*explicit*/operator int() {     // nr de caratctere din numele tuturor actorilor folodint explicit suntem obligati sa folosim =(int)f;
		int s = 0;
		for (int i = 0; i < nrActori; i++)
			s += numeActori[i].length();
		return s;
	}

	bool operator==(Film f) {
		return this->nrActori == f.nrActori; //<= si >=
	}

	string& operator[](int pozitie) {     //operatorul index
		//return this->getNumeActor(pozitie);
		return this->numeActori[pozitie];
	}


	int operator()() {
		return this->nrActori;
	}

	void operator()(int val) {
		(*this) = (*this) + val;
	}



	friend ostream& operator<<(ostream& monitor, Film f);
	friend int operator+(int val, Film f); // pt a avea acces din afara 
	friend istream&operator>>(istream& in, Film &f);
};


int Film::fps = 60;
int operator+(int val, Film f)// in afara clase deoarece ne pune 3 parametri daca este metoda avand si operatorul this
{
	//return val + f.getNrActori();
	return val + f.nrActori; // am declarat in clasa friend int operator+(int val, Film f) si avem acces la atributul nrActori din clasa
}

ostream& operator<<(ostream& monitor, Film f) // fara referinta pt ca doar le accesam
{
	monitor << f.titlu << endl;
	monitor << f.nrActori << ":";
	for (int i = 0; i < f.nrActori; i++)
	{
		monitor << f.numeActori[i] << ";";
	}
	return monitor;
}
istream&operator>>(istream& in, Film &f)// cu referinta la f pt ca le modificam
{
	cout << "Titlu film:";
	in >> f.titlu;
	cout << "numar actori:";
	in >> f.nrActori;
	delete[]f.numeActori;
	f.numeActori = new string[f.nrActori];
	for (int i = 0; i < f.nrActori; i++)
	{
		cout << "numele actorului" << i << ":";
		in >> f.numeActori[i];
	}
	return in;


}



void afisare(Film f) {
	cout << f.getTitlu() << endl;

}
class ExceptieParametru {
public:
	string mesaj;
	ExceptieParametru(string mesaj) {
		this->mesaj = mesaj;
	}
};

class Scurtmetraj :public Film {  //clasa derivata din clasa film
private:
	int durata;
public:
	int getDurata() {
		return durata;
	}
	void setDurata(int value) {
		if (value > 1) {
			durata = value;
		}
		else {
			throw new ExceptieParametru("Parametru incorect");  //aruncam un pointer la ExceptieParametru
		}

	}
	Scurtmetraj() :Film("Scurtmetraj", 2, new string[2]{ "Popescu","Ionescu" }, 2) {   //apelam constructorul cu parametri al clasei film(se putea apela si cel fara parametri)
		durata = 10;
	}
	Scurtmetraj(int durataNoua) :Film(), durata(durataNoua) {}   //apelare constr fara parm, am initializat tot in anten si de aceea e gol

	Scurtmetraj(int durata, string titlu, int nrActori, string * numeActori, float id) :Film(titlu, nrActori, numeActori, id) {
		this->durata = durata;
	}
	//constr de copiere:
	Scurtmetraj(const Scurtmetraj &sm) :Film(sm) { //up casting; se face by default -- down casting ul nu este by default
		this->durata = sm.durata;
	}
	//op egal
	Scurtmetraj operator =(const Scurtmetraj sm) {
		Film::operator=(sm);    //copiaza sm in this
		this->durata = sm.durata;
		return *this;
	}
	~Scurtmetraj() {}  //nu e nevoie sa apelam destructorul din clasa Film ptc se apeleaza automat
	
};
ostream &operator<<(ostream &monit, Scurtmetraj &sm) {
	monit << (Film)sm;
	monit << sm.getDurata();
	return monit;

}
void main()
{
	Scurtmetraj sm1(16);
	Scurtmetraj sm2(18, "Sinucide-ma", 4, new string[4]{ "Cheloo","Mark","Andrei","Mircea" }, 1);

	cout << sm1.getDurata(); //afiseaza 16
	cout << sm1.getTitlu();  //afiseaza Ion
	cout << sm2.getTitlu();  //afiseaza Sinucide-ma

	Film f;
	f = sm1;
	//cout << f.getDurata();  --eroare, clasa Film nu are metoda getDurata()

	cout << endl; //Sinucide-ma
	cout << sm2 << endl; 

	//diferenta dintre erori si exceptii este faptul ca exceptiile pot fi captate si tratate
	try {  //se incearca executia codului din interior
		sm1.setDurata(-1);
	}
	catch (Film f) {  //capteaza exceptia

	}
	catch (ExceptieParametru *ep) {
		cout << ep->mesaj;  //Parametru incorect
	}
	catch (...) { //catch general

	}
	cout <<endl<<5<<endl;  //se afiseaza 5 ptc s-a tratat eroarea



}
//in C++ pot sa am mai multe clase pe care le mostenesc; mostenire multipla
//mostenire= ne folosim de ceva face pt a creea ceva nou