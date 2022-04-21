#include <iostream>
using namespace std;

void print(char field[][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
}
bool checkingInput(char field[][3], int x, int y) 
{	
	if (x < 0 || x>2 || y < 0 || y>2)
		return false;
	else if (field[x][y] == 'X' || field[x][y] == 'O')
		return false;
	else
	return true;
}
bool winner(char field[][3], char sym)
{
	int col = 0;
	int row = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (field[i][j] == sym)
				row++;
			if (field[j][i] == sym)
				col++;
			if (row == 3)
				return true;
			if (col == 3)
				return true;
		}
		row = 0;
		col = 0;
	}
	for (size_t i = 0; i < 3; i++)
	{
		if (field[i][i] == sym)
			row++;
		if (row == 3)
			return true;
	}
	row = 0;
	for (int i = 2,k=0; i >= 0; --i,++k)
	{
			if (field[i][k] == sym)
				row++;
			if (row == 3)
				return true;		
	}
	return false;
}
int game()
{
	int m = 0;
	int nobody = 0;
	const int X = 3;
	const int Y = 3;
	char field[X][Y];
	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			field[i][j] = '-';
		}
	}
	bool winer = true;
	bool moveTransition = true;
	while (winer)
	{
		int x = 0;
		int y = 0;
		bool checking = true;
		print(field);
		if (moveTransition)
		{
			if (nobody >= 9)
				return 0;
			while (checking)
			{
				cout << "Enter the coordinates X ( X (1-3), Y (1-3)) ";
				cin >> x >> y;
				x--;
				y--;
				if (!checkingInput(field, x, y))
				{
					cout << "Error incorrect input "<<endl;
				}
				else
				checking = false;
			}
			field[x][y] = 'X';
			moveTransition = false;
			if (winner(field, 'X'))
			{
				m = 1;
				return m;
			}
			nobody++;
		}
		else 
		{	
			if (nobody >= 9)
				return 0;
			while (checking)
			{
				cout << "Enter the coordinates O ( X (1-3), Y (1-3)) ";
				cin >> x >> y;
				x--;
				y--;
				if (!checkingInput(field, x, y))
				{
					cout << "Error incorrect input" << endl;
				}
				else
					checking = false;
			}
			field[x][y] = 'O';
			moveTransition = true;
			if (winner(field, 'O'))
			{
				m = -1;
				return m;
			}
			nobody++;
		}
	}
	return m;
}
int main()
{   
	int win = game();
	if (win == 1)
		cout << endl<<"X WIN" << endl;
	else if (win == -1)
		cout <<endl<< "O WIN" << endl;
	else
		cout <<endl<< "NOBODI" << endl;
}
