#pragma once
#include "Graf.h"
#include "Stos.h"

class PD
{
private:
	int ilosc_wierzcholkow;					//zmienna przechowuj¹ca iloœæ wierzcho³ków w grafie
	int** tab;								//tablica dwuwymiarowa przechowuj¹ca reprezentacjê grafu
	int wynik = 999999999;					//zmienna przechowujaca wynik algorytmu  (dlugosc sciezki)
	int tymczasowa = 0;						//zmienna pomocniczna
	int** pamiecDrogi;						//tablica dwuwymiarowa o wymiarach 2^n na n, gdzie n to liczba wierzcholkow, w komorce przechowuje minimalna dlugosc sciezki z danego wierzcholka do wierzcholka 0
											//przechodzaca przez wierzcholki odpowiadajace masce wiersza
	int** pamiecPoprzednichWierzcholkow;	//tablica dwuwymiarowa o wymiarach 2^n na n, gdzie n to liczba wierzcholkow, w komorce przechowuje wartosc wierzcholka
											//ktory prowadzi do optymalnej sciezki (z zadanego wierzcholka do wierzcholka 0, przechodzaca przez wierzcholki odpowiadajace masce wiersza)
	int wierzcholek;						//wartosc wierzcholka, z ktorego prowadzi minimalna sciezka

public:
	void start();							//funkcja rozpoczynajaca algorytm
	string wyswietlWynik();					//funkcja wyswietlajaca wyniki
	int getWynik() {
		return wynik;						//funkcja zwracajaca wartosc wyniku
	}
	PD(Graf* graf);							//konstruktor algorytmu przyjmujacy w parametrze wskaznik na graf
	~PD();									//destruktor algorytmu
};