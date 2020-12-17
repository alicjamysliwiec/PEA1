#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Graf {

private:
	int ilosc_wierzcholkow;			//zmienna przechowuj�ca ilo�� wierzcho�k�w w grafie
	int** tab;						//tablica dwuwymiarowa przechowuj�ca reprezentacj� grafu

public:
	Graf(int ilosc);				//konstruktor grafu przyjmuje w paramterze ilosc wierzcholkow
	~Graf();						//destruktor grafu
	void wygeneruj();				//funkcja generuj�ca losowy graf
	void wyswietl();				//funkcja wyswietlaj�ca graf
	void wczytaj(fstream plik);		//funkcja wczytuj�ca graf z pliku
	int** getTab() {
		return tab;					//funkcja zwracajca reprezentacj� macierzow� grafu
	}
	int getW() {
		return ilosc_wierzcholkow;	//funkcja zwracaj�ca ilosc wierzcholkow grafu
	}

};
