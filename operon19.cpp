// operon19.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream plik("oddzialy.txt");

void stratyImaxdyst()
{
	int strat = 0;
	int poza = 0;
	int x;
	int y;
	double dystans;
	double max = 0;
	for (int i = 0; i < 50; i++)
	{
		plik >> x >> y;
		dystans = sqrt((x * x) + (y * y));
		if (dystans > max) max = dystans;
		if (dystans == 1 || dystans == 20) strat += 25;
		if (dystans > 1 && dystans < 20) strat += 100;
		if (dystans < 1 || dystans > 20) poza++;
	}
	plik.close();
	plik.open("oddzialy.txt");
	cout << strat << " " << poza << endl;
	cout << setprecision(5) << max << endl;
}

int straty(int a, int b)
{
	int x;
	int y;
	double distance;
	int strat = 0;
	for (int i = 0; i < 50; i++)
	{
		plik >> x >> y;
		//cout << a << "\t" << b << "\t" << x << "\t" << y << endl;
		distance = sqrt(((x - a) * (x - a)) + ((y - b) * (y - b)));
		if (distance == 2) strat += 25;
		if (distance < 2) strat += 100;
	}
	plik.close();
	plik.open("oddzialy.txt");
	return strat;
}

int main()
{
	stratyImaxdyst();
	int x = 0, y = 0;
	int max = 0;
	int maks = 0;
	for (int i = -20; i <= 20; i++)
	{
		for (int j = -20; j <= 20; j++)
		{
			maks = straty(i, j);
			//cout << maks << endl;
			//cout << i << "\t" << j << endl;
			if (maks > max)
			{
				max = maks;
				x = i;
				y = j;
			}
		}
	}
	cout << x << ", " << y << "\t" << max << endl;
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
