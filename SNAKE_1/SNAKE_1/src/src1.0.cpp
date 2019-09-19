#include "../h/Header.h"

bool GameOver;
bool Border = true;
bool End = false;
const int width = 20, height = 20;
int score = 0;
int n, fruit, x, y, fx, fy, Fx, Fy;

//int tailX[(width-1)*(width-1)], tailY[(height-1)*(height-1)], n;
std::array<int, (width - 1)*(width - 1) > tailX;
std::array<int, (height - 1)*(height - 1) > tailY;
/*class Map { public: const int width = 20, height = 20; int score = 0; }; Map map;
class Fruit { public:int x = 1, y = 1; }; Fruit fruit;
class Snake { public: int x = 1, y = 1; }; Snake snake;*/

enum Direction { stop = 0, left, right, up, down }; Direction dir; 

void SlowN()
{
	n=n+3;
}

int random(int x)
{
	return rand() % x;
}

int increment(int x)
{
	return x + 1;
}

int decrement(int x)
{
	return x-1;
}

void Startup()
{
	GameOver = false;
	dir = stop;
	x = width / 2;
	y = height / 2;
	fx = random(width);
	fy = random(height);
	Fx = 1000000000000000;
	Fy = 1000000000000000;
	fruit = 0;
	n = 0;
	score = 0;
	tailX.fill(100);
	tailY.fill(100);
}

void Event1()
{
	if (fruit == 10)
	{
		Fx = random(width);
		Fy = random(height);
	}
	else if (fruit < 10)
	{
		Fx = 10000000000000000;
		Fy = 10000000000000000;
	}
	else if (fruit > 10)
	{
		Fx = 10000000000000000;
		Fy = 10000000000000000;
		fruit = 0;
	}
}


void Render()
{
	system("cls");
	for (int i = 0; i < width+2; i++) { std::cout << "#"; } std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j==0) std::cout << "#"; 
			if (j == x && i == y) std::cout << "@";
			else if (j == fx && i == fy) std::cout << "F";
			else if (j == Fx && i == Fy) std::cout << "*";
			else 
			{
				bool tail = false;
				for (int k = 0; k < n; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "o";
						tail = true;
					}
				}

				if (!tail) std::cout << " ";
			}

			if (j == width - 1) std::cout << "#";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++) { std::cout << "#"; } std::cout << std::endl;

	std::cout << "Score: " << score;
}

void Control()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = left;
			break;
		case 'd':
			dir = right;
			break;
		case 'w':
			dir = up;
			break;
		case 's':
			dir = down;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}

void AI()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int backX, backY;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < n; i++)
	{
		backX = tailX[i];
		backY = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = backX;
		prevY = backY;
	}
	
	switch (dir)
	{
	case left:
		x--;
		
		break;
	case right:
		x++;
	
		break;
	case up:
		y--;
		break;
	case down:
		y++;
		break;
	default:
		break;
	}

	if (Border) {
		if (x > width - 1 || x < 0 || y > height - 1 || y < 0)
			GameOver = true;
	}
	else {
		if (x > width - 1) x = 0;
		if (x < 0) x = width;
		if (y > height - 1) y = 0;
		if (y < 0) y = height;
	}

	for (int i = 0; i < n; i++)
		if ( tailX[i] == x &&  tailY[i] == y)
			GameOver = true;

	if (x == fx && y == fy)
	{

		n++;
		fruit++;
		score++;
		fx = random(width);
		fy = random(height);
		Event1();
	}
	if (x == Fx && y == Fy)
	{
	
		n=n+4;
		score=score+5;
		
		fruit=0;
		Event1();
	}
	
}


void Game()
{
	Startup();
	while (!GameOver)
	{
		Render();
		Control();
		AI();
		Sleep(30);

	}
	
	
}


int main()
{
	char input;
	while (End = true)
	{
		Game();
		std::cout << "\nGame Over! ";
		system("Pause");
		
		//HS 142
	}

		
	 
	
	
}