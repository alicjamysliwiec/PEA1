#pragma once
#include <string>

using namespace std;

class Stos
{
private:

	int* poczatek = nullptr;	//wskaznik na poczatek stosu
	int rozmiar = 0;			//zmienna przechowujaca rozmiar stosu

public:
	void push(int element);		//funkcja dodajaca element do stosu (pierwszy)
	void pop();					//funkcja usuwajaca element ze stosu (pierwszy)
	string toString();			//funkcja wypisujaca sciezke
	int getRozmiar() {
		return rozmiar;			//funkcja zwracajaca rozmiar stosu
	}
	void copy(Stos* docelowy);	//funkcja kopiuj¹ca stos do docelowego
	Stos();						//konstruktor stosu
	~Stos();					//destruktor stosu
	void clear();				//funkcja czyszczaca stos	
	string odKoncaToString();	//funkcja wyspisujaca sciezke od konca
};