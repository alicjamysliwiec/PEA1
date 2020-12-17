#pragma once
#include "Stos.h"
#include "Graf.h"
#include "Wierzcholek.h"
#include "Kolejka.h"


class BB
{
private:
	Wierzcholek wierzcholek;							//zmienna typu Wierzcholek przechowujaca informacje o wierzcholku
	int ilosc_wierzcholkow;								//zmienna przechowuj�ca ilo�� wierzcho�k�w w grafie
	int** tab;											//tablica dwuwymiarowa przechowuj�ca reprezentacj� grafu
	Stos sciezka;										//zmienna przechowuj�ca rozwiazanie w stosie
	Stos aktualna_sciezka;								//zmienna przechowujaca aktualne rozwiazanie w stosie
	int ograniczenie_gorne = 99999999;					//zmienna przechowuj�ca wartosc ograniczenia gornego
	int ograniczenie_dolne = 0;							//zmienna przechowujaca wartosc ograniczenia dolnego
	int* tablica_min;									//pomocnicza tablica wartosci minimalnych
	bool* odwiedzone;									//pomocnicza tablica zawierajaca informacje o wierzcholkach odwiedzonych

public:
	BB(Graf* graf);										//konstruktor algorytmu przyjmuj�cy w parametrze wskaznik na graf
	~BB();												//destruktor algorytmu
	void gorne(Wierzcholek wierzcholek);				//funkcja wyznaczajaca ograniczenie gorne
	int dolne(Wierzcholek wierzcholek, int nastepny);	//funkcja obliczajaca ograniczenie dolne
	void rekurencja(Wierzcholek wierzcholek);			//funkcja rekurencyjna
	void start();										//funkcja rozpoczynaj�ca algorytm
	string wyswietlWynik();								//funkcja wy�wietlaj�ca wynik 
};

