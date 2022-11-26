#include <iostream>
#include <conio.h>
#include "MyLibrary.h"
using namespace std;

const int MAX = 100;
int lengthOfSnake = 3;

void borderTop();
void borderBottom();
void borderLeft();
void borderRight();
void drawBorderGame();

void initSnake(int snakeX[], int snakeY[]);
void drawSnake(int snakeX[], int snakeY[]);
void removeOldSnake(int snakeX[], int snakeY[]);

void changeDirection(int &checkDirection, int &x, int &y);

void addToArray(int array[], int value);
void removeFromArray(int array[], int pos);
void snakeHandling(int snakeX[], int snakeY[], int headSnakeX, int headSnakeY, int &foodX, int &foodY);

bool checkSnakeTouchingTheBorder(int headSnakeX, int headSnakeY);
bool checkSnakeTouchingItsTail(int snakeX[], int snakeY[]);
bool checkGameOver(int snakeX[], int snakeY[]);

void drawFood(int &foodX, int &foodY, int snakeX[], int snakeY[]);
bool checkSpawnsFood(int foodX, int foodY, int snakeX[], int snakeY[]);
bool checkEatFood(int foodX, int foodY, int headSnakeX, int headSnakeY);

int main()
{
	system("cls");
	int snakeX[MAX];
	int snakeY[MAX];

	bool gameOver = false;

	drawBorderGame();

	initSnake(snakeX, snakeY);
	drawSnake(snakeX, snakeY);
	int x = 50;
	int y = 13;

	int checkDirection = 2; // Cho nó mặc định là đi qua phải
							/*
								check = 0 là chạm biên trên -> đi xuống
								check = 1 là chạm biên dưới -> đi lên
								check = 2 là chạm biên trái -> đi qua phải
								check = 3 là chạm biên phải -> đi qua trái
							*/

	srand(time(NULL));
	int foodX = 0;
	int foodY = 0;

	drawFood(foodX, foodY, snakeX, snakeY);

	while (gameOver == false)
	{
		// Sử dụng backspace để xóa không bị nháy màn như system("cls")
		removeOldSnake(snakeX, snakeY);

		// Điều khiển
		changeDirection(checkDirection, x, y);

		// Xử lý di chuyển các thứ
		snakeHandling(snakeX, snakeY, x, y, foodX, foodY);

		// Kiem tra win or lose
		gameOver = checkGameOver(snakeX, snakeY);
		Sleep(100);
	}

	_getch();
	return 0;
}

void borderTop()
{
	int x = 10;
	int y = 1;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void borderBottom()
{
	int x = 10;
	int y = 26;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void borderLeft()
{
	int x = 10;
	int y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "|";
		y++;
	}
}

void borderRight()
{
	int x = 100;
	int y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "|";
		y++;
	}
}

void drawBorderGame()
{
	SetColor(11);
	borderTop();
	borderBottom();
	borderLeft();
	borderRight();
	SetColor(7);
}

void initSnake(int snakeX[], int snakeY[])
{
	int x = 50;
	int y = 13;
	// Cho con rắn ở giữa map tọa độ con rắn (50, 13)
	for (int i = 0; i < lengthOfSnake; i++)
	{
		snakeX[i] = x;
		snakeY[i] = y;
		x--;
	}
}

void drawSnake(int snakeX[], int snakeY[])
{
	/*int changeColors = rand() % (15 - 1 + 1) + 1;
	SetColor(changeColors);*/
	for (int i = 0; i < lengthOfSnake; i++)
	{
		gotoXY(snakeX[i], snakeY[i]);

		if (i == 0)
			cout << "0";
		else
			cout << "o";
	}
}

void removeOldSnake(int snakeX[], int snakeY[]) // Xóa bằng backspace
{
	for (int i = 0; i < lengthOfSnake; i++)
	{
		gotoXY(snakeX[i], snakeY[i]);
		cout << " ";
	}
}

void addToArray(int array[], int value)
{
	for (int i = lengthOfSnake; i > 0; i--)
	{
		array[i] = array[i - 1];
	}

	array[0] = value;
	lengthOfSnake++;
}

void removeFromArray(int array[], int pos)
{
	for (int i = pos; i < lengthOfSnake; i++)
	{
		array[i] = array[i + 1];
	}

	lengthOfSnake--;
}

void snakeHandling(int snakeX[], int snakeY[], int headSnakeX, int headSnakeY, int &foodX, int &foodY) // x, y là tọa độ mới sẽ thêm vào đầu mảng (con rắn) khi di chuyển
{
	// Thêm tọa độ mới cho mảng
	addToArray(snakeX, headSnakeX);
	addToArray(snakeY, headSnakeY);

	if (checkEatFood(foodX, foodY, snakeX[0], snakeY[0]) == false) // Rắn không ăn đồ ăn thì xóa đuôi lúc di chuyển
	{
		// Xóa tọa độ cuối mảng
		removeFromArray(snakeX, lengthOfSnake - 1);
		removeFromArray(snakeY, lengthOfSnake - 1);
	}
	else
		drawFood(foodX, foodY, snakeX, snakeY);
	// Nếu ăn thì nó dài thêm khỏi xóa

	// Vẽ rắn
	drawSnake(snakeX, snakeY);
}

bool checkSnakeTouchingTheBorder(int headSnakeX, int headSnakeY)
{
	// Chạm biên trên
	if (headSnakeY == 1 && (headSnakeX >= 10 && headSnakeX <= 100))
	{
		return true; // Game over
	}
	// Chạm biên dưới
	else if (headSnakeY == 26 && (headSnakeX >= 10 && headSnakeX <= 100))
	{
		return true; // Game over
	}
	// Chạm biên trái
	else if (headSnakeX == 10 && (headSnakeY >= 1 && headSnakeY <= 26))
	{
		return true; // Game over
	}
	// Chạm biên phải
	else if (headSnakeX == 100 && (headSnakeY >= 1 && headSnakeY <= 26))
	{
		return true; // Game over
	}

	return false;
}

bool checkSnakeTouchingItsTail(int snakeX[], int snakeY[])
{
	for (int i = 1; i < lengthOfSnake; i++)
	{
		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
			return true;
	}

	return false;
}

bool checkGameOver(int snakeX[], int snakeY[])
{
	bool gameOver1 = checkSnakeTouchingItsTail(snakeX, snakeY);
	bool gameOver2 = checkSnakeTouchingTheBorder(snakeX[0], snakeY[0]);

	if (gameOver1 == true || gameOver2 == true)
		return true;
	else
		return false;
}

void drawFood(int &foodX, int &foodY, int snakeX[], int snakeY[])
{
	do
	{
		// rand() % (b - a + 1) + a //Random Số từ a tới b [a, b]
		foodX = rand() % (99 - 11 + 1) + 11;
		foodY = rand() % (25 - 2 + 1) + 2;

	} while (checkSpawnsFood(foodX, foodY, snakeX, snakeY) == true);

	int changeColors = rand() % (15 - 1 + 1) + 1;
	SetColor(changeColors);
	gotoXY(foodX, foodY);
	cout << "#";

	// SetColor(7); // 7 là màu trắng (chỉnh con rắn về màu trắng)
}

bool checkSpawnsFood(int foodX, int foodY, int snakeX[], int snakeY[])
{
	for (int i = 0; i < lengthOfSnake; i++)
	{
		if (foodX == snakeX[i] && foodY == snakeY[i])
		{
			// Kiểm tra coi đồ ăn nó có hiện ra trùng lên con rắn không?,
			// không thì đồ ăn tàng hình
			return true;
		}
	}

	return false;
}

bool checkEatFood(int foodX, int foodY, int headSnakeX, int headSnakeY)
{
	if (foodX == headSnakeX && foodY == headSnakeY)
	{
		return true;
	}

	return false;
}

void changeDirection(int &checkDirection, int &x, int &y)
{
	if (_kbhit()) // Hàm này nhập từ phím nó sẽ trả true còn không nhập gì nó trả false
	{
		char characterUserEnter = _getch();

		if (characterUserEnter == -32) // Phím mũi tên là PHÍM KÉP nên có 2 mã ASCII, mã chung là -32
		{
			characterUserEnter = _getch();

			if (characterUserEnter == 72 && checkDirection != 0) // ASCII của mũi tên đi LÊN là 72
			{
				checkDirection = 1;
			}
			else if (characterUserEnter == 80 && checkDirection != 1) // ASCII của mũi tên đi XUỐNG là 80
			{
				checkDirection = 0;
			}
			else if (characterUserEnter == 75 && checkDirection != 2) // ASCII của mũi tên đi TRÁI là 75
			{
				checkDirection = 3;
			}
			else if (characterUserEnter == 77 && checkDirection != 3) // ASCII của mũi tên đi PHẢI là 77
			{
				checkDirection = 2;
			}
		}
	}

	if (checkDirection == 0) //đi xuống
	{
		y++;
	}
	else if (checkDirection == 1) //đi lên
	{
		y--;
	}
	else if (checkDirection == 2) //đi qua phải
	{
		x++;
	}
	else if (checkDirection == 3) //đi qua trái
	{
		x--;
	}
}