#include <iostream>
#include <iomanip> //what for?
#include <random>
#include <sstream>

using namespace std;
int macierz[15][15];

// bank - po każdym naliczeniu odsetek wyświetlić informacje
// 3 - żeby funkcja dostawała parametr czy uwzględniać przekątną 19

int getIntInput()
{
	int numInput = 0; string strInput = "";

	while (true)
	{
		getline(cin, strInput);
		stringstream intStream(strInput);
		if (intStream >> numInput)
		{
			return numInput;
			break;
		}
	}
}

char getCharInput()
{
	string inputString = "";
	while (true)
	{
		getline(cin, inputString);
		if (inputString.length() == 1)
		{
			return inputString[0];
		}
	}
}

void pobierz_wielkosc(int &int_wielkosc)
{	
	do
	{
		cout << "Jaka ma być wielkość macierzy? : ";
		int_wielkosc = getIntInput();
	} while (int_wielkosc <= 1 || int_wielkosc > 15);
}

void drukuj(int int_wielkosc)
{
	for (int j = 0; j < int_wielkosc; j++)
	{
		cout << "|";
		for (int i = 0; i < int_wielkosc; i++)
		{
			cout << setw(3) << macierz[j][i] << "|";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dodaj_dane(int int_wielkosc)
{
	

	cout << "Dodaj elementy: \n";
	for (int j = 0; j < int_wielkosc; j++)
	{
		for (int i = 0; i < int_wielkosc; i++)
		{
			cout << "Wiersz: " << j+1 << " Kolumna: " << i+1 << " = ";
			//macierz[j][i] = rand()%41 - 20;
			//cin >> macierz[j][i]; i read about type-safe input
			macierz[j][i] = getIntInput();
		}
	}
	drukuj(int_wielkosc);
}


int suma_ponizej(int int_wielkosc, bool withDiagonal)
{
	int suma = 0;
	if (withDiagonal == true)
	{
		for (int j = 0; j < int_wielkosc; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				suma += macierz[j][i];
			}
		}
	}
	else
	{
		for (int j = 0; j < int_wielkosc; j++)
		{
			for (int i = 0; i < j; i++)
			{
				suma += macierz[j][i];
			}
		}
	}

	return suma;
}

int suma_powyzej(int int_wielkosc, bool withDiagonal)
{
	int suma = 0;
	if (withDiagonal == true)
	{
		for (int j = 0; j < int_wielkosc; j++)
		{
			for (int i = int_wielkosc - 1; i >= j; i--)
			{
				suma += macierz[j][i];
			}
		}
	}else
	{
		for (int j = 0; j < int_wielkosc; j++)
		{
			for (int i = int_wielkosc-1; i > j; i--)
			{
				suma += macierz[j][i];
			}
		}
	}
	return suma;
}

int sum_column(int wielkosc)
{
	int column = 0; int sum = 0;
	do
	{
		cout << "Której kolumny sumę? : ";
		column = getIntInput();
	} while (column < 1 || column > wielkosc);
	column--; //alignment of user perspective for index 0 row equals 1

	for (int i = 0; i < wielkosc; i++)
	{
		sum += macierz[i][column];
	}
	return sum;
}

int sum_row(int wielkosc)
{
	int row = 0; int sum = 0;
	do
	{
		cout << "Którego wiersza sumę? : ";
		row = getIntInput();
	} while (row < 1 || row > wielkosc);
	row--; //alignment of user perspective for index 0 row equals 1
	
	for (int i = 0; i < wielkosc; i++)
	{
		sum += macierz[row][i];
	}
	return sum;
}


int main()
{
	int wielkosc, opcja;
	pobierz_wielkosc(wielkosc);
	dodaj_dane(wielkosc);

	do
	{
		cout << " Wybierz\n 1 - Aby wyznaczyć sumy wartości poniżej przekątnej. \n 2 - Aby wyznaczyć sumy wartości powyżej przekątnej.\n 3 - Aby wyznaczyć sumy wskazanego wiersza/kolumny.\n 4 - Aby zakończyć działanie programu.\n";
		cin >> opcja;
		switch (opcja)
		{
		case 1:
		{
			char charInput = { 0 };
			do
			{
				cout << "Wraz z przekątną?[T/N] : ";
				charInput = getCharInput();
			} while (charInput != 'T' && charInput != 'N');

			if (charInput == 'T')
			{
				cout << "Suma wartości poniżej wraz z przekątną wynosi: " << suma_ponizej(wielkosc, true) << "\n";
			}
			else
			{
				cout << "Suma wartości poniżej wykluczając przekątną wynosi: " << suma_ponizej(wielkosc, false) << "\n";
			}

			drukuj(wielkosc);
			break;
		}
		case 2:
		{
			char charInput = { 0 };
			do
			{
				cout << "Wraz z przekątną?[T/N] : ";
				charInput = getCharInput();
			} while (charInput != 'T' && charInput != 'N');

			if (charInput == 'T')
			{
				cout << "Suma wartości powyżej wraz z przekątną wynosi: " << suma_powyzej(wielkosc, true) << "\n";
			}
			else
			{
				cout << "Suma wartości powyżej wykluczając przekątną wynosi: " << suma_powyzej(wielkosc, false) << "\n";
			}

			//cout << "Suma wartości powyżej przekątnej wynosi: " << suma_powyzej(wielkosc) << "\n\n";

			drukuj(wielkosc);
			break;
		}
		case 3:
		{
			char charInput = { 0 };
			do
			{
				cout << "Wiersz czy kolumna? [W/K] : ";
				charInput = getCharInput();
			} while (charInput != 'W' && charInput != 'K');
			
			if (charInput == 'W')
			{
				cout << "Suma wiersza równa jest: " << sum_row(wielkosc) << endl;
			}
			else
			{
				cout << "Suma kolumny równa jest: " << sum_column(wielkosc) << endl;
			}

			drukuj(wielkosc);
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			cout << "Niepoprawna opcja.";
			break;
		}
		} 
	}while (opcja != 4);
}
