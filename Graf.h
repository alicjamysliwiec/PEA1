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
	int ilosc_wierzcholkow;			//zmienna przechowuj¹ca iloœæ wierzcho³ków w grafie
	int** tab;						//tablica dwuwymiarowa przechowuj¹ca reprezentacjê grafu

public:
	Graf(int ilosc);				//konstruktor grafu przyjmuje w paramterze ilosc wierzcholkow
	~Graf();						//destruktor grafu
	void wygeneruj();				//funkcja generuj¹ca losowy graf
	void wyswietl();				//funkcja wyswietlaj¹ca graf
	void wczytaj(fstream plik);		//funkcja wczytuj¹ca graf z pliku
	int** getTab() {
		return tab;					//funkcja zwracajca reprezentacjê macierzow¹ grafu
	}
	int getW() {
		return ilosc_wierzcholkow;	//funkcja zwracaj¹ca ilosc wierzcholkow grafu
	}

};
