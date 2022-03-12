#include <stdio.h>
#include <conio.h>

char position[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void menu();
int startgame();
void setup();
void help();
int checkwin();

void menu()
{
    int choice;
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\a----------Menu----------\n\n\n");
    printf("\t\t\t\t\t\t\t 1. Start Game\n");
    printf("\t\t\t\t\t\t\t 2. Help\n");
    printf("\t\t\t\t\t\t\t 3. Exit\n");
    printf("\t\t\t\t\t\t\t Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        startgame();
        break;
    case 2:
        system("cls");
        help();
        break;
    case 3:
        system("cls");
        break;
    default:
        system("cls");
        printf("\n\n\n\t\t\t\t\t\t\t\a You made a wrong choice,Enter a right number!\n\n");
        menu();
    }
}

void help()
{
    int cl;
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t\t\a----------Instruction----------\n\n");
    printf("\n\t1: A 3*3 board shows on the screen.");
    printf("\n\t2: Then start play.");
    printf("\n\t3: 1st playerput his symbol in any box of the board which he want.");
    printf("\n\t4: Then player 2 will put his symbol any box of the board.");
    printf("\n\t5: After putting symbols in the box , if player 1 put his symbol 3 in a row/column/slop wise, player 1 will win.");
    printf("\n\t6: Either player 2 putting his symbol 3 in a row/column/slop wise, player 2 will win.");
    printf("\n\t7: When no one put their symbol 3 ina row/column/slop wise. the game will be drawn.\n\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\aDo you want to play a game now?\n\n\n");
    printf("\t\t\t\t\t\t\t 1. Yes\n");
    printf("\t\t\t\t\t\t\t 2. No\n");
    printf("\t\t\t\t\t\t\t Enter your choice : ");
    scanf("%d", &cl);

    switch (cl)
    {
    case 1:
        startgame();
        break;
    case 2:
        system("cls");
        break;
    default:
        system("cls");
        printf("\n\n\n\t\t\t\t\t\t\t\a You made a wrong choice,Enter a right number!\n\n");
        help();
    }
}
int startgame()
{
    int player = 1, box, i;
    char mark;

    do
    {
        setup();
        player = (player % 2) ? 1 : 2;

        printf("\n\n\t\t\t\t\t\tPlayer %d, enter box number:  ", player);
        scanf("%d", &box);

        mark = (player == 1) ? 'X' : 'O';

        if (box == 1 && position[1] == '1')
            position[1] = mark;

        else if (box == 2 && position[2] == '2')
            position[2] = mark;

        else if (box == 3 && position[3] == '3')
            position[3] = mark;

        else if (box == 4 && position[4] == '4')
            position[4] = mark;

        else if (box == 5 && position[5] == '5')
            position[5] = mark;

        else if (box == 6 && position[6] == '6')
            position[6] = mark;

        else if (box == 7 && position[7] == '7')
            position[7] = mark;

        else if (box == 8 && position[8] == '8')
            position[8] = mark;

        else if (box == 9 && position[9] == '9')
            position[9] = mark;

        else
        {
            printf("\n\n\t\t\t\t\t\t\aInvalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    } while (i == -1);

    setup();

    if (i == 1)
        printf("\n\n\t\t\t\t\t\t===>\aPlayer %d win ", --player);
    else
    {
        printf("\n\n\t\t\t\t\t\t\aGame draw,Play another Game!");
    }
    printf("\n\n\t\t\t\t\t\t Go to Menu, Press Enter");
    getch();
    system("cls");
    menu();

    return 0;
}

void setup()
{
    int j = checkwin();
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t*****Tic Tac Toe*****\n\n\n");
    printf("\t\t\t\t\t\tPlayer 1 (symbol:'X')  -  Player 2 (symbol:'O')\n\n\n");

    // // if (j == 1 || j == 0)
    // {
    //     char position[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    //     printf("\t\t\t\t\t\t\t     |     |     \n");
    //     printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[1], position[2], position[3]);
    //     printf("\t\t\t\t\t\t\t_____|_____|_____\n");
    //     printf("\t\t\t\t\t\t\t     |     |     \n");
    //     printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[4], position[5], position[6]);
    //     printf("\t\t\t\t\t\t\t_____|_____|_____\n");
    //     printf("\t\t\t\t\t\t\t     |     |     \n");
    //     printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[7], position[8], position[9]);
    //     printf("\t\t\t\t\t\t\t     |     |     \n\n");
    // }
    // else
    {
        printf("\t\t\t\t\t\t\t     |     |     \n");
        printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[1], position[2], position[3]);
        printf("\t\t\t\t\t\t\t_____|_____|_____\n");
        printf("\t\t\t\t\t\t\t     |     |     \n");
        printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[4], position[5], position[6]);
        printf("\t\t\t\t\t\t\t_____|_____|_____\n");
        printf("\t\t\t\t\t\t\t     |     |     \n");
        printf("\t\t\t\t\t\t\t  %c  |  %c  |  %c \n", position[7], position[8], position[9]);
        printf("\t\t\t\t\t\t\t     |     |     \n\n");
    }
}

/*********************************************
FUNCTION TO RETURN GAME STATUS
1 = GAME IS OVER WITH RESULT
-1 = GAME IS IN PROGRESS
O = GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (position[1] == position[2] && position[2] == position[3])
        return 1;

    else if (position[4] == position[5] && position[5] == position[6])
        return 1;

    else if (position[7] == position[8] && position[8] == position[9])
        return 1;

    else if (position[1] == position[4] && position[4] == position[7])
        return 1;

    else if (position[2] == position[5] && position[5] == position[8])
        return 1;

    else if (position[3] == position[6] && position[6] == position[9])
        return 1;

    else if (position[1] == position[5] && position[5] == position[9])
        return 1;

    else if (position[3] == position[5] && position[5] == position[7])
        return 1;

    else if (position[1] != '1' && position[2] != '2' && position[3] != '3' &&
             position[4] != '4' && position[5] != '5' && position[6] != '6' && position[7] != '7' && position[8] != '8' && position[9] != '9')

        return 0;
    else
        return -1;
}

void main()
{
    system("color 3");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t *****Tic Tac Toe*****\n\n\n");

    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t_______|_______|_______\n");
    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t_______|_______|_______\n");
    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t       |       |     \n");
    printf("\t\t\t\t\t\t\t       |       |     \n\n\n\n");

    printf("\t\t\t\t\t\t\t Project build and designed by :\n");
    
    printf("\t\t\t\t\t\t\t Sutanu Chandra \n");

    printf("\t\t\t\t\t\t\t\aPress any key to continue!\n");

    getch();
    system("cls");
    menu();
}