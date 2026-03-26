#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
const int HEIGHT = 12;
const int WIDTH = 25;

char maze[HEIGHT][WIDTH + 1] =
    {
        "########################",
        "#K      #        E    X#",
        "# ####  #   #######    #",
        "#      L#              #",
        "#  #######     ######  #",
        "#        #             #",
        "#   G    #      E      #",
        "#        #######       #",
        "#   L                 ##",
        "#        K             #",
        "#                     ##",
        "########################"};
int playerX1 = 1;
int playerY1 = 1;
int enemyX1 = 18;
int enemyY1 = 1;
int enemyX2 = 16;
int enemyY2 = 6;
class player
{
public:
    int health = 100;
    bool hasgun = false;
    bool haskey = false;
    bool gamerunning = true;
    void drawmaze()
    {
        system("cls"); // It clears the console screen before drawing the next frame of the game.Basically it ensures that the console is refreshed and only the current state of the maze is displayed without any leftover characters from previous frames.
        for (int i = 0; i < HEIGHT; i++)
        {
            cout << maze[i] << endl; // originally, the code was using nested loops to go through each cell of the maze and print the corresponding character based on its content. However, this approach can be simplified by directly printing each row of the maze as a string. Since each row is already stored as a null-terminated string in the 2D array, we can simply print it using cout without needing to check each cell individually. This makes the code cleaner and more efficient while achieving the same result.

            // Go through each row of the maze
            // for (int j = 0; j < WIDTH; j++)
            // { // Go through each column of the maze
            //     char cell = maze[i][j];
            //     if (cell == '#')
            //     {

            //         cout << "▓▓";
            //     }
            //     else if (cell == 'K')
            //     {
            //         cout << "🗝";
            //     }

            //     else if (cell == 'E')
            //     {
            //         cout << "👹";
            //     }
            //     else if (cell == 'L')
            //     {
            //         cout << "🌋";
            //         ;
            //     }
            //     else if (cell == 'G')
            //     {
            //         cout << "🔫";
            //     }
            //     else
            //         cout << "  ";
            // }
            // cout << endl;
        }
    }
    void declarations()
    {
        cout << "Health: " << health << endl;
        cout << " Gun: " << (hasgun ? "Yes" : "No") << endl;
        cout << " key: " << (haskey ? "Yes" : "No") << endl;
        cout << "Controls: W (Up), A (Left), S (Down), D (Right), Q (Quit) | F = Shoot" << endl;
    }
    void movePlayer(int newX, int newY)
    {
        char next = maze[newY][newX];
        if (next == '#')
        {
            cout << "you cannot move there, it's a wall!" << endl;
        }
        if (next == 'L')
        {
            cout << "you found a lava! health decreased by 20!" << endl;
            health -= 20;
        }
        if (next == 'G')
        {
            cout << "you found a gun! you can shoot enenmies now!" << endl;
            hasgun = true;
            Sleep(700);//this function is used to pause the execution of the program for a specified amount of time in milliseconds.In this case, it is used to create a brief pause after the player finds a gun, allowing them to read the message before the game continues.
        }
        if (next == 'K')
        {
            cout << "you found a key! you can open the exit now!" << endl;
            haskey = true;
            Sleep(700);
        }
        if (next == 'X')
        {
            if (haskey)
            {
                cout << "you opened the exit and won the game congratulations" << endl;
                gamerunning = false;
                Sleep(700);
                return;
            }
            else
            {
                cout << "you need a key to open a exit!" << endl;
                Sleep(700);
                return;
            }
            maze[playerY1][playerX1] = ' ';
            playerX1 = newX;
            playerY1 = newY;
            maze[playerY1][playerX1] = 'p';
        }
    }
    void moveEnemy()
    {
        maze[enemyY1][enemyX1] = ' ';
        enemyX1--;
        if (enemyX1 < 10)
        {
            enemyX1 = 18;
        }
        if (playerX1 == enemyX1 && playerY1 == enemyY1)
        {
            cout << "you got caught by an enemy! health decreased by 10!" << endl;
            health -= 10;
            Sleep(700);
        }
        maze[enemyY1][enemyX1] = 'E';

        maze[enemyY2][enemyX2] = ' ';
        enemyX2++;
        if (enemyX2 > 20)
        {
            enemyX2 = 16;
        }
        if (playerX1 = enemyX2 && playerY1 == enemyY2)
        {
            cout << "you got the other enemy! health decreased by 10!" << endl;
            health -= 10;
            Sleep(700);
        }
        maze[enemyY2][enemyX2] = 'E';
    }
    void shoot()
    {
        if (!hasgun)
        {
            cout << "you dont have a gun to shoot!" << endl;
            Sleep(700);
            return;
        }
        int shootX = playerX1 + 1;
        int shootY = playerY1;
        while (maze[shootY][shootX] != '#')
        {
            if (maze[shootY][shootX] == 'E')
            {
                cout << "you shot an enemy!" << endl;
                Sleep(700);
                return;
            }
            maze[shootY][shootX] = '*';
            drawmaze();
            Sleep(500);
            maze[shootY][shootX] = ' ';
            shootX++;
        }
    }
};

int main()
{
    maze[playerY1][playerX1] = 'p';
    player kade;
    while (kade.gamerunning && kade.health > 0)
    {
        kade.drawmaze();
        kade.declarations();
        if (_kbhit()) // It checks if any key on the keyboard has been pressed.we use this instead of cin>>move because we want to capture the key press immediately without waiting for the user to press Enter.
        {
            char move = _getch(); // It captures the key press and stores it in the variable move.
            if (move == 'w' || move == 'W')
            {
                kade.movePlayer(playerX1, playerY1 - 1);
            }
            else if (move == 'a' || move == 'A')
            {
                kade.movePlayer(playerX1 - 1, playerY1);
            }
            else if (move == 's' || move == 'S')
            {
                kade.movePlayer(playerX1, playerY1 + 1);
            }
            else if (move == 'd' || move == 'D')
            {
                kade.movePlayer(playerX1 + 1, playerY1);
            }
            else if (move == 'f' || move == 'F')
            {
                kade.shoot();
            }
            else if (move == 'q' || move == 'Q')
            {
                cout << "you quit the game!" << endl;
                kade.gamerunning = false;
            }
        }
        kade.moveEnemy();
        if (kade.health <= 0)
        {
            cout << "you died! game over!" << endl;
            kade.gamerunning = false;
            break;
        }
        Sleep(700);
    }
    return 0;
}