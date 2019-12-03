#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <iomanip>

using namespace std;

const int H = 40, W =80;

bool map[H][W];

void setXY(short x, short y)
{
	COORD coord = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showXY(short x, short y)
{
	setXY(20, 20);
	cout << "X:" << setw(3) << x << " Y:" << setw(3) << y;
	setXY(x, y);
}

bool check(int x, int y)
{
	if (map[x][y] == 0) {
		return 1;
	}
	return 0;
}

int main()
{

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			setXY(i, j);
			if (map[i][j] == 1) {
				cout << "#";
			}
		}
		cout << endl;
	}

	int x = H / 2, y = W / 2;
	bool flag = true;
	int t = 100;
	enum Moves { UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75, Enter = 13 };
	while (flag) {
		switch (_getch()) {
		case RIGHT:
			if (check(x, y + 1)) {
				setXY(x, y);
				cout << " ";
				++y;
				setXY(x, y);
				cout << "O";
				showXY(x, y);
				Sleep(t);
			}
			break;
		case LEFT:
			if (check(x, y - 1)) {
				setXY(x, y);
				cout << " ";
				--y;
				setXY(x, y);
				cout << "O";
				showXY(x, y);
				Sleep(t);
			}
			break;
		case UP:
			if (check(x - 1, y)) {
				setXY(x, y);
				cout << " ";
				--x;
				setXY(x, y);
				cout << "O";
				showXY(x, y);
				Sleep(t);
			}
			break;
		case DOWN:
			if (check(x + 1, y)) {
				setXY(x, y);
				cout << " ";
				++x;
				setXY(x, y);
				cout << "O";
				showXY(x, y);
				Sleep(t);
			}
			break;
		case Enter:
			flag = false;
			break;
		}
	}

}