#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cmath>
#include <windows.h>
using namespace std;

//光标定位 
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

//定义地图的长宽，蛇的坐标，长度，方向，食物的位置
int m = 20, n = 25;

struct node
{
	int x, y;
}snake[1000];
int snake_length, dir;
node food;
int direction_x = 0, direction_y = 1;

//函数列表
void locate(int x, int y);
void hide();
double random(double start, double end);
void print_wall();
void print_snake();
bool is_correct();
bool print_food();
bool go_ahead();

//主函数
int main()
{
	int hard = 4;
	//设置初始蛇长，位置，方向
	snake_length = 5;
	clock_t a, b;
	char ch;
	double hard_len;
	for (int i = 0; i <= 4; i++)
	{
		snake[i].x = 1;
		snake[i].y = 5 - i;
	}
	//初始化地图，蛇与食物
	system("cls");
	hide();
	print_wall();
	print_food();
	print_snake();
	//开始游戏
	while (1)
	{
		//难度随长度增加而提高
		hard_len = (double)snake_length / (double)(m*n);
		//调节时间，单位是ms
		a = clock();
		while (1)
		{
			b = clock();
			if (b - a >= (int)(400 - 30 * hard)*(1 - sqrt(hard_len))) break;
		}
		//键盘上下左右键，换向操作
		if (_kbhit())
		{
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
				switch (ch)
				{
				case 72:
					if (direction_x == 1) break;
					direction_y = 0;
					direction_x = -1;
					break;
				case 80:
					if (direction_x == -1) break;
					direction_y = 0;
					direction_x = 1;
					break;
				case 75:
					if (direction_y == 1) break;
					direction_y = -1;
					direction_x = 0;
					break;
				case 77:
					if (direction_y == -1) break;
					direction_y = 1;
					direction_x = 0;
					break;
				}
			}
		}
		//前进操作
		if (!go_ahead()) break;
	}
	system("pause");
	return 0;
}

//定位
void locate(int x, int y)
{
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};

//隐藏光标
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cursor_info);
}

//生成随机数
double random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

//输出墙
void print_wall()
{
	for (int i = 0; i < n + 2; ++i)
		cout << "#";
	cout << endl;
	for (int j = 0; j < m; ++j)
	{
		cout << "#";
		for (int i = 0; i < n; ++i)
			cout << " ";
		cout << "#" << endl;
	}
	for (int i = 0; i < n + 2; ++i)
		cout << "#";
}

//初始化蛇
void print_snake()
{
	locate(snake[0].x, snake[0].y);
	cout << "*";
	for (int i = 1; i <= snake_length - 1; ++i)
	{
		locate(snake[i].x, snake[i].y);
		cout << "o";
	}
}

//判断是否撞墙或者自撞
bool is_correct()
{
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == m + 1 || snake[0].y == n + 1)
		return false;
	for (int i = 1; i <= snake_length - 1; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			return false;
	}
	return true;
}

//随机生成食物位置
bool print_food()
{
	srand((unsigned)time(0));
	bool e;
	while (1)
	{
		e = true;
		int i = (int)random(0, m) + 1;
		int j = (int)random(0, n) + 1;
		food.x = i; food.y = j;
		for (int k = 0; k <= snake_length - 1; k++)
		{
			if (snake[k].x == food.x && snake[k].y == food.y)
			{
				e = false;
				break;
			}
		}
		if (e) break;
	}
	locate(food.x, food.y);
	cout << "$";
	return true;
}

//蛇的前进
bool go_ahead()
{
	node temp;
	bool flag = false;
	temp = snake[snake_length - 1];
	for (int i = snake_length - 1; i >= 1; i--)
		snake[i] = snake[i - 1];
	//换向操作
	snake[0].x += direction_x;
	snake[0].y += direction_y;
	//将原来蛇头的位置当做第一节蛇身
	locate(snake[1].x, snake[1].y);
	cout << "o";
	//吃到了食物
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		++snake_length;
		flag = true;
		//尾巴保留
		snake[snake_length - 1] = temp;
		//新增食物点
		print_food();
	}
	//输出此时蛇状态
	else
	{
		//如果此时没吃食物，则将最后一节尾巴变为空
		locate(temp.x, temp.y);
		cout << " ";
	}

	locate(snake[0].x, snake[0].y);
	cout << "*";
	//如果撞到墙壁或自身
	if (!is_correct())
	{
		system("cls");
		cout << "游戏结束" << endl;
		return false;
	}
	return true;
}
