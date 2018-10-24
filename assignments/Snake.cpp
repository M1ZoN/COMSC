/***************************************************************
Problem: Snake
Description: Snake
Name: Adeola Morren,Mukhammadnozim Islamov
ID: 1632933/ 1668193
Date: 11/18/17
Status: ( complete)
****************************************************************/
#include<iostream>
#include"windows.h"
#include<vector>
#include<random>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

void Draw(int &x, int &y, int &fruitX, int &fruitY, int &score, int nTail, vector<int>&tailX, vector<int>&tailY) {
	system("cls");

	for (int i = 0; i < WIDTH; i++) {
		cout << '#';
	}cout << endl;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (j == 0 || j == HEIGHT - 1) {
				cout << '#';
			}

			else if (i == y && j == x) {
				cout << 'O';
			}
			else if (i == fruitY && j == fruitX) {
				cout << 'F';
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX.at(k) == j && tailY.at(k) == i) {
						cout << 'o';
						print = true;
					}
				}
				if (!print) {
					cout << ' ';
				}
			}

		}
		cout << endl;
	}
	for (int i = 0; i < WIDTH; i++) {
		cout << '#';
	}cout << endl;
	cout << "Score: " << score << endl;
}


void Input(bool &gameOver, int &fruitX, int &fruitY, int &x, int &y, int &score, int &nTail, vector<int>&tailX, vector<int>&tailY) {
	int prevX = tailX.at(0);
	int prevY = tailY.at(0);
	int prev2X = 0, prev2Y = 0;
	tailX.at(0) = x;
	tailY.at(0) = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX.at(i);
		prev2Y = tailY.at(i);
		tailX.at(i) = prevX;
		tailY.at(i) = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		y++;
	}
	if (GetAsyncKeyState(VK_UP)) {
		y--;
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		x++;
	}

	if (GetAsyncKeyState(VK_LEFT)) {
		x--;
	}
	if (GetAsyncKeyState(VK_ESCAPE) || x >= WIDTH - 1 || x <= 0 || y >= HEIGHT || y<0) {
		gameOver = true;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX.at(i) == x && tailY.at(i) == y) {
			gameOver = true;
		}
	}
	if (gameOver) {
		system("cls");
		cout << "Game Over" << endl;
	}
	if (x == fruitX && y == fruitY) {
		score++;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}

}

int main() {
	bool gameOver = false;
	vector<int>tailX(100);
	vector<int>tailY(100);
	int nTail = 0;
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int>distribution(1, WIDTH);
	int dice_roll = distribution(generator);
	int x = WIDTH / 2, y = HEIGHT / 2, fruitX = dice_roll, fruitY = dice_roll, score = 0;

	while (!gameOver) {
		Draw(x, y, fruitX, fruitY, score, nTail, tailX, tailY);
		system("pause>nul");
		Input(gameOver, fruitX, fruitY, x, y, score, nTail, tailX, tailY);
	}

	return 0;
}