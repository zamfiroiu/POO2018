//Seminarul 7 - 15 noiembrie 2018
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
	Film operator=(const Film &f){      //operatorul egal --transmitere prin referinta ptc se doreste evitarea apelarii constr de copiere
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
			temp.numeActori[i] = f.numeActori[i-this->nrActori];
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


};

int Film::fps = 60;
void afisare(Film f) {
	cout << f.getTitlu() << endl;

}

void main()
{
	Film f;
	Film f2 = f;   //se apeleaza constructorul de copiere

	//afisare(f);

	Film f3;
	f3=f;  //se apeleaza constructorul egal


	Film f4 = f + f3;
	Film f5 = f + 2;
	Film f6 = 2 + f;  //se face in afara clasei
	

}