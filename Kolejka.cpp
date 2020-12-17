#include "Kolejka.h"


//konstruktor kolejki
Kolejka::Kolejka() {
	Kolejka::poczatek = NULL;					//domyœlnie ustawiamy pierwszy element na zero
};

//destruktor kolejki
Kolejka::~Kolejka()
{
	Wierzcholek* element;						//tworzymy wskaznik na element
	while (poczatek) {							//dopoki jest element pocz¹tkowy
		element = poczatek->getNastepny();		//przechodzimy do kolejnego elementu listy
		delete poczatek;						//usuwamy poprzedni element
		poczatek = element;						//ustawiamy nowy poczatek listy
	}
};

//funkcja dodajaca element do kolejki sortujac wedlug wagi o_dolne (najnizsze na poczatku)
void Kolejka::push(Wierzcholek k) {
	if (poczatek == NULL) {						// je¿eli nie istnieje pierwszy element
		poczatek = new Wierzcholek;				// tworzymy nowy i ustawiamy jako pierwszy
		poczatek->setO_dolne(k.getO_dolne());	// przypisujemy podane wartosci
		poczatek->setWartosc(k.getWartosc());
	}
	else {
		Wierzcholek* nowy = new Wierzcholek;					 //tworzymy nowy element
		nowy->setO_dolne(k.getO_dolne());						 // przypisujemy podane wartosci
		nowy->setWartosc(k.getWartosc());

		if (poczatek->getO_dolne() > nowy->getO_dolne())		 //sprawdzamy czy wstawic na poczatku
		{
			nowy->setNastepny(poczatek);						 //wstawiamy na poczatku listy
			poczatek = nowy;
		}
		else
		{
			Wierzcholek* tmp = poczatek;
			while (tmp->getNastepny() != NULL)										//przechodzimy dopoki nie napotkamy konca
			{
				if (tmp->getNastepny()->getO_dolne() > nowy->getO_dolne()) break;	//lub gdy ograniczenie dolne nastepnego bedzie wieksze od ograniczenia dolnego nowego wierzcholka
				tmp = tmp->getNastepny();											//przechodzimy do kolejnego elementu listy

			}

			nowy->setNastepny(tmp->getNastepny());									//wstawiamy do listy
			tmp->setNastepny(nowy);
		}
	}
};

//funkcja uzuwajaca poczatek
void Kolejka::pop() {
	if (poczatek != NULL)
	{
		Wierzcholek* e = poczatek->getNastepny();	//Ustawienie elementu e jako nowego pierwszego
		delete poczatek;							//usuwamy poczatek
		poczatek = e;								//ustawiamy nowy poczatek
	}
}

//funkcja zwracajaca poczatek
Wierzcholek Kolejka::front()
{
	return *poczatek;
}


//funkcja sprawdzajaca czy kolejka jest pusta
bool Kolejka::czyPusta() {
	if (poczatek == NULL) return true;
	else return false;
}
