#include <iostream>
#include <ctime>
#include <string>

class TicTacToe
{
private:
	char** matrice;

public:
	void alocareMatrice()
	{
		matrice = new char* [9];
		for (int i = 0; i < 9; i++)
		{
			matrice[i] = new char[9];
			for (int j = 0; j < 9; j++)
				matrice[i][j] = ' ';
		}
	}
	void dealocareMatrice()
	{
		for (int i = 0; i < 9; i++)
			delete[] matrice[i];
		delete[] matrice;
	}
	void afisareTicTacToe()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-----------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << matrice[i][j];
			}
			std::cout << std::endl;
		}
	}
	bool egalitate()
	{
		for (int i = 0; i < 9; i = i + 3)
			for (int j = 0; j < 9; j = j + 3)
				if (matrice[i][j] == ' ')
					return false;
		return true;
	}
	int verificare(char k)
	{
		int linia = ((k - 1) / 3) * 3, coloana = ((k - 1) % 3) * 3;
		if (matrice[linia][coloana] == ' ')
			return 1;
		return 0;
	}
	int win(char& castigator)
	{
		for (int i = 0; i < 9; i = i + 3)
		{
			if (matrice[i][0] != ' ' && matrice[i][0] == matrice[i][3] && matrice[i][0] == matrice[i][6] && matrice[i][3] == matrice[i][6])
			{
				if (matrice[i][0] == '\\')
					castigator = 'X';
				else
					castigator = 'O';
				return 1;
			}
			if (matrice[0][i] != ' ' && matrice[0][i] == matrice[3][i] && matrice[0][i] == matrice[6][i] && matrice[3][i] == matrice[6][i])
			{
				if (matrice[0][i] == '\\')
					castigator = 'X';
				else
					castigator = 'O';
				return 1;
			}
		}
		if (matrice[0][0] != ' ' && matrice[0][0] == matrice[3][3] && matrice[0][0] == matrice[6][6] && matrice[3][3] == matrice[6][6])
		{
			if (matrice[0][0] == '\\')
				castigator = 'X';
			else
				castigator = 'O';
			return 1;
		}
		if (matrice[6][0] != ' ' && matrice[6][0] == matrice[3][3] && matrice[6][0] == matrice[0][6] && matrice[3][3] == matrice[0][6])
		{
			if (matrice[6][0] == '\\')
				castigator = 'X';
			else
				castigator = 'O';
			return 1;
		}
		return 0;
	}
	int robotel(int* vector)
	{
		if (vector[0] !=0 && vector[0] == vector[1] && verificare(3))
			return 3;
		if (vector[0] != 0 && vector[0] == vector[2] && verificare(2))
			return 2;
		if (vector[1] != 0 && vector[1] == vector[2] && verificare(1))
			return 1;
		if (vector[3] != 0 && vector[3] == vector[4] && verificare(6))
			return 6;
		if (vector[3] != 0 && vector[3] == vector[5] && verificare(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[5] && verificare(4))
			return 4;
		if (vector[6] != 0 && vector[6] == vector[7] && verificare(9))
			return 9;
		if (vector[6] != 0 && vector[6] == vector[8] && verificare(8))
			return 8;
		if (vector[7] != 0 && vector[7] == vector[8] && verificare(7))
			return 7;
		if (vector[0] != 0 && vector[0] == vector[4] && verificare(9))
			return 9;
		if (vector[0] != 0 && vector[0] == vector[8] && verificare(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[8] && verificare(1))
			return 1;
		if (vector[2] != 0 && vector[2] == vector[4] && verificare(7))
			return 7;
		if (vector[2] != 0 && vector[2] == vector[6] && verificare(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[6] && verificare(3))
			return 3;
		if (vector[0] != 0 && vector[0] == vector[3] && verificare(7))
			return 7;
		if (vector[0] != 0 && vector[0] == vector[6] && verificare(4))
			return 4;
		if (vector[3] != 0 && vector[3] == vector[6] && verificare(1))
			return 1;
		if (vector[1] != 0 && vector[1] == vector[4] && verificare(8))
			return 8;
		if (vector[1] != 0 && vector[1] == vector[7] && verificare(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[7] && verificare(2))
			return 2;
		if (vector[2] != 0 && vector[2] == vector[5] && verificare(9))
			return 9;
		if (vector[2] != 0 && vector[2] == vector[8] && verificare(6))
			return 6;
		if (vector[5] != 0 && vector[5] == vector[9] && verificare(3))
			return 3;
		int decizie;
		do {
			decizie = rand() % 9 + 1;
		} while (!verificare(decizie));
		return decizie;
	}
	void joaca()
	{
		std::cout << "Cum vrei sa joci?\n 1. 2 jucatori\n 2. un jucator impotriva calculatorul\n";
		int k;
		char castigator = ' ';
		std::cin >> k;
		switch (k)
		{
		case 1:
		{
			std::cout << "Jucatorul 1:X\nJucatorul 2:O";
			int rand = 1;
			while (!egalitate() && win(castigator) == 0)
			{
				int t;
				std::cout << "\nJucatorul " << rand << " vrea sa introduca in casuta cu numarul ";
				do {
					std::cin >> t;
					if (verificare(t) == 0)
					{
						std::cout << "\nExista deja un element inserat, alege alta pozitie ";
					}
				} while (verificare(t) == 0);
				int linia = ((t - 1) / 3) * 3, coloana = ((t - 1) % 3) * 3;
				if (rand == 1)
				{
					matrice[linia][coloana] = matrice[linia + 2][coloana + 2] = '\\';
					matrice[linia + 2][coloana] = matrice[linia][coloana + 2] = '/';
					matrice[linia + 1][coloana + 1] = 'X';
					rand = 2;
					afisareTicTacToe();
				}
				else
				{
					matrice[linia][coloana] = '+';
					matrice[linia][coloana + 2] = '+';
					matrice[linia + 2][coloana] = '+';
					matrice[linia + 2][coloana + 2] = '+';
					matrice[linia][coloana + 1] = matrice[linia + 2][coloana + 1] = '-';
					matrice[linia + 1][coloana] = matrice[linia + 1][coloana + 2] = '|';
					rand = 1;
					afisareTicTacToe();
				}
			}
			if (egalitate() == true)
				std::cout << "Egalitate\n";
			if (castigator == 'X')
				std::cout << "FELICITARI! Jucatorul 1 a castigat!";
			else
				if (castigator == 'O')
					std::cout << "FELICITARI! Jucatorul 2 a castigat!";
			break;
		}
		case 2:
		{
			int* vector;
			vector = new int[9];
			for (int i = 0; i < 9; i++)
				vector[i] = 0;
			std::cout << "Vrei sa fi X sau O?";
			char caracter;
			do
			{
				std::cin >> caracter;
				if (caracter != 'X' && caracter != 'x' && caracter != 'O' && caracter != 'o')
					std::cout << "Nu e caracter valid, te rog introdu din nou ";
			} while (caracter != 'X' && caracter != 'x' && caracter != 'O' && caracter != 'o');
			while (!egalitate() && win(castigator) == 0)
			{
				int t;
				std::cout << "\nJucatorul vrea sa introduca in casuta cu numarul ";
				do {
					std::cin >> t;
					if (verificare(t) == 0)
					{
						std::cout << "\nExista deja un element inserat, alege alta pozitie ";
					}
				} while (verificare(t) == 0);
				vector[t-1]++;
				int linia = ((t - 1) / 3) * 3, coloana = ((t - 1) % 3) * 3;
				if (caracter == 'X' || caracter == 'x')
				{
					matrice[linia][coloana] = matrice[linia + 2][coloana + 2] = '\\';
					matrice[linia + 2][coloana] = matrice[linia][coloana + 2] = '/';
					matrice[linia + 1][coloana + 1] = 'X';
					afisareTicTacToe();
				}
				else
				{
					matrice[linia][coloana] = '+';
					matrice[linia][coloana + 2] = '+';
					matrice[linia + 2][coloana] = '+';
					matrice[linia + 2][coloana + 2] = '+';
					matrice[linia][coloana + 1] = matrice[linia + 2][coloana + 1] = '-';
					matrice[linia + 1][coloana] = matrice[linia + 1][coloana + 2] = '|';
					afisareTicTacToe();
				}
				if (egalitate() == true)
					break;
				int decizie=robotel(vector);
				vector[decizie - 1] = 2;
				std::cout << "\nRobotul introduce la pozitia " << decizie << '\n';
				int l = ((decizie - 1) / 3) * 3;
				int c = ((decizie - 1) % 3) * 3;
				if (caracter == 'X' || caracter == 'x')
				{
					matrice[l][c] = '+';
					matrice[l][c + 2] = '+';
					matrice[l + 2][c] = '+';
					matrice[l + 2][c + 2] = '+';
					matrice[l][c + 1] = matrice[l + 2][c + 1] = '-';
					matrice[l + 1][c] = matrice[l + 1][c + 2] = '|';
					afisareTicTacToe();
				}
				else
				{
					matrice[l][c] = matrice[l + 2][c + 2] = '\\';
					matrice[l + 2][c] = matrice[l][c + 2] = '/';
					matrice[l + 1][c + 1] = 'X';
					afisareTicTacToe();
				}
			}
			if (egalitate() == true)
				std::cout << "Egalitate\n";
			if (castigator == 'X'&& (caracter=='X'||caracter=='x'))
				std::cout << "FELICITARI! Jucatorul 1 a castigat!";
			else
				if (castigator == 'O')
					std::cout << "Robotu a castigat";
			delete[] vector;
			break;
		}
		default:
		{
			std::cout << "Nu e o optiune valabila\n";
			joaca();
		}
		}
	}
};

int main()
{
	srand(time(NULL));
	TicTacToe joc;
	joc.alocareMatrice();
	joc.afisareTicTacToe();
	joc.joaca();
}