#include "Header.h"
int num = 0;
const int n = 5;
bool field_hidden[n][n];
int score = 0;
char field[n][n];


void create_field()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			field[i][j] = '*';
			field_hidden[i][j] = 0;
		}
	}
}
void set_mine()
{
	int count = 10;
	int i = 0;
	while (i < count)
	{
		int x = rand() % n;
		int y = rand() % n;
		if (!field_hidden[x][y])
		{
			field_hidden[x][y] = 1;
			i++;
		}
	}
}
void show_field_hidden()
{

	cout << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << "\n---------------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << (char)(i + 65) << "|";
		for (int j = 0; j < n; j++)
		{
			cout << field_hidden[i][j] << " ";
		}
		cout << endl;
	}

}
void show_field()
{
	cout << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << "\n---------------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << (char)(i + 65) << "|";
		for (int j = 0; j < n; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

void game()
{
	create_field();
	set_mine();

	cout << endl << endl;
	int y;
	char x; int lives = 3;


	do
	{
		system("cls");
		show_field_hidden();
		cout << endl;
		show_field();


		cout << "\nShoot please!\n";
		cin >> x;
		cin >> y;
		x = x - 65;



		if (field_hidden[x][y])
		{

			field[x][y] = 1 + 0x30;
			score -= 5;
			lives--;
		}

		else
		{
			field[x][y] = 0 + 0x30;



			if (num < 5)
			{
				score += 5;

			}
			else if (num >= 5 && num < 10)
			{
				score += 10;

			}
			else
			{
				score += 15;
			}
			num++;

		}

	} while ((num < ((n * n) - 10)) && (lives > 0));

	system("cls");
	if (lives == 0)
	{
		cout << "Game over!" << endl;
	}
	else
	{
		cout << "You win!" << endl << endl;
		cout << "Your score is " << score << endl;
	}
}