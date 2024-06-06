#include <stdio.h>
#include <stdlib.h>
#include "levels/levels.h"

void showMainMenu();
void tutorialLevel();
void playGame();
void showScoreTable();

int main()
{
    char choice;

    do
    {
        showMainMenu();
        scanf("%s", &choice);
        int code;

        switch (choice)
        {

        case '1':

            system("cls");
            printf("enter code 4 digits\n");
            scanf("%4d", &code);
            switch (code)
            {
            case 1111:
                level1();
                break;

            case 2222:
                level2();
                break;

            case 3333:
                level3();
                break;

            case 4444:
                level4();
                main();
                break;

            default:
                printf("invalid digits");
                Sleep(500);
                main();
                break;
            }
            break;
        case '2':
            playGame();
            break;
        case '3':
            showScoreTable();
            break;
        case '4':
            auRevoir();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            Sleep(900);
        }
    } while (choice != '4');

    return 0;
}

void showMainMenu()
{
    system("cls");
    snoopy();
    printf("Menu:\n");
    printf("\t level code                1\n");
    printf("\t Nouveau jeu               2\n");
    printf("\t voir le table du score    3\n");
    printf("\t Quitter                   4\n");
}

void tutorialLevel()
{
    char again;

    do
    {
        tutorial();

        scanf(" %c", &again);

        printf("\n Play again? (Y/N): ");
        scanf(" %c", &again);
    } while (again == 'Y' || again == 'y');

    printf("\n Start level 1? (Y/N): ");
    scanf(" %c", &again);

    if (again == 'Y' || again == 'y')
    {
        playGame();
    }
    else
    {
        main();
    }
}

void playGame()
{
    system("cls");
    level1();
    system("cls");

    if (win == TRUE)
    {
        char save;
        printf("Save your score ? (y/n)\n");
        scanf("%c", &save);
        if (save == 'y' || save == 'Y')
            saveScore();
        else
            main();
    }
    else
        main();
}

void showScoreTable()
{
    char c;

    do
    {
        system("cls");
        printf("Table du score\n");
        displayScoreTable();
        printf("\n Entrez (m) pour revenir au menu\n");
        c = getchar();
    } while (c != 'm');
}
