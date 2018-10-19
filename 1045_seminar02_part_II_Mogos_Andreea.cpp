//Program care sterge cel mai lung cuvant
#include <iostream>
#include <string>

using namespace std;

int PozElemLung (int n, string* v)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i].length() > v[max].length()) //lungimea elem curent>lung elem max
		{
			max = i; //max preia elem curent
		}
	}
	return max;
}

void StergeDePePoz(int n, string* v, int poz)
{
	string* aux = new string[n - 1]; //alocare memorie pt vector auxiliar
	int j = 0; //indice nou
	for (int i = 0; i < n; i++)
	{
		if (i != poz)
		{
			aux[j++] = v[i]; //copiaza v[i] in aux
		}
	}
		delete[] v;
		v = aux;
		n--; //scade dimensiunea vectorului dupa stergerea elementului 
}

void StergeElemLung(int n, string* v)
{
	//1.determinam pozitia celui mai lung element
	int pozitie = PozElemLung(n,v);
	//2.stergem elementul de pe pozitia respectiva si scadem n
	StergeDePePoz(n, v, pozitie);
 }
void main()
{
	int n = 4;
	string*v = new string[n];
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	StergeElemLung(n, v);
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << "";
		}
}