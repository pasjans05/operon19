// operon19.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream plik("oddzialy.txt");

void straty()
{
	int strat = 0;
	int poza = 0;
	int x;
	int y;
	double dystans;
	for (int i = 0; i < 50; i++)
	{
		plik >> x >> y;
		dystans = sqrt((x * x) + (y * y));
		if (dystans == 1 || dystans == 20) strat += 25;
		if (dystans > 1 && dystans < 20) strat += 100;
		if (dystans < 1 || dystans > 20) poza++;
	}
	plik.close();
	cout << strat << " " << poza;
}

int main()
{
	straty();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
