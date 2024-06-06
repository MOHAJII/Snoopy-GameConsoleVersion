#include "base.h"

void setup()
{

    // pour cacher le curseur
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    gameOver = FALSE;
    win = FALSE;
    nbrCoins = 4;
    startTime = clock();

    player.position.x = COLONNE / 2 + 1;
    player.position.y = LIGNE / 2 + 1;

    ball.position.x = COLONNE - 2;
    ball.position.y = LIGNE - 2;

    ball.direction.x = -1;
    ball.direction.y = -1;

    for (int i = 0; i < LIGNE + 2; i++)
    {
        for (int j = 0; j < COLONNE + 2; j++)
        {
            if (i == 0 || i == LIGNE + 1 || j == 0 || j == COLONNE + 1)
            {
                matrix[i][j] = BORDER;
            }
            else
            {
                matrix[i][j] = EMPTY;
            }
        }
    }

    matrix[player.position.y][player.position.x] = PLAYER;
    matrix[ball.position.y][ball.position.x] = BALL;

    matrix[1][1] = COIN;
    matrix[1][21] = COIN;
    matrix[10][1] = COIN;
    matrix[10][21] = COIN;
}

// function pour dessiner l matrice du bordure
void drawGame()
{
    system("cls");

    for (int i = 0; i < LIGNE + 2; i++)
    {
        for (int j = 0; j < COLONNE + 2; j++)
        {
            if (matrix[i][j] == PLAYER)
            {
                setConsoleColor(10); // Green color for the player
            }
            else if (matrix[i][j] == BALL)
            {
                setConsoleColor(12);
            }
            else if (matrix[i][j] == MOVABLE_BLOC)
            {
                setConsoleColor(7);
            }
            else if (matrix[i][j] == TELEPORT_POINT)
            {
                setConsoleColor(7);
            }
            else if (matrix[i][j] == COIN)
            {
                setConsoleColor(6);
            }
            else
            {
                setConsoleColor(7); // Default color for other characters
            }
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    levelLabel(label);
    printf("\n%d coin(s) reamining ", nbrCoins);
    printf("\nIn %d s ", timer);
}

void levelLabel(char *label)
{
    printf("\n%s ", label);
}

void updatePlayer()
{
    // Clear the player's current position
    matrix[player.position.y][player.position.x] = EMPTY;

    int nextX = player.position.x;
    int nextY = player.position.y;

    if (GetAsyncKeyState('A') & 0x8000)
    {
        if (player.position.x > 1)
        {
            nextX = player.position.x - 1;
        }
    }
    if (GetAsyncKeyState('D') & 0x8000)
    {
        if (player.position.x < COLONNE)
        {
            nextX = player.position.x + 1;
        }
    }
    if (GetAsyncKeyState('W') & 0x8000)
    {
        if (player.position.y > 1)
        {
            nextY = player.position.y - 1;
        }
    }
    if (GetAsyncKeyState('S') & 0x8000)
    {
        if (player.position.y < LIGNE)
        {
            nextY = player.position.y + 1;
        }
    }
    if (GetAsyncKeyState('P') & 0x8000)
    {
        pausegame(timer);
    }

    // Check if the next position contains an obstacle
    if (matrix[nextY][nextX] != OBSTACLE)
    {

        if (matrix[nextY][nextX] == MOVABLE_BLOC)
        {
            // Check if the next position after the movable block is empty
            int nextBlockX = nextX + (nextX - player.position.x);
            int nextBlockY = nextY + (nextY - player.position.y);

            if (matrix[nextBlockY][nextBlockX] == EMPTY)
            {
                // Move the movable block
                moveBlock(nextX, nextY, nextBlockX, nextBlockY);
            }
        }

        if (matrix[nextY][nextX] == TELEPORT_POINT)
        {
            teleport(&nextX, &nextY);
        }

        // If not an obstacle, update the player's position
        player.position.x = nextX;
        player.position.y = nextY;

        // Check if the player collected a coin
        checkCoins(player.position.y, player.position.x);
        collision();
    }

    matrix[player.position.y][player.position.x] = PLAYER;
}

void pausegame(int old_time)
{
    system("cls");
    printf("game paused enter any key to resume\n");
    getchar();
    timer = old_time;
}

// fonction pour verifier les coins
void checkCoins(int x, int y)
{
    if (matrix[x][y] == COIN)
    {
        nbrCoins--;
    }
    if (nbrCoins == 0)
    {
        gameOver = TRUE;
        win = TRUE;
    }
}

// fonction pour le deplacement de la balle
void updateBall()
{
    matrix[ball.position.y][ball.position.x] = EMPTY;

    int newX = ball.position.x + ball.direction.x;
    int newY = ball.position.y + ball.direction.y;

    // verifier si il y a  une collision avec les murs
    if (newX >= COLONNE || newX <= 1)
    {
        ball.direction.x = -ball.direction.x;
    }
    if (newY >= LIGNE || newY <= 1)
    {
        ball.direction.y = -ball.direction.y;
    }

    // verifier si il y a une collision avec obstacles ou bien coin
    if (matrix[newY][newX] == OBSTACLE || matrix[newY][newX] == COIN || matrix[newY][newX] == MOVABLE_BLOC)
    {
        // changer la direction de la ball
        ball.direction.y = -ball.direction.y;
        ball.direction.x = ball.direction.x;

        // deplacer la balle a la derniere position
        newX = ball.position.x;
        newY = ball.position.y;
    }

    // mise a jour de la position de la balle
    ball.position.x = newX;
    ball.position.y = newY;

    matrix[ball.position.y][ball.position.x] = BALL;
}

// // fonction pour verifier si la balle touche le player
void collision()
{
    if (player.position.x == ball.position.x && player.position.y == ball.position.y)
    {
        printf("\nGame Over! You were hit by the ball!\n");
        gameOver = 1;
    }
}

// fonction pour ajouter les obstacles
void addObstacle(int x, int y)
{

    if (x >= 1 && x <= COLONNE && y >= 1 && y <= LIGNE)
    {
        matrix[y][x] = OBSTACLE;
    }
    else
    {
        fprintf(stderr, "Error: Coordinates out of bounds for adding obstacle.\n");
    }
}

// fonction pour ajouter les obstacles
void addMouvableBlock(int x, int y)
{

    if (x >= 1 && x <= COLONNE && y >= 1 && y <= LIGNE)
    {
        MovableBlock block;
        block.position.x = x;
        block.position.y = y;
        block.movable = TRUE;
        matrix[y][x] = MOVABLE_BLOC;
    }
    else
    {
        fprintf(stderr, "Error: Coordinates out of bounds for adding obstacle.\n");
    }
}

void moveBlock(int fromX, int fromY, int toX, int toY)
{

    // Clear the block's current position
    matrix[fromY][fromX] = EMPTY;

    // Update the block's new position
    matrix[toY][toX] = OBSTACLE;
}

// fonction pour sauvgarder le score dans le fichier
void saveScore()
{
    FILE *file = fopen("./scoretable/ScoreTable.txt", "a");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    fprintf(file, "Username: %s Score: %d\n", username, score);

    fclose(file);
}

void displayScoreTable()
{
    FILE *file = fopen("./scoretable/ScoreTable.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    printf("\n%-20s %-10s\n", "Username", "Score");
    printf("----------------------------\n");

    char username[50];
    int score;

    while (fscanf(file, "Username: %49s Score: %d\n", username, &score) == 2)
    {
        printf("%-20s %-10d\n", username, score);
    }
    printf("\n----------------------------\n");
    fclose(file);
}

// styling
void setConsoleColor(int colorCode)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, colorCode);
}

void teleport(int *x, int *y)
{
    matrix[*y][*x] = EMPTY;

    for (int i = 0; i < LIGNE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            if (matrix[i][j] == TELEPORT_POINT && i != *x && j != *y)
            {
                *x = j;
                *y = i;
                printf("sdcdc\n");

                return;
            }
        }
    }
}

void addteleportBlock(int x, int y)
{
    if (x >= 1 && x <= COLONNE && y >= 1 && y <= LIGNE)
    {
        matrix[y][x] = TELEPORT_POINT;
    }
    else
    {
        fprintf(stderr, "Error: Coordinates out of bounds for adding obstacle.\n");
    }
}