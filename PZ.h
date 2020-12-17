#pragma once
#include "Graf.h"
class PZ
{
private:
	int* tablica_permutacji;		//tablica przechowuj�ca wartosci potrzebne do wykonania permutacji
	int ilosc_wierzcholkow;			//zmienna przechowuj�ca ilo�� wierzcho�k�w w grafie
	int** tab;						//tablica dwuwymiarowa przechowuj�ca reprezentacj� grafu
	int* sciezka;					//tablica zawierajaca wierzcholki tworzace sciezke
	int min = 999999999;			//zmienna przechowujaca wartosc minimalna	

public:
	PZ(Graf* graf);					//konstruktor algorytmu przyjmuj�cy w parametrze wskaznik na graf
	~PZ();							//destruktor algorytmu
	void permutacje(int k);			//funkcja wykonujaca permutacje 
	void start();					//funkcja rozpoczynajaca algorytm
	void mierzPZ();					//funkcja potrzebna do zmierzenia czasy wykonania algorytmu
	string wyswietlWynik();			//funkcja wyswietlajaca wyniki
};

