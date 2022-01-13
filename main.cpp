#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

#define WIDTH 40
#define HEIGHT 26
using namespace std;


int score = 0;
bool gameOver = false;

enum direction {STOP, UP, DOWN, LEFT, RIGHT} dir;


int posX, posY, fruitX, fruitY;

void getInput() {
    if (_kbhit()) {
        switch(_getch()) {
    case 'w':
        dir = UP;
        break;
    case 'a':
        dir = LEFT;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'd':
        dir = RIGHT;
        break;
    default:
        break;

        }
    }
}
void moveSnake() {
    switch(dir) {

    case UP:
        posY--;
        Sleep(45);
        break;
    case DOWN:
        posY++;
        Sleep(45);
        break;
    case LEFT:
        posX--;
        Sleep(45);
        break;
    case RIGHT:
        posX++;
        Sleep(45);
        break;
    default:
        break;
    }
    if (posY <= 0 || posY >= HEIGHT || posX <= 0 || posX >= WIDTH) {
        gameOver = true;
        cout << endl << "Game over!" << endl;
    }


}

void gameInfo() {
    posX = WIDTH / 2;
    posY = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void moveFruit() {
    if (fruitX==posX && fruitY == posY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

int j = 20;

void draw() {
   // system("cls");      causes flickering
    clearScreen();
    for (int i = 0; i <= WIDTH; i++) {    // prints top of map
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {

        if (i==fruitY) {
            cout << "*" << "F" << setw(39) << "*" << endl;             // prints fruit
        }
        else if (i == posY) {
            cout << "*" << setw(posX) << "O" << setw(WIDTH-posX) << "*" << endl; // prints head
        }
    /*    else if (i==height-1) {                       // prints bottom of map
                for (int i = 0; i <= width; i ++){
                    cout << "*";
                }
        } */
        else {
            cout << "*" << setw(40) << "*" << endl;  // prints the sides of the map

        }
    }
    for (int i = 0; i <= WIDTH; i++) {
        cout << "*";
    }
    cout << "\nUse 'W' 'A' 'S' 'D' to move" << endl;

}

int main()
{
    gameInfo();

    while (gameOver!=true) {
        draw();
        getInput();
        moveSnake();
        moveFruit();
    }

    system("pause");
    return 0;
}
