//operatorul +

#include <iostream>
#include<string>
using namespace std;

class Dispozitiv
{
private:
	float pretBaza;
public:

	Dispozitiv(float pret) :pretBaza(pret) {} //constructor
	float getpretBaza() //getter
	{
		return pretBaza;
	}

	void setPretBaza(float value) //setter
	{
		if (value > 0)
			pretBaza = value;
	}


	virtual float getPretMagazin() = 0; //fct virtual pura= aceasta metoda poate fi suprascrisa in clasele care mostenesc aceasta clasa
										//virtual pura e cand = 0
										//e ca un fel de pointer la this acel virtual
	virtual void afisare() = 0;
	virtual ~Dispozitiv(){
		cout << "S-a apelat Destructorul din clasa Dispozitiv"<<endl;
	}

};
 ostream& operator<<(ostream& os, Dispozitiv &o) {
	os << o.getpretBaza();
	return os;
}



class Telefon :public Dispozitiv
{
private:
	const int cod; //nu este unic
	static int TVA;
	string model;
	int nrSenzori;
	double *pretSenzori;
public:

	float getPretMagazin()
	{
		return this->getpretBaza() + this->calcularePretTota();
	}

	Telefon() : cod(0), nrSenzori(2), Dispozitiv(10)							//creeaza o instanta a clasei,aloca si initializeaza(constructor fara param.); initializarea const
	{
		model = "Samsung";
		pretSenzori = new double[nrSenzori]; //aloc mem pt vect de preturi
		pretSenzori[0] = 100;
		pretSenzori[1] = 130;
	}

	Telefon(string model, int nrSenzori, double*pretSenzori, int CodNou) :cod(CodNou), Dispozitiv(10)	 //constructori cu parametri 
	{
		this->model = model;
		this->nrSenzori = nrSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++)
		{
			this->pretSenzori[i] = pretSenzori[i];
		}
	}
	~Telefon()
	{
		delete[] pretSenzori;
		cout << "S-a apelat Destructorul din clasa Telefon" << endl;
	}
	string getModel() //get
	{
		return model;
	}
	void setModel(string model) //set
	{
		if (model.length() > 0)

			this->model = model;
	}

	void setNrSenzori(int nrSenzori, double *pretSenzori)
	{
		this->nrSenzori = nrSenzori; //atribuim valoarea la atribut 
		delete[] this->pretSenzori;
		this->pretSenzori = new double[nrSenzori];
		for (int i = 0; i < nrSenzori; i++)
		{
			this->pretSenzori[i] = pretSenzori[i];
		}
	}

	int getNrSenzori() //fara parametrii deoarece e getter
	{
		return nrSenzori;
	}
	double* getPretSenzori()
	{
		return pretSenzori;
	}

	double getPretSenzorPozitie(int index) //getter cu parametru,exceptie
	{
		if (index >= 0 && index < nrSenzori)
		{
			return this->pretSenzori[index];
		}
		else
		{
			throw "Index incorect!"; //trateaza exceptia, indexul este in afara limitei; afiseaza mesaj
			//daca ajunge aici se intrerupe metoda si se apeleaza in programul pricipal
		}
	}

	static 	int getTVA() //nu poate referi un atribut in interior
	{
		//return this->TVA;
		return TVA;
	}
	Telefon(const Telefon& t) :cod(t.cod), Dispozitiv(10)
	{
		this->model = t.model;
		this->nrSenzori = t.nrSenzori;
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++)
		{
			this->pretSenzori[i] = t.pretSenzori[1];
		}
	}

	Telefon operator=(const Telefon &t)
	{
		this->model = t.model;
		this->nrSenzori = nrSenzori;


		if (this->pretSenzori != NULL)
		{
			delete[]this->pretSenzori; //evit aparitia de memory leak 
		}
		this->pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < nrSenzori; i++)
		{
			this->pretSenzori[i] = t.pretSenzori[i];
		}
		return *this;
	}

	Telefon operator+(const Telefon& t)    // operatorul + 
	{
		Telefon temp = *this;
		//temp.nrSenzori= this->nrSenzori +t.nrSenzori;
		temp.nrSenzori += t.nrSenzori;
		delete[] temp.pretSenzori;
		temp.pretSenzori = new double[temp.nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++)
		{
			temp.pretSenzori[i] = this->pretSenzori[i];
		}

		for (int i = this->nrSenzori; i < temp.nrSenzori; i++)
		{
			temp.pretSenzori[i] = t.pretSenzori[i - this->nrSenzori];
		}
		return temp;
	}

	Telefon operator+ (int nrSenzori) //vrem sa 
	{
		Telefon t = *this;
		t.nrSenzori += nrSenzori;
		delete[]t.pretSenzori; //dezalocam vectorul
		t.pretSenzori = new double[t.nrSenzori]; //alocam

		for (int i = 0; i < this->nrSenzori; i++)
		{
			t.pretSenzori[i] = this->pretSenzori[i];
		}

		for (int i = this->nrSenzori; i < t.nrSenzori; i++)
		{
			t.pretSenzori[i] = 1;
		}
		return t;
	}

	Telefon operator++() //implementam preincrementarea
		//modificam preturile tuturor senzorilor; toate preturile cresc cu o unitate
	{
		for (int i = 0; i < this->nrSenzori; i++)
		{
			this->pretSenzori[i]++;
		}
		return *this;
	}

	Telefon operator++(int) //implementam postincrementare
		//s-a facut o convensie ca sa se decida ca la post inclementare se va pune un parametru de timp int pe care nu-l vom folosi dar il punem ca sa vedem ca acolo e postincrementare
	{
		Telefon temporar = *this;
		for (int i = 0; i < this->nrSenzori; i++)
		{
			this->pretSenzori[i]++;
		}
		return temporar;
	}
	//PT EXAMNE: 75% SANSE SA PICE POST/PRE INCREMENTARE OPERATORII ASA CA SUNT DEI NVATAT. MAI ALES POST

	double calcularePretTota()
	{
		double s = 0;
		for (int i = 0; i < this->nrSenzori; i++)
		{
			s += this->pretSenzori[i];
		}
		return s;
	}

	bool operator>(Telefon t) //functie pt a compara t1 cu t3 din main
	{
		return this->calcularePretTota() > t.calcularePretTota();
	}

	double & operator[](int index) //returneaza dintr-un anumit fisier vectorul suma ceruta
	{

		if (index >= 0 && index < nrSenzori)
		{
			return this->pretSenzori[index];
		}
		else
		{
			throw "Index incorect!"; //trateaza exceptia, indexul este in afara limitei; afiseaza mesaj
			//daca ajunge aici se intrerupe metoda si se apeleaza in programul pricipal
		}
	}

	double operator()() { //metoda se cheama operator() de asta exista doua ()()
		return calcularePretTota();
	}

	explicit operator int() //mereu va returna int //operator de cast care converteste int in telefon sau chestii de genu
	{
		return this->nrSenzori;
	}
	explicit operator float()
	{
		return calcularePretTota();
	}

	friend  ostream& operator <<(ostream& os, const Telefon& t);
	friend istream& operator >>(istream& os, Telefon& t) //fara const pt ca ne dorim sa modificam telefon t
	{
		cout << "Model telefon: ";
		os >> t.model;
		cout << "Nr senzori: ";
		os >> t.nrSenzori;
		delete[]t.pretSenzori;
		t.pretSenzori = new double[t.nrSenzori];
		for (int i = 0; i < t.nrSenzori; i++)
		{
			cout << "Pretul: " << i << ":";
			os >> t.pretSenzori[i];
		}
		return os;
	}

	void afisare() {
		cout << *this;
	}
};
int Telefon::TVA = 19; //initializarea staticului in afara clasei cu operatorul de rezolutie


int operator+ (int nr, Telefon t) //incercam sa punem
{
	return nr + t.getNrSenzori();
}

void afisareModel(Telefon t)
{
	cout << t.getModel() << endl;
}

ostream& operator <<(ostream& os, const Telefon& t) //os e numele, pot sa pun ce vreau eu; const pt ca vrem sa il afisam nu sa il si modificam //os are functie de cout dar e dif pt ca daca am folosi cout si as vrea sa afisam o inf pe tastatura,
{
	os << t.model << " " << t.nrSenzori;
	for (int i = 0; i < t.nrSenzori; i++)
	{
		os << t.pretSenzori[i] << " , ";
	}
	os << endl;
	return os;
}


class ParametruExceptie
{
public:
	string mesajExceptie;
	ParametruExceptie(string val) //constructor
	{
		mesajExceptie = val;
	}
};





class Smartphone :public Telefon //aici vom trece clasa pe care o mostenim; public adica tot ce luam de la telefon se pune in zona public a smartphone ul
							//relatua de IS A (un smatphone IS A telefon)
{
private:
	float diagonala;
public:

	float getPretMagazin()
	{
		return this->diagonala * 10 + Telefon::getPretMagazin();
	}


	Smartphone() :Telefon("model", 2, new double[2]{ 10.9,17.5 }, 1) //constructor dara parametri la smxartphone caruia ii e atribuit cel cu parametri de la telefon
	{
		this->diagonala = 4.0;

	}

	Smartphone(float diag) :Telefon(), diagonala(diag)
	{

	}

	Smartphone(string model, int nrSenzori, double* preturi, int cod, float diagonala) : Telefon(model, nrSenzori, preturi, cod)
	{
		this->diagonala = diagonala;
	}
	Smartphone(const Smartphone& sp) :Telefon(sp)		//constr de copiere
	{
		this->diagonala = sp.diagonala;
	}

	float getDiagonala()
	{
		return diagonala;
	}

	void setDiagonala(float valoare)
	{
		if (valoare > 3)
		{
			diagonala = valoare;
		}
		else
		{
			throw ParametruExceptie("Valoare parametru incorecta.");
		}
	}

	~Smartphone()		//destructor; prima data se apeleaza estructorul de la clasa fiu, dupaia cel din clasa parinte; daca nu scriem desteructorul, el va fi apelat obligatoriu
	{

	}

	Smartphone operator= (const Smartphone &sp)
	{
		Telefon::operator=(sp); //copiem to ce aceam din telefon
		this->diagonala = sp.diagonala;
		return *this;
	}
};


ostream & operator<<(ostream & out, Smartphone& sp)
{
	out << (Telefon)sp; //se va cauta un operator << care sa primeasca un atribut telefon adica <<de la telefon
	out << sp.getDiagonala();
	return out;
}


class Magazin {
private:
	string numeMagazin;
	Dispozitiv ** dispozitive;
	int nrDispozitive;

public:
	Magazin() {
		this->numeMagazin = "Anonim";
		this->dispozitive = NULL;
		this->nrDispozitive = 0;
 }

	Magazin(string n, Dispozitiv ** d, int nr)
	{
		this->numeMagazin = n;
		this->nrDispozitive = nr;
		this->dispozitive = new Dispozitiv*[nrDispozitive];
		for (int i = 0; i < nrDispozitive; i++)
		{
			this->dispozitive[i] = d[i];
		}
	
	}
	Magazin(const Magazin& m) {
		this->numeMagazin = m.numeMagazin;
		this->nrDispozitive = m.nrDispozitive;
		this->dispozitive = new Dispozitiv*[m.nrDispozitive];
		for (int i = 0; i < m.nrDispozitive; i++) {
			this->dispozitive[i] = m.dispozitive[i];
		}
	}
	Magazin operator=(const Magazin &m) {
		this->numeMagazin = m.numeMagazin;
		this->nrDispozitive = m.nrDispozitive;
		if (this->dispozitive != NULL) delete[]this->dispozitive;
		this->dispozitive = new Dispozitiv*[nrDispozitive];
		for (int i = 0; i < nrDispozitive; i++) {
			this->dispozitive[i] = m.dispozitive[i];
		}
		
		return *this;
	}
	~Magazin()
	{
		if (this->dispozitive != NULL)
			delete[] this->dispozitive;

	}
	Dispozitiv*& operator[](int index) {
		if (index >= 0 && index < nrDispozitive)
			return dispozitive[index];
		else throw ParametruExceptie("parametru incorect");
	}

	friend ostream& operator<<(ostream& os, Magazin m){
		os << m.numeMagazin;
		os << m.nrDispozitive<<endl;
		for (int i = 0; i < m.nrDispozitive; i++)
		{
			m.dispozitive[i]->afisare();
		}
		return os;
	}
};

void main()
{
Telefon t;

t.getPretBaza();

Dispozitiv d;

d.getPretBaza();


}