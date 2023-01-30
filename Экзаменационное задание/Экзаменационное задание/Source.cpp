#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

const int N = 10;

void printField(char field[N][N], bool hideShips)
{
	cout << "  ";
	for (int i = 0; i < N; ++i)
	{
		cout << i << " "; // Вывод системы координат.
	}
	cout << endl;

	for (int i = 0; i < N; ++i)
	{
		cout << i << " ";
		for (int j = 0; j < N; ++j)
		{
			if (!hideShips)
			{
				if ((field[i][j] == '1') || (field[i][j] == 'P'))
					cout << "* ";
				else if (field[i][j] == '#')
					cout << "# ";
				else if ((field[i][j] == 'D') || (field[i][j] == 'X') || (field[i][j] == 'N'))
					cout << "X ";
				else
					cout << "  ";
			}
			else
			{
				if (field[i][j] == '#')
					cout << "# ";
				else if ((field[i][j] == 'D') || (field[i][j] == 'X') || (field[i][j] == 'N'))
					cout << "X ";
				else
					cout << "  ";
			}
		}
		cout << endl;
	}


}

bool canPlace(char field[N][N], int x, int y)
{
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		if ((field[x + 1][y + 1] == ' ') && (field[x - 1][y - 1] == ' ') && (field[x - 1][y + 1] == ' ') && (field[x + 1][y - 1] == ' '))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		if ((field[x + 1][y + 1] == ' ') && (field[x + 1][y - 1] == ' '))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		if ((field[x - 1][y - 1] == ' ') && (field[x - 1][y + 1] == ' '))
			return true;
		else
			return false;
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		if ((field[x + 1][y + 1] == ' ') && (field[x - 1][y + 1] == ' '))
			return true;
		else
			return false;
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		if ((field[x - 1][y - 1] == ' ') && (field[x + 1][y - 1] == ' '))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y == 0) && (field[x + 1][y + 1] == ' '))
	{
			return true;
	}
	else if ((x == 0) && (y == N - 1))
	{
		if (field[x + 1][y - 1] == ' ')
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		if (field[x - 1][y - 1] == ' ')
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == 0))
	{
		if (field[x - 1][y + 1] == ' ')
			return true;
		else
			return false;
	}
	else if ((field[x][y] == '1') || (field[x][y] == 'P'))
	{
		return false;
	}
	else
	{
		return false;
	}
}

bool canPlace2(char field[N][N], int x, int y)
{
	if (field[x][y] == '1')
		return false;
	
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		if ((field[x + 1][y] == '1') || (field[x - 1][y] == '1') || (field[x][y + 1] == '1') || (field[x][y - 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		if ((field[x + 1][y] == '1') || (field[x][y + 1] == '1') || (field[x][y - 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		if ((field[x - 1][y] == '1') || (field[x][y + 1] == '1') || (field[x][y - 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		if ((field[x + 1][y] == '1') || (field[x - 1][y] == '1') || (field[x][y + 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		if ((field[x][y - 1] == '1') || (field[x - 1][y] == '1') || (field[x + 1][y] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y == 0))
	{
		if ((field[x + 1][y] == '1') || (field[x][y + 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y == N - 1))
	{
		if ((field[x + 1][y] == '1') || (field[x][y - 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == 0))
	{
		if ((field[x - 1][y] == '1') || (field[x][y + 1] == '1'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		if ((field[x][y - 1] == '1') || (field[x - 1][y] == '1'))
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

bool canPlace3(char field[N][N], int x, int y)
{
	if (field[x][y] == 'P')
		return false;
	
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		if ((field[x + 1][y] != 'P') && (field[x - 1][y] != 'P') && (field[x][y + 1] != 'P') && (field[x][y - 1] != 'P') && (field[x - 1][y - 1] != 'P')
			&& (field[x - 1][y + 1] != 'P') && (field[x + 1][y - 1] != 'P') && (field[x + 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		if ((field[x + 1][y] != 'P') && (field[x][y - 1] != 'P') && (field[x][y + 1] != 'P') && (field[x + 1][y - 1] != 'P') && (field[x + 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x - 1][y] != 'P') && (field[x + 1][y] != 'P') && (field[x - 1][y - 1] != 'P') && (field[x + 1][y - 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		if ((field[x - 1][y] != 'P') && (field[x][y - 1] != 'P') && (field[x][y + 1] != 'P') && (field[x - 1][y - 1] != 'P') && (field[x - 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		if ((field[x][y + 1] != 'P') && (field[x - 1][y] != 'P') && (field[x + 1][y] != 'P') && (field[x - 1][y + 1] != 'P') && (field[x + 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y == 0))
	{
		if ((field[x + 1][y] != 'P') && (field[x][y + 1] != 'P') && (field[x + 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == 0) && (y == N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x + 1][y] != 'P') && (field[x + 1][y - 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x - 1][y] != 'P') && (field[x - 1][y - 1] != 'P'))
			return true;
		else
			return false;
	}
	else if ((x == N - 1) && (y == 0))
	{
		if ((field[x - 1][y] != 'P') && (field[x][y + 1] != 'P') && (field[x - 1][y + 1] != 'P'))
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

void placeOneShip(char field[N][N], int size)
{
	bool firstPoint = false;

	for (int i = 0; i < size; ++i)
	{
		bool check;
		do
		{
			check = true;
			int x, y;

			cout << "Введите координаты палубы: ";
			cin >> x >> y;

			if ((x == -1) || (y == -1))
			{
				for (int i = 0; i < N; ++i)
				{
					for (int j = 0; j < N; ++j)
					{
						if (field[i][j] == '1')
							field[i][j] = ' ';
					}
				}
				check = false;
				firstPoint = false;
				i = 0;
				system("cls");
			}
			else
			{

				if ((x > N - 1) || (x < 0) || (y > N - 1) || (y < 0))
				{
					cout << "Вы вышли за пределы поля. Попробуйте ещё раз." << endl;
					check = false;
					Sleep(2000);
				}
				else if (!canPlace(field, x, y)) // Нельзя ставить наискосок.
				{
					cout << "Корабль нельзя здесь разместить. Попробуйте ещё раз." << endl;
					check = false;
					Sleep(2000);
				}
				else if (!firstPoint)
				{
					if (canPlace3(field, x, y))
					{
						field[x][y] = '1';
						firstPoint = true; // Размещение первой палубы.
					}
					else
					{
						cout << "Корабль нельзя здесь разместить. Попробуйте ещё раз." << endl;
						check = false;
						Sleep(2000);
					}
				}
				else
				{
					if ((!canPlace2(field, x, y)) || (!canPlace3(field, x, y)))
					{
						cout << "Корабль нельзя здесь разместить. Попробуйте ещё раз." << endl;
						check = false;
						Sleep(2000);
					}
					else
					{
						field[x][y] = '1';
					}
				}

				system("cls");

			}
				cout << "Ваше поле: " << endl;
				printField(field, false);
		} while (!check);

	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (field[i][j] == '1')
				field[i][j] = 'P';
		}
	}
}

void computerPlacement(char field[N][N], int size)
{
	bool firstPoint = false;

	for (int i = 0; i < size; ++i)
	{
		bool check;
		do
		{
			check = true;

			int x, y;
			x = rand() % N;
			y = rand() % N;

			if (!canPlace(field, x, y))
			{
				check = false;
			}
			else if (!firstPoint)
			{
				if (canPlace3(field, x, y))
				{
					field[x][y] = '1';
					firstPoint = true;
				}
				else
				{
					check = false;
				}
			}
			else
			{
				if ((!canPlace2(field, x, y)) || (!canPlace3(field, x, y)))
				{
					check = false;
				}
				else
				{
					field[x][y] = '1';
				}
			}

		} while (!check);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (field[i][j] == '1')
				field[i][j] = 'P';
		}
	}
}

void placeShips(char field[N][N], int modeLocation)
{
	
	if (modeLocation == 1)
	{
		cout << "Введите -1, если хотите разместить корабль заново." << endl;
		cout << "Расположите четырёхпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 4);

		cout << "Расположите трёхпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 3);

		cout << "Расположите ещё один трёхпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 3);

		cout << "Расположите двухпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 2);

		cout << "Расположите ещё один двухпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 2);

		cout << "Расположите ещё один двухпалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 2);

		cout << "Расположите однопалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 1);

		cout << "Расположите ещё один однопалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 1);

		cout << "Расположите ещё один однопалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 1);

		cout << "Расположите ещё один однопалубный корабль." << endl;
		Sleep(1500);
		placeOneShip(field, 1);
	}
	else if (modeLocation == 2)
	{
		computerPlacement(field, 4);
		computerPlacement(field, 3);
		computerPlacement(field, 3);
		computerPlacement(field, 2);
		computerPlacement(field, 2);
		computerPlacement(field, 2);
		computerPlacement(field, 1);
		computerPlacement(field, 1);
		computerPlacement(field, 1);
		computerPlacement(field, 1);
	}
}

bool isDestroyed(char field[N][N], int x, int y)
{
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x][y + 1] != 'P') && (field[x - 1][y] != 'P') && (field[x + 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x][y + 1] != 'P') && (field[x + 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		if ((field[x - 1][y] != 'P') && (field[x + 1][y] != 'P') && (field[x][y - 1] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x][y + 1] != 'P') && (field[x - 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		if ((field[x - 1][y] != 'P') && (field[x][y + 1] != 'P') && (field[x + 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == 0) && (y == 0))
	{
		if ((field[x][y + 1] != 'P') && (field[x + 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == 0) && (y == N - 1))
	{
		if ((field[x][y - 1] != 'P') && (field[x + 1][y] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
			if (field[x + 1][y] == 'X')
			{
				if (isDestroyed(field, x + 1, y))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		if ((field[x - 1][y] != 'P') && (field[x][y - 1] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
			if (field[x][y - 1] == 'X')
			{
				if (isDestroyed(field, x, y - 1))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((x == N - 1) && (y == 0))
	{
		if ((field[x - 1][y] != 'P') && (field[x][y + 1] != 'P'))
		{
			field[x][y] = 'D';
			if (field[x - 1][y] == 'X')
			{
				if (isDestroyed(field, x - 1, y))
					return true;
				else
					return false;
			}
			if (field[x][y + 1] == 'X')
			{
				if (isDestroyed(field, x, y + 1))
					return true;
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void fillWithX(char field[N][N], int x, int y)
{
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		field[x - 1][y - 1] = 'N';
		field[x - 1][y + 1] = 'N';
		field[x + 1][y - 1] = 'N';
		field[x + 1][y + 1] = 'N';
		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}

	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		field[x + 1][y - 1] = 'N';
		field[x + 1][y + 1] = 'N';

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		field[x - 1][y - 1] = 'N';
		field[x + 1][y - 1] = 'N';

		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		field[x - 1][y - 1] = 'N';
		field[x - 1][y + 1] = 'N';

		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		field[x + 1][y + 1] = 'N';
		field[x - 1][y + 1] = 'N';

		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}
	}
	else if ((x == 0) && (y == 0))
	{
		field[x + 1][y + 1] = 'N';

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}
	}
	else if ((x == 0) && (y == N - 1))
	{
		field[x + 1][y - 1] = 'N';

		if (field[x + 1][y] != 'D')
			field[x + 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x + 1, y);
		}

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		field[x - 1][y - 1] = 'N';

		if (field[x][y - 1] != 'D')
			field[x][y - 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y - 1);
		}

		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}
	}
	else if ((x == N - 1) && (y == 0))
	{
		field[x - 1][y + 1] = 'N';

		if (field[x - 1][y] != 'D')
			field[x - 1][y] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x - 1, y);
		}

		if (field[x][y + 1] != 'D')
			field[x][y + 1] = 'N';
		else
		{
			field[x][y] = 'N';
			fillWithX(field, x, y + 1);
		}
	}
}

void newXY(char field[N][N], int& x, int& y, int lastHitX, int lastHitY, int hits)
{
	int randomNum;
	if ((x != 0) && (y != 0) && (x != N - 1) && (y != N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 4 + 1;
			if (randomNum == 1)
			{
				x = lastHitX - 1;
				y = lastHitY;
			}
			else if (randomNum == 2)
			{
				x = lastHitX;
				y = lastHitY + 1;
			}
			else if (randomNum == 3)
			{
				x = lastHitX + 1;
				y = lastHitY;
			}
			else if (randomNum == 4)
			{
				x = lastHitX;
				y = lastHitY - 1;
			}
		}
		else
		{
			randomNum = rand() % 2 + 1;
			if (((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X')) && ((field[lastHitX + 1][lastHitY] == 'D')
				|| (field[lastHitX + 1][lastHitY] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
			else if (((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X')) && ((field[lastHitX][lastHitY + 1] == 'D')
				|| (field[lastHitX][lastHitY + 1] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
			else if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX + 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY - 1;
				}
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX - 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY + 1;
				}
			}
		}

	}
	else if ((x == 0) && (y != 0) && (y != N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 3 + 1;
			if (randomNum == 1)
			{
				x = lastHitX;
				y = lastHitY - 1;
			}
			else if (randomNum == 2)
			{
				x = lastHitX;
				y = lastHitY + 1;
			}
			else if (randomNum == 3)
			{
				x = lastHitX + 1;
				y = lastHitY;
			}
		}
		else
		{
			randomNum = rand() % 2 + 1;
			if (((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X')) && ((field[lastHitX][lastHitY + 1] == 'D') ||
				(field[lastHitX][lastHitY + 1] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
			else if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY + 1;
				}
			}
			else if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY - 1;
				}
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				++x;
				newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
		}
	}
	else if ((y == N - 1) && (x != 0) && (x != N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 3 + 1;
			if (randomNum == 1)
			{
				x = lastHitX - 1;
				y = lastHitY;
			}
			else if (randomNum == 2)
			{
				x = lastHitX + 1;
				y = lastHitY;
			}
			else if (randomNum == 3)
			{
				x = lastHitX;
				y = lastHitY - 1;
			}
		}
		else
		{
			randomNum = rand() % 2 + 1;
			if (((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X')) && ((field[lastHitX + 1][lastHitY] == 'D') ||
				(field[lastHitX + 1][lastHitY] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
			else if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX + 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX - 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				--y;
				newXY(field, x, y, lastHitX, lastHitY - 1, hits);
			}
		}
	}
	else if ((x == N - 1) && (y != 0) && (y != N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 3 + 1;
			if (randomNum == 1)
			{
				x = lastHitX - 1;
				y = lastHitY;
			}
			else if (randomNum == 2)
			{
				x = lastHitX;
				y = lastHitY - 1;
			}
			else if (randomNum == 3)
			{
				x = lastHitX;
				y = lastHitY + 1;
			}
		}
		else
		{
			randomNum = rand() % 2 + 1;
			if (((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X')) && ((field[lastHitX][lastHitY + 1] == 'D') ||
				(field[lastHitX][lastHitY + 1] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
			else if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY + 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY - 1;
				}
			}
			else if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX, lastHitY - 1, hits);
				else if (randomNum == 2)
				{
					x = lastHitX;
					y = lastHitY + 1;
				}
			}
			else if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				--x;
				newXY(field, x, y, lastHitX - 1, lastHitY, hits);
			}
		}
	}
	else if ((y == 0) && (x != 0) && (x != N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 3 + 1;
			if (randomNum == 1)
			{
				x = lastHitX - 1;
				y = lastHitY;
			}
			else if (randomNum == 2)
			{
				x = lastHitX;
				y = lastHitY + 1;
			}
			else if (randomNum == 3)
			{
				x = lastHitX - 1;
				y = lastHitY;
			}
		}
		else
		{
			randomNum = rand() % 2 + 1;
			if (((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X')) && ((field[lastHitX + 1][lastHitY] == 'D') ||
				(field[lastHitX + 1][lastHitY] == 'X')))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
			else if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX - 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX + 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				if (randomNum == 1)
					newXY(field, x, y, lastHitX + 1, lastHitY, hits);
				else if (randomNum == 2)
				{
					x = lastHitX - 1;
					y = lastHitY;
				}
			}
			else if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				++y;
				newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
		}
	}
	else if ((x == 0) && (y == 0))
	{
		if (hits < 2)
		{
			randomNum = rand() % 2 + 1;
			if (randomNum == 1)
			{
				x = x + 1;
				y = y;
			}
			else if (randomNum == 2)
			{
				x = x;
				y = y + 1;
			}
		}
		else
		{
			if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				++y;
				newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				++x;
				newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
		}
	}
	else if ((x == 0) && (y == N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 2 + 1;
			if (randomNum == 1)
			{
				x = x + 1;
				y = y;
			}
			else if (randomNum == 2)
			{
				x = x;
				y = y - 1;
			}
		}
		else
		{
			if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				--y;
				newXY(field, x, y, lastHitX, lastHitY - 1, hits);
			}
			else if ((field[lastHitX + 1][lastHitY] == 'D') || (field[lastHitX + 1][lastHitY] == 'X'))
			{
				++x;
				newXY(field, x, y, lastHitX + 1, lastHitY, hits);
			}
		}
	}
	else if ((x == N - 1) && (y == N - 1))
	{
		if (hits < 2)
		{
			randomNum = rand() % 2 + 1;
			if (randomNum == 1)
			{
				x = x;
				y = y - 1;
			}
			else if (randomNum == 2)
			{
				x = x - 1;
				y = y;
			}
		}
		else
		{
			if ((field[lastHitX][lastHitY - 1] == 'D') || (field[lastHitX][lastHitY - 1] == 'X'))
			{
				--y;
				newXY(field, x, y, lastHitX, lastHitY - 1, hits);
			}
			else if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				--x;
				newXY(field, x, y, lastHitX - 1, lastHitY, hits);
			}
		}
	}
	else if ((x == N - 1) && (y == 0))
	{
		if (hits < 2)
		{
			randomNum = rand() % 2 + 1;
			if (randomNum == 1)
			{
				x = x - 1;
				y = y;
			}
			else if (randomNum == 2)
			{
				x = x;
				y = y + 1;
			}
		}
		else
		{
			if ((field[lastHitX - 1][lastHitY] == 'D') || (field[lastHitX - 1][lastHitY] == 'X'))
			{
				--x;
				newXY(field, x, y, lastHitX - 1, lastHitY, hits);
			}
			else if ((field[lastHitX][lastHitY + 1] == 'D') || (field[lastHitX][lastHitY + 1] == 'X'))
			{
				++y;
				newXY(field, x, y, lastHitX, lastHitY + 1, hits);
			}
		}
	}
}

bool isFieldDestroyed(char field[N][N])
{
	bool check = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if ((field[i][j] == '1') || (field[i][j] == 'P'))
				check = false;
		}
	}

	return check;
}

void playGame(char field1[N][N], char field2[N][N], int mode, int AIMode)
{
	if (mode == 1)
		cout << "Вы ходите первыми." << endl;
	
	// Для режима человек-компьютер.
	bool computerAI = false;
	bool repeat = false;
	int xP, yP, xC, yC; // xP - x для  первого игрока, xC - для второго.
	int lastHitX, lastHitY; // Последнее попадание у компьютера.
	int hits = 0;

	// Для режима компьютер-компьютер.
	int x1, x2, y1, y2;
	int lastHitX1, lastHitX2, lastHitY1, lastHitY2, hits1 = 0, hits2 = 0;
	bool computerAI1 = false, computerAI2 = false;

	do
	{
		if (mode == 1)
		{
			do
			{
				repeat = false;

				cout << "Введите координаты для выстрела: ";
				cin >> xP >> yP;

				if ((xP < 0) || (xP > N - 1) || (yP < 0) || (yP > N - 1))
				{
					cout << "Вы вышли за пределы поля. Попробуйте ещё раз." << endl;
					repeat = true;
					Sleep(1500);
				}
				else if ((field2[xP][yP] != 'P') && (field2[xP][yP] != '#') && (field2[xP][yP] != 'X') && (field2[xP][yP] != 'D') && (field2[xP][yP] != 'N'))
				{
					cout << "Мимо!" << endl;
					field2[xP][yP] = '#';
					Sleep(1500);
				}
				else if ((field2[xP][yP] == 'X') || (field2[xP][yP] == '#') || (field2[xP][yP] == 'D') || (field2[xP][yP] == 'N'))
				{
					cout << "Вы уже стреляли в эту область. Попробуйте ещё раз." << endl;
					repeat = true;
					Sleep(1500);
				}
				else if (field2[xP][yP] == 'P')
				{
					cout << "Вы попали! Вы можете ходить ещё раз." << endl;
					repeat = true;
					field2[xP][yP] = 'X';
					Sleep(1500);

					if (isDestroyed(field2, xP, yP))
					{
						cout << "Карабль уничтожен!" << endl;
						fillWithX(field2, xP, yP);
						Sleep(2000);
					}
				}
				system("cls");
				cout << "Ваше поле: " << endl;
				printField(field1, false);
				cout << "Поле компьютера: " << endl;
				printField(field2, true);
			} while (repeat);

			if (!isFieldDestroyed(field2))
			{
				cout << "Следующий ходит компьютер." << endl;
				do
				{
					repeat = false;
					if (computerAI) // Если было попадание, то стреляем рядом.
					{
						newXY(field1, xC, yC, lastHitX, lastHitY, hits); // В x и y будет занесён результат через ссылки.
					}
					else
					{
						xC = rand() % N;
						yC = rand() % N;
					}

					if ((field1[xC][yC] != 'P') && (field1[xC][yC] != '#') && (field1[xC][yC] != 'X') && (field1[xC][yC] != 'D') && (field1[xC][yC] != 'N'))
					{
						cout << "Мимо!" << endl;
						field1[xC][yC] = '#';
						Sleep(1500);
					}
					else if ((field1[xC][yC] == 'X') || (field1[xC][yC] == '#') || (field1[xC][yC] == 'D') || (field1[xC][yC] == 'N'))
					{
						repeat = true;
					}
					else if (field1[xC][yC] == 'P')
					{
						repeat = true;
						field1[xC][yC] = 'X';
						if (AIMode == 2)
						{
							computerAI = true;
						}
						cout << "Компьютер попал!" << endl;
						
						lastHitX = xC;
						lastHitY = yC;
						++hits;
						
						Sleep(1500);

						if (isDestroyed(field1, xC, yC))
						{
							computerAI = false;
							hits = 0;
							cout << "Корабль уничтожен!" << endl;
							fillWithX(field1, xC, yC);
							Sleep(2000);
						}
					}

					system("cls");
					cout << "Ваше поле: " << endl;
					printField(field1, false);
					cout << "Поле компьютера: " << endl;
					printField(field2, true);

				} while (repeat);
			}
		}
		else if (mode == 2)
		{
			do
			{
				repeat = false;
				cout << "Следующий ходит компьютер 1." << endl;

				if (computerAI1)
				{
					newXY(field2, x1, y1, lastHitX1, lastHitY1, hits1);
				}
				else
				{
					x1 = rand() % N;
					y1 = rand() % N;
				}

				if ((field2[x1][y1] != 'P') && (field2[x1][y1] != '#') && (field2[x1][y1] != 'X') && (field2[x1][y1] != 'D') && (field2[x1][y1] != 'N'))
				{
					Sleep(2000);
					cout << "Мимо!" << endl;
					field2[x1][y1] = '#';
					Sleep(3500);
				}
				else if ((field2[x1][y1] == 'X') || (field2[x1][y1] == '#') || (field2[x1][y1] == 'D') || (field2[x1][y1] == 'N'))
				{
					repeat = true;
				}
				else if (field2[x1][y1] == 'P')
				{
					repeat = true;
					field2[x1][y1] = 'X';
					if (AIMode == 2)
					{
						computerAI1 = true;
					}
					Sleep(2000);
					cout << "Компьютер 1 попал!" << endl;

					lastHitX1 = x1;
					lastHitY1 = y1;
					++hits1;

					Sleep(3500);

					if (isDestroyed(field2, x1, y1))
					{
						computerAI1 = false;
						hits1 = 0;
						cout << "Корабль уничтожен!" << endl;
						fillWithX(field2, x1, y1);
						Sleep(4000);
					}
				}

				system("cls");
				cout << "Поле компьютера 1: " << endl;
				printField(field1, false);
				cout << "Поле компьютера 2: " << endl;
				printField(field2, true);

			} while (repeat);

			Sleep(2500);
			if (!isFieldDestroyed(field2))
			{
				cout << "Следующий ходит компьютер 2." << endl;

				do
				{
					repeat = false;

					if (computerAI2)
					{
						newXY(field1, x2, y2, lastHitX2, lastHitY2, hits2);
					}
					else
					{
						
						x2 = rand() % N;
						y2 = rand() % N;
					}

					if ((field1[x2][y2] != 'P') && (field1[x2][y2] != '#') && (field1[x2][y2] != 'X') && (field1[x2][y2] != 'D') && (field1[x2][y2] != 'N'))
					{
						Sleep(2000);
						cout << "Мимо!" << endl;
						field1[x2][y2] = '#';
						Sleep(3500);
					}
					else if ((field1[x2][y2] == 'X') || (field1[x2][y2] == '#') || (field1[x2][y2] == 'D') || (field1[x2][y2] == 'N'))
					{
						repeat = true;
					}
					else if (field1[x2][y2] == 'P')
					{
						repeat = true;
						field1[x2][y2] = 'X';
						if (AIMode == 2)
						{
							computerAI2 = true;
						}
						Sleep(2000);
						cout << "Компьютер 2 попал!" << endl;

						lastHitX2 = x2;
						lastHitY2 = y2;
						++hits2;

						Sleep(3500);

						if (isDestroyed(field1, x2, y2))
						{
							computerAI2 = false;
							hits2 = 0;
							cout << "Корабль уничтожен!" << endl;
							fillWithX(field1, x2, y2);
							Sleep(4000);
						}
					}

					system("cls");
					cout << "Поле компьютера 1: " << endl;
					printField(field1, false);
					cout << "Поле компьютера 2: " << endl;
					printField(field2, true);

				} while (repeat);
				Sleep(2500);
			}

		}
	} while ((!isFieldDestroyed(field1)) && (!isFieldDestroyed(field2)));

	if (isFieldDestroyed(field1))
	{
		if (mode == 1)
			cout << "Вы проиграли." << endl;
		else if (mode == 2)
			cout << "Компьютер 2 победил!" << endl;
	}
	if (isFieldDestroyed(field2))
	{
		if (mode == 1)
			cout << "Поздравляем! Вы победили!" << endl;
		else if (mode == 2)
			cout << "Компьютер 1 победил!" << endl;
	}
	Sleep(4000);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	cout << "Добро пожаловать в игру \"Морской бой\"!" << endl;

	bool choice;
	do
	{
		int mode;
		char field1[N][N], field2[N][N];

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				field1[i][j] = ' ';
				field2[i][j] = ' '; // Заполнение пробелами.
			}
		}

		cout << "1 - Человек - компьютер" << endl;
		cout << "2 - Компьютер - компьютер" << endl;
		cout << "Выберете режим игры: ";
		cin >> mode;

		int AIMode;
		cout << "1 - случайный выстрел" << endl;
		cout << "2 - интеллектуальная игра" << endl;
		cout << "Выберете режим игры компьютера: ";
		cin >> AIMode;

		if (mode == 1)
		{
			int modeLocation;
			cout << "1 - игрок расставляет вручную" << endl;
			cout << "2 - компьютер расставляет за игрока" << endl;
			cout << "Выберете расстановку: ";
			cin >> modeLocation;

			if (modeLocation == 1)
			{
				cout << "Ваше поле: " << endl;
				printField(field1, false); // Сразу выводится поле при ручной расстановке.
			}

			placeShips(field1, modeLocation);

			if (modeLocation == 2)
			{
				cout << "Компьютер расставил корабли за вас!" << endl;
				cout << "Ваше поле: " << endl;
				printField(field1, false);
			}

			placeShips(field2, 2);
			cout << "Поле компьютера: " << endl;
			printField(field2, true);

		}
		else if (mode == 2)
		{
			placeShips(field1, 2);
			placeShips(field2, 2);

			cout << "Поле первого компьютера: " << endl;
			printField(field1, false);

			cout << "Поле второго компьютера: " << endl;
			printField(field2, true);
			Sleep(2000);
		}
		playGame(field1, field2, mode, AIMode);

		cout << "0 - нет\n1 - да" << endl;
		cout << "Хотите поиграть ещё раз? -> ";
		cin >> choice;
		system("cls");
	} while (choice);

	return 0;
}