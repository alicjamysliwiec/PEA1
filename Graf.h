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
	int ilosc_wierzcholkow;			//zmienna przechowująca ilość wierzchołków w grafie
	int** tab;						//tablica dwuwymiarowa przechowująca reprezentację grafu

public:
	Graf(int ilosc);				//konstruktor grafu przyjmuje w paramterze ilosc wierzcholkow
	~Graf();						//destruktor grafu
	void wygeneruj();				//funkcja generująca losowy graf
	void wyswietl();				//funkcja wyswietlająca graf
	void wczytaj(fstream plik);		//funkcja wczytująca graf z pliku
	int** getTab() {
		return tab;					//funkcja zwracajca reprezentację macierzową grafu
	}
	int getW() {
		return ilosc_wierzcholkow;	//funkcja zwracająca ilosc wierzcholkow grafu
	}

};
