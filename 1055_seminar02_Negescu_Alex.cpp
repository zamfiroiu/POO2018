//11.10.2018
#include <iostream>
#include <string>      //biblioteca necesara lucrului cu string
using namespace std;

//String= sir de caractere
//in interiorul clasi string exista si functii de prelucrare

int cautaMinim(int *v, int n)
{
	int index_minim = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[index_minim])
			index_minim = i;
	}
	return index_minim;
}
void stergerePozitiecuMinim(int * &v, int &n,int index)
{
	int *aux = new int[n - 1];  //se creaza un vector auxiliar
	int j=0;   //dimensiunea vectorului aux
	for (int i = 0; i < n; i++)
	{
		if (i != index)
		{
			aux[j] = v[i];
			j++;
		}

	}

	delete[]v; //se elibereaza memoria
	v = aux;  //atribuirea de adrese--- se atribuie vechii adrese a vectorului sters noua adresa a noului vector
	n--;  //modificarea dimensiunii vectorului

	   
}
void stergeMinim(int * &v, int &n)   //&-transmiterea parametrilor prin referinta(ia adresa)
{
	//cautam indexul pt val minima din vector
	int index = cautaMinim(v, n);
	//stergem elementul de pe indexul gasit prin copierea urmatoarelor elemente
	//modificam dimensiunea vectorului
	stergerePozitiecuMinim(v, n, index);
	   
}
void main()
{
	string sir = "Seminar 02";      //un string poate fi initializat direct pe baza unei constante
	sir = "seminar 2";

	//sir += "-pointeri";   ----adauga sirul "-pointeri" la sirul "seminar 2"; le concateneaza
	sir.append("-pointeri");     //echivalent cu sir += "-pointeri";
	cout << sir << endl;

	//sir.find('-');   ---cautarea caracterului '-'; returneaza pozitia unde se afla '-'
	//sir.rfind('e');  ---cauta de la sfarsit

	string sir2=sir.substr(sir.find('-') + 1, 8);     //returneaza sirul "pointer"  -- 8 pozitii
	cout << sir2 << endl;



	int v[100];  //alocarea statica nu este necesara---se foloseste prea multa memorie
	cout << v << endl; //adresa de unde incepe vectorul

	int *vector;
	int n = 5;       //dimensiune vector
	vector = new int[n];     //alocare spatiu
	//INDEXAREA
	// 0*sizeof(int) --> primul element ---motivul indexarii incepand de la 0
	for(int i=0;i<n;i++)
	{
		vector[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		
		cout << vector[i];
		
	}

	cout << endl;

	stergeMinim(vector, n);
	
	
	for (int i = 0; i < n; i++)
	{
		cout << vector[i];
	
	}



	delete []vector; //se duce la adresa memorata in vector---parantezele drepte indica faptul ca acolo se gaseste un vector

}

//atoi converteste catre int
//atof converteste catre float
//itoa converteste int la sir de caractere

