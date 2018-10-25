//Minoiu Maria-Magdalena seminarul 4 25.10.2018
#include<iostream>
#include<string>
using namespace std;
// un atribut static nu apartine obiectului
//atributele statice sunt definite in zona de memorie  a clasei, deci apartin clasei
class Carte {
public:
	const int idCarte;           //id ul fiecarei carti, nu se modifica niciodata
	const int codISBN;           //nu se modifica niciodata
	string titlu;
	unsigned int nrPagini;
	double pret;
	static double tva;           //este acelasi pt toate cartile
	static int nrExemplare;
	static int contor;

	Carte():idCarte(contor++),codISBN(1234){       //constructor;   initializarea constantelor se face la nivelul constructorului
		titlu = "Ion";
		pret = 20;
		nrPagini = 300;
		//contor++;
		nrExemplare++;

		/*idCarte = contor;
		codISBN = 1234;     <---eroare, un atribut constant nu se poate afla in stanga egalului*/
	}

	Carte(int isbn, string titlu, int nrPagini, double pret) :idCarte(contor++), codISBN(isbn) {   //constructor cu parametri
		this->titlu = titlu; 
		this->pret = pret;
		this->nrPagini = nrPagini;
		nrExemplare++;
	}

	Carte(string titlu, double pret) :idCarte(contor++), codISBN(0) {    // 0 <--valoare default
		nrPagini = 300;   // valoare default
		this->titlu = titlu;
		this->pret = pret;
		nrExemplare++;
	}


	void afisare()
	{
		cout << "ID : " << idCarte << ", ISBN : " << codISBN << ", TVA : " << tva << " %.";
		cout << titlu << " costa " << pret << " lei si are " << nrPagini << " pagini." << endl;
	}
};

//initializarea atributelor se face in afara clasei
double Carte::tva = 5;
int Carte::nrExemplare = 0;
int Carte::contor = 1;

void main()
{
	Carte c1;

	cout << c1.nrExemplare << endl;  //accesare prin intermediul unui obiect
	cout << Carte::tva << endl;   //accesare prin intermediul clasei

	Carte c2(3456,"Iona",80,10);      //apelare constructor cu parametri

	cout << c1.nrExemplare << endl;
	c1.afisare();
	c2.afisare();

	Carte* pc1=&c1;
	Carte* pc2 = new Carte(5678, "Mara", 200, 15);
	pc2->afisare();

	cout << Carte::nrExemplare << endl;   

	//Carte c3("Anna", 40);   <--eroare, nu are parametri suficienti. Rezolvare: se creaza constructor cu doar 2 parametri, titlu si pret
	
	Carte c3("Anna", 40);
	c3.afisare();

	delete pc2; //eliberarea memoriei pt pc2
}
//constructor=metoda care aloca spatiu pt atribute si initializeaza; are acelasi nume ca si clasa si nu are un tip returnat