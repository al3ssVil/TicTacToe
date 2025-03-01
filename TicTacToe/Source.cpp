#include <iostream>
#include <ctime>
#include <string>

class TicTacToe
{
private:
	char** m_matrix;

public:
	void AllocateMatrix()
	{
		m_matrix = new char* [9];
		for (int i = 0; i < 9; i++)
		{
			m_matrix[i] = new char[9];
			for (int j = 0; j < 9; j++)
				m_matrix[i][j] = ' ';
		}
	}
	void DeallocateMatrix()
	{
		for (int i = 0; i < 9; i++)
			delete[] m_matrix[i];
		delete[] m_matrix;
	}
	void DisplayTicTacToe()
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
				std::cout << "-----------" << '\n';
			for (int j = 0; j < 9; j++)
			{
				if (j == 3 || j == 6)
					std::cout << "|";
				std::cout << m_matrix[i][j];
			}
			std::cout << std::endl;
		}
	}
	bool Equality()
	{
		for (int i = 0; i < 9; i = i + 3)
			for (int j = 0; j < 9; j = j + 3)
				if (m_matrix[i][j] == ' ')
					return false;
		return true;
	}
	int Checking(char k)
	{
		int row = ((k - 1) / 3) * 3, column = ((k - 1) % 3) * 3;
		if (m_matrix[row][column] == ' ')
			return 1;
		return 0;
	}
	int Win(char& winner)
	{
		for (int i = 0; i < 9; i = i + 3)
		{
			if (m_matrix[i][0] != ' ' && m_matrix[i][0] == m_matrix[i][3] && m_matrix[i][0] == m_matrix[i][6] && m_matrix[i][3] == m_matrix[i][6])
			{
				if (m_matrix[i][0] == '\\')
					winner = 'X';
				else
					winner = 'O';
				return 1;
			}
			if (m_matrix[0][i] != ' ' && m_matrix[0][i] == m_matrix[3][i] && m_matrix[0][i] == m_matrix[6][i] && m_matrix[3][i] == m_matrix[6][i])
			{
				if (m_matrix[0][i] == '\\')
					winner = 'X';
				else
					winner = 'O';
				return 1;
			}
		}
		if (m_matrix[0][0] != ' ' && m_matrix[0][0] == m_matrix[3][3] && m_matrix[0][0] == m_matrix[6][6] && m_matrix[3][3] == m_matrix[6][6])
		{
			if (m_matrix[0][0] == '\\')
				winner = 'X';
			else
				winner = 'O';
			return 1;
		}
		if (m_matrix[6][0] != ' ' && m_matrix[6][0] == m_matrix[3][3] && m_matrix[6][0] == m_matrix[0][6] && m_matrix[3][3] == m_matrix[0][6])
		{
			if (m_matrix[6][0] == '\\')
				winner = 'X';
			else
				winner = 'O';
			return 1;
		}
		return 0;
	}
	int Robot(int* vector)
	{
		if (vector[0] !=0 && vector[0] == vector[1] && Checking(3))
			return 3;
		if (vector[0] != 0 && vector[0] == vector[2] && Checking(2))
			return 2;
		if (vector[1] != 0 && vector[1] == vector[2] && Checking(1))
			return 1;
		if (vector[3] != 0 && vector[3] == vector[4] && Checking(6))
			return 6;
		if (vector[3] != 0 && vector[3] == vector[5] && Checking(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[5] && Checking(4))
			return 4;
		if (vector[6] != 0 && vector[6] == vector[7] && Checking(9))
			return 9;
		if (vector[6] != 0 && vector[6] == vector[8] && Checking(8))
			return 8;
		if (vector[7] != 0 && vector[7] == vector[8] && Checking(7))
			return 7;
		if (vector[0] != 0 && vector[0] == vector[4] && Checking(9))
			return 9;
		if (vector[0] != 0 && vector[0] == vector[8] && Checking(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[8] && Checking(1))
			return 1;
		if (vector[2] != 0 && vector[2] == vector[4] && Checking(7))
			return 7;
		if (vector[2] != 0 && vector[2] == vector[6] && Checking(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[6] && Checking(3))
			return 3;
		if (vector[0] != 0 && vector[0] == vector[3] && Checking(7))
			return 7;
		if (vector[0] != 0 && vector[0] == vector[6] && Checking(4))
			return 4;
		if (vector[3] != 0 && vector[3] == vector[6] && Checking(1))
			return 1;
		if (vector[1] != 0 && vector[1] == vector[4] && Checking(8))
			return 8;
		if (vector[1] != 0 && vector[1] == vector[7] && Checking(5))
			return 5;
		if (vector[4] != 0 && vector[4] == vector[7] && Checking(2))
			return 2;
		if (vector[2] != 0 && vector[2] == vector[5] && Checking(9))
			return 9;
		if (vector[2] != 0 && vector[2] == vector[8] && Checking(6))
			return 6;
		if (vector[5] != 0 && vector[5] == vector[9] && Checking(3))
			return 3;
		int decision;
		do {
			decision = rand() % 9 + 1;
		} while (!Checking(decision));
		return decision;
	}
	void Play()
	{
		std::cout << "How do you want to play?\n 1. 2 players\n 2. one player against the computer\n";
		int decision;
		char winner = ' ';
		std::cin >> decision;
		switch (decision)
		{
		case 1:
		{
			std::cout << "Player 1: X\nPlayer 2: O\n";
			int turn = 1;
			while (!Equality() && Win(winner) == 0)
			{
				int boxNumber;
				std::cout << "\nPlayer " << turn << " wants to place in the box number ";
				do {
					std::cin >> boxNumber;
					if (Checking(boxNumber) == 0)
					{
						std::cout << "\nThere is already an element inserted, choose another position";
					}
				} while (Checking(boxNumber) == 0);
				int row = ((boxNumber - 1) / 3) * 3, column = ((boxNumber - 1) % 3) * 3;
				if (turn == 1)
				{
					m_matrix[row][column] = m_matrix[row + 2][column + 2] = '\\';
					m_matrix[row + 2][column] = m_matrix[row][column + 2] = '/';
					m_matrix[row + 1][column + 1] = 'X';
					turn = 2;
					DisplayTicTacToe();
				}
				else
				{
					m_matrix[row][column] = '+';
					m_matrix[row][column + 2] = '+';
					m_matrix[row + 2][column] = '+';
					m_matrix[row + 2][column + 2] = '+';
					m_matrix[row][column + 1] = m_matrix[row + 2][column + 1] = '-';
					m_matrix[row + 1][column] = m_matrix[row + 1][column + 2] = '|';
					turn = 1;
					DisplayTicTacToe();
				}
			}
			if (Equality() == true)
				std::cout << "Equality!\n";
			if (winner == 'X')
				std::cout << "CONGRATULATIONS! Player 1 has won!";
			else
				if (winner == 'O')
					std::cout << "CONGRATULATIONS! Player 2 has won!";
			break;
		}
		case 2:
		{
			int* vector;
			vector = new int[9];
			for (int i = 0; i < 9; i++)
				vector[i] = 0;
			std::cout << "Do you want to be X or O?";
			char character;
			do
			{
				std::cin >> character;
				if (character != 'X' && character != 'x' && character != 'O' && character != 'o')
					std::cout << "Invalid character, please enter again. ";
			} while (character != 'X' && character != 'x' && character != 'O' && character != 'o');
			while (!Equality() && Win(winner) == 0)
			{
				int decision;
				std::cout << "\nThe player wants to place in the box number ";
				do {
					std::cin >> decision;
					if (Checking(decision) == 0)
					{
						std::cout << "\nThere is already an element placed, choose another position.";
					}
				} while (Checking(decision) == 0);
				vector[decision-1]++;
				int row = ((decision - 1) / 3) * 3, column = ((decision - 1) % 3) * 3;
				if (character == 'X' || character == 'x')
				{
					m_matrix[row][column] = m_matrix[row + 2][column + 2] = '\\';
					m_matrix[row + 2][column] = m_matrix[row][column + 2] = '/';
					m_matrix[row + 1][column + 1] = 'X';
					DisplayTicTacToe();
				}
				else
				{
					m_matrix[row][column] = '+';
					m_matrix[row][column + 2] = '+';
					m_matrix[row + 2][column] = '+';
					m_matrix[row + 2][column + 2] = '+';
					m_matrix[row][column + 1] = m_matrix[row + 2][column + 1] = '-';
					m_matrix[row + 1][column] = m_matrix[row + 1][column + 2] = '|';
					DisplayTicTacToe();
				}
				if (Equality() == true)
					break;
				int decizie=Robot(vector);
				vector[decizie - 1] = 2;
				std::cout << "\nThe robot places at position " << decizie << '\n';
				int l = ((decizie - 1) / 3) * 3;
				int c = ((decizie - 1) % 3) * 3;
				if (character == 'X' || character == 'x')
				{
					m_matrix[l][c] = '+';
					m_matrix[l][c + 2] = '+';
					m_matrix[l + 2][c] = '+';
					m_matrix[l + 2][c + 2] = '+';
					m_matrix[l][c + 1] = m_matrix[l + 2][c + 1] = '-';
					m_matrix[l + 1][c] = m_matrix[l + 1][c + 2] = '|';
					DisplayTicTacToe();
				}
				else
				{
					m_matrix[l][c] = m_matrix[l + 2][c + 2] = '\\';
					m_matrix[l + 2][c] = m_matrix[l][c + 2] = '/';
					m_matrix[l + 1][c + 1] = 'X';
					DisplayTicTacToe();
				}
			}
			if (Equality() == true)
				std::cout << "Equality!\n";
			if (winner == 'X'&& (character=='X'||character=='x'))
				std::cout << "CONGRATULATIONS! You won!";
			else
				if(winner=='O'&&(character=='o'||character=='O'))
					std::cout << "CONGRATULATIONS! You won!";
				else
					std::cout << "The robot has won.";
			delete[] vector;
			break;
		}
		default:
		{
			std::cout << "It is not a valid option.\n";
			Play();
		}
		}
	}
};

int main()
{
	srand(time(NULL));
	TicTacToe game;
	game.AllocateMatrix();
	game.DisplayTicTacToe();
	game.Play();
}