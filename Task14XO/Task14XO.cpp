#include <iostream>
using namespace std;

void print(char field[][3])
{
for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout<<field[i][j];
		}
		cout << endl;
	}
}
int main()
{   
	bool winer = true;
	while (winer) 
	{

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
		print(field);
	}
}
