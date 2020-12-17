#include "Stoper.h"

using namespace std;

//konstruktor klasy stoper
Stoper::Stoper() {
	Stoper::licznik = 0;
}

//destruktor klasy stoper
Stoper::~Stoper() {};

//funkcja zwracajaca czas komputera
LARGE_INTEGER Stoper::getTime()
{
	LARGE_INTEGER time;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&time);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return time;
}

//funkcja zapisujaca czas startu
void Stoper::start() {
	performanceCountStart = getTime();
}

//funkcja zapisujaca czas zakonczenia
void Stoper::stop() {
	performanceCountEnd = getTime();
}

//funkcja liczaca czas miedzy poczatkiem, a koncem
void Stoper::dodajCzas() {
	licznik += performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
}

//funkcja zerujaca licznik
void Stoper::zerujLicznik() {
	licznik = 0;
}

