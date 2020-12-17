#include "Stos.h"

//funkcja dodajaca element do stosu
void Stos::push(int element)
{
	if (!rozmiar) {								//je¿eli rozmiar jest rozny od zera, czyli stos nie istnieje
		rozmiar++;								//zwiekszamy rozmiar
		poczatek = new int[1];					//tworzymy nowa tablice o rozmiarze 1
		*poczatek = element;					//przypisujemy poczatkowi stosu wartosc 1
	}
	else {										//jezeli stos istnieje
		rozmiar++;								//zwiekszamy rozmiar stosu
		int* nowy_poczatek = new int[rozmiar];	//rezerwujemy miejsce na zwiekszony stos
		int* poczatek_buff = poczatek;			//zmienne do przepisywania stosu
		int* temp_buff = nowy_poczatek;			//zmienne do przepisywania stosu		

		for (int i = 0; i < rozmiar - 1; i++)	//przepisujemy caly stos do nowo utworzonego
		{
			*temp_buff = *poczatek_buff;
			temp_buff++;
			poczatek_buff++;
		}

		*temp_buff = element;					//dopisujemy ostatni element do nowego stosu

		delete[] poczatek;						//usuwamy stary poczatek

		poczatek = nowy_poczatek;				//jako poczatek stosu ustawiamy nowy poczatek
	}
}

//funkcja usuwajaca  element ze stosu
void Stos::pop()
{
	if (rozmiar > 1)								//je¿eli stos ma co najmniej 2 elementy
	{
		rozmiar--;									//zmniejszamy rozmiar stosu

		int* nowy_poczatek = new int[rozmiar];		//rezerwujemy miejsce na zmniejszony stos
		int* poczatek_buff = poczatek;				//zmienne do przepisywania stosu
		int* temp_buff = nowy_poczatek;				//zmienne do przepisywania stosu

		for (int i = 0; i < rozmiar; i++)			//przepisujemy caly stos do nowo utworzonego
		{
			*temp_buff = *poczatek_buff;
			poczatek_buff++;
			temp_buff++;
		}

		delete[] poczatek;					//usuwamy stary poczatek
		poczatek = nowy_poczatek;			//jako poczatek stosu ustawiamy nowy poczatek

	}
	else if (rozmiar == 1)					//jezeli stos jest jednoelementowy
	{

		rozmiar = 0;						//rozmiar ustawiamy na zero

		delete[] poczatek;					//usuwamy poczatek
		poczatek = nullptr;					//poczatek ustawiamy na nieistniejacy, usuwamy stos

	}
}

//funkcja zwracajaca wynik
string Stos::toString()
{
	string msg = "";
	int* poczatek_buff = poczatek;			//zmienna do przemieszczania sie po stosie

	if (!rozmiar)
	{
		msg = "Stos pusty";					//jezeli stos nie istnieje to jest pusty
	}
	else
	{
		for (int i = 0; i < rozmiar; i++)
		{
			msg = msg + to_string(*poczatek_buff) + " - ";
			poczatek_buff++;
		}
	}

	return msg;								//zwracamy wynik
}

//konstruktor stosu
Stos::Stos()
{

}

//destruktor stosu
Stos::~Stos()
{
	if (poczatek != nullptr)
	{
		delete[] poczatek;		//dopoki istnieje poczatek, usuwamy go
	}
}

//funkcja czyszczaca stos
void Stos::clear()
{
	delete[]poczatek;			//usuwamy poczatek
	poczatek = nullptr;			//ustawiamy poczatek jako niesitniejacy
	rozmiar = 0;				//zerujemy rozmiar stosu
}

//funkcja kopiujaca aktualny stos do docelowego
void Stos::copy(Stos* docelowy)
{
	int* poczatek_buff = poczatek;			//zmienna do poruszania sie po stosie

	docelowy->clear();						//czyscimy docelowy

	if (rozmiar)							//jezeli stos istnieje
	{
		for (int i = 0; i < rozmiar; i++)
		{
			docelowy->push(*poczatek_buff); //dodawanie elementow starego stosu do nowego
			poczatek_buff++;
		}
	}
}

//funkcja zwracajaca wyniki od konca
string Stos::odKoncaToString()
{
	string msg = "0";
	int* poczatek_buff = poczatek + rozmiar - 1; //zmienna do przemieszczania sie po stosie

	if (!rozmiar)
	{
		msg = "Stos pusty";						//jezeli stos nie istnieje to jest pusty
	}
	else
	{
		for (int i = 0; i < rozmiar; i++)
		{
			msg = msg + " - " + to_string(*poczatek_buff);
			poczatek_buff--;
		}
	}

	return msg;								 //zwracamy wynik
}