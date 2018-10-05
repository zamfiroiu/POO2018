#include<iostream>

using namespace std;

	struct Spital {
		int nrMedici;
		float salariuMediu;
		//char retine 1 caracter , are un octet , un singur cod ascii retine
		// in pointer retin adresa de memorie a unei zone de memorie, pot declara un vector intr un char pointer
		char* denumire; // char* ocupa 4 octeti

	};

	void afisare(Spital s) {
		cout << s.denumire << " are " << s.nrMedici << " - " << s.salariuMediu << endl; 

	}


	void main() {
		int a = 8; //concateneaza 8.4 la 8
		cout << a << endl; //debug , punem breakpoint si el cauta un punct de pauza, ruleaza codul cautand pct ul de pauza si se opreste la el. 
						   //daca nu gaseste ruleaza tot codul si dispare
						   //structura = un sablon care uneste mai multe tipuri de date
		//int * b = &a;
		//cout << b; afiseaza adresa lui a
		Spital s;
		s.nrMedici = 5;
		s.salariuMediu = 3000;
		//s.denumire = "BABES" NU Merge deoarece nu am declarat o dimensiune a zonei de memorie
		// s.denumire=(char*) malloc(sizeof(char)/*are dimensiunea 1*/* strlen("Babes")+1) //determinam mai intai cat ocupa un caracter si apoi inmultim cu cate elemente avem si apoi punem +1 pentru /0                    //facem o conversie a lui s.denumire din void pointer la char pointer
		s.denumire = new char[strlen("Babes")+1];/*[]un vector, char * e pointer la pointer*/
		strcpy(s.denumire, "Babes"); //introduce in memorie pe babes
		afisare(s);
		delete[]s.denumire;        //dezalocam ce am alocat cu [] pentru un sir de caractere (vector)
}