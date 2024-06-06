#include "levels.h"

void level1()
{

    addObstacle(2, 5);
    addObstacle(2, 6);
    addObstacle(7, 5);
    addObstacle(10, 6);

    setup();
    label = "level 1";

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        // Update timer
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

        _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }
    if (win == TRUE)
    {

        score += timer * 1000;
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 1. with %d points\n", score);
        Sleep(3000);

        printf("\nlevel 2 loading");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        system("cls");
        level2();
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {
            system("cls");
            level1();
        }
        else
        {
            system("cls");
            return;
        }
    }
}

void level2()
{

    setup();
    label = "level 2";

    // Ajout des  obstacles
    addObstacle(13, 5);
    addObstacle(13, 6);
    addObstacle(9, 5);
    addObstacle(9, 6);
    // addObstacle(15, 3);

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

        _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }

    if (win == TRUE)
    {

        score += timer * 1000;
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 2. with %d points\n", score);
        Sleep(500);

        char save;
        printf("Save your score ? (y/n)\n");
        scanf("%c", &save);
        if (save == 'y' || save == 'Y')
            saveScore();

        else
        {

            printf("\nlevel 3 loading");
            Sleep(700);
            printf(".");
            Sleep(700);
            printf(".");
            Sleep(700);
            printf(".");
            Sleep(700);
            system("cls");
            level3();
        }
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {

            system("cls");
            Sleep(500);
            level2();
        }
        else
        {

            system("cls");
            printf("save your previous score ? ( y/N) \n");
            scanf("%c", &try);
            if (try == 'Y' || try == 'y')
                saveScore();
        }
    }
}

void level3()
{

    setup();
    label = "level 3";

    // Ajout des  obstacles
    addObstacle(13, 5);
    addObstacle(13, 6);
    addObstacle(9, 5);
    addObstacle(9, 6);
    addMouvableBlock(10, 7);
    addMouvableBlock(11, 7);
    addMouvableBlock(12, 7);
    addMouvableBlock(10, 4);
    addMouvableBlock(11, 4);
    addMouvableBlock(12, 4);

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

        _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }

    if (win == TRUE)
    {

        score += timer * 1000;
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 3. with %d points\n", score);

        char save;
        scanf("%c", &save);
        printf("Save your score ? (y/n)\n");
        scanf("%c", &save);
        if (save == 'y' || save == 'Y')
            saveScore();
        else
            level4();
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {

            system("cls");
            Sleep(500);
            level3();
        }
        else
        {

            system("cls");
            printf("save your previous score ? ( y/N) \n");
            scanf("%c", &try);
            if (try == 'Y' || try == 'y')
                saveScore();
        }
    }
}

void level4()
{

    setup();
    label = "level 4";

    // Ajout des  obstacles
    addObstacle(13, 5);
    addObstacle(13, 6);
    addObstacle(9, 5);
    addObstacle(9, 6);
    addObstacle(10, 7);
    addObstacle(11, 7);
    addObstacle(12, 7);
    addObstacle(10, 4);
    addObstacle(11, 4);
    addObstacle(12, 4);
    addteleportBlock(18, 6);
    addteleportBlock(12, 5);
    // addteleportBlock(12,4);
    // addteleportBlock(18,2);

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

        _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }

    if (win == TRUE)
    {

        score += timer * 1000;
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 3. with %d points\n", score);

        char save;
        scanf("%c", &save);
        printf("Save your score ? (y/n)\n");
        scanf("%c", &save);
        if (save == 'y' || save == 'Y')
            saveScore();
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {

            system("cls");
            Sleep(500);
            level3();
        }
        else
        {

            system("cls");
            printf("save your previous score ? ( y/N) \n");
            scanf("%c", &try);
            if (try == 'Y' || try == 'y')
                saveScore();
        }
    }
}

void tutorial()
{

    setup();
    label = "tutorial";
    while (!gameOver)
    {

        _kbhit();
        drawGame();
        // updateBall();
        Sleep(1000 / 30);
        updatePlayer();
    }

    setup();
    label = "tutorial";
    while (!gameOver)
    {

        _kbhit();
        drawGame();
        updateBall();
        Sleep(1000 / 30);
        updatePlayer();
    }
    system("cls");
    if (win == TRUE)
    {
        system("cls");
        congratulation();
        printf("\n\nYou've completed the Tutorial. ");
        Sleep(3000);
    }

    // char try;
    // system("cls");
    // printf("\nPlay again  (Y/N)\n");
    // scanf("%c", &try);
    // if (try == 'Y' || try == 'y')
    // {

    //     system("cls");
    //     Sleep(3000);
    //     tutorial();
    // }
    // else
    // {

    //     system("cls");
    // }
}
