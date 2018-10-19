//18.10.2018 Minoiu Maria-Magdalena

#include<iostream>
#include<string>

using namespace std;

class Telefon       //numele clasei este de obicei substantiv
{
public:              //atributele devin publice
	string marca;
//private:
	int memorie;     //marca, memorie si pret sunt atribute = caracteristici ale unui obiect
//protected:
	float pret;

	void modificarePret()
	{
		pret = 8000;
		//Telefon t;
		//t.pret = 8000;  
	}

	void printare()  //poate sa se numeasca si afisare
	{
		cout << marca << " are " << memorie << " GB si costa " << pret <<" de lei."<< endl;
	}
};

//spre deosebire de structuri, atributele sunt private, adica sunt accesibile doar in interiorul clasei
void afisare(Telefon t)
{
	cout << t.marca << " are o memorie de " << t.memorie << " GB si costa " << t.pret << " de lei." << endl;
}
void main()
{
	Telefon t;        //declararea unui obiect de tipul telefon; obiectul este o instanta a clasei
	//Telefon t2;      //pot exista mai multe obiecte din aceeasi clasa
	
	t.marca = "Samsung";
	t.memorie = 2;
	t.pret = 2000;

	Telefon * pt;             //pointer telefon
	pt = new Telefon();       //paranteze rotunde ptc vrem un sg telefon
	
	(*pt).marca = "Apple";     //se pun paraneze pt a trece peste ierarhizarea prestabilita
	pt->memorie = 4;          //echivalent cu (*pt).memorie=4;
	pt->pret = 4000;


	//cout << t.marca << " are " << t.memorie << " GB si costa " << t.pret <<" de lei."<< endl;
	//cout << pt->marca << " are " << pt->memorie << " GB si costa " << pt->pret << " de lei." << endl;
	// nu este indicat sa avem aceeasi secventa de cod; este indicat sa facem o functie special pt afisare

	afisare(t);
	afisare(*pt);

	cout << endl;

	t.printare();      //la metode parametrul la care apelam este dat prin referire
	pt->printare();

	cout << endl;

	//apelarea 1
	pt->modificarePret();
	t.printare();      
	pt->printare();


	//apelarea 2
	cout << endl<<"Dupa modificare" << endl;
	t.modificarePret();
	t.printare();   //nu se modifica ptc se modifica doar in interiorul clasei, datele se sterg dupa terminare
	pt->printare();
//lipsesc vectorii deobiecte si pointeri la Telefon
//zona de memorie alocata pentru pointer trebuie stearsa.
}

//functia este declarata global
//metoda este declarata in clasa