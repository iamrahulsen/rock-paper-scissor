#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int Player;
Player you, computer; // defining the players
int score_you=0, score_computer=0; // scores of both the players
int count=0, k = 0;

// setting up the menu for rock paper and scissor
int menu()
{
    printf("\n1. Select ROCK ");
    printf("\n2. Select PAPER ");
    printf("\n3. Select SCISSOR ");
    printf("\n4. EXIT \n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d", &ch);
    return ch;
}

// geterating random computer choice
void setup()
{
    printf("\nRound %d", count+1);
    generate_again:
    computer = (rand()%4);
    if(computer == 0)
    {
        goto generate_again;   
    }

    you = menu();
}

// result of the rounds
void logic()
{
    switch (you)
    {
        case 1:
            if(computer == 1)
            {
                printf("Game draw\n");
                printf("Both of you have choosen ROCK");
                sleep(2);                
            }
            else if(computer == 2)
            {
                printf("Computer won\n");
                printf("You = ROCK \t Computer = PAPER");
                score_computer++;
                sleep(2);
            }
            else          
            {
                printf("You won\n");
                printf("You = ROCK \t Computer = SCISSOR");
                score_you++;
                sleep(2);
            }
            count++;
            break;
        case 2:
            if(computer == 1)
            {
                printf("You won\n");
                printf("You = PAPER \t Computer = ROCK");
                score_you++;
                sleep(2);
            }
            else if(computer == 2)
            {
                printf("Game draw\n");
                printf("Both of you have choosen PAPER");
                sleep(2);
            }
            else          
            {
                printf("Computer won\n");
                printf("You = PAPER \t Computer = SCISSOR");
                score_computer++;
                sleep(2);
            }
            count++;
            break;
        case 3:
            if(computer == 1)
            {
                printf("Computer won\n");
                printf("You = SCISSOR \t Computer = ROCK");
                score_computer++;
                sleep(2);
            }
            else if(computer == 2)
            {
                printf("You won\n");
                printf("You = SCISSOR \t Computer = PAPER");
                score_you++;
                sleep(2);
            }
            else          
            {
                printf("Game draw\n");
                printf("Both of you have choosen SCISSOR");
                sleep(2);
            }
            count++;
            break;
        case 4:
            exit(0);
            break;
    
        default:
            printf("Invalid choice, please try again ");
            sleep(2);

    }
}

// game name display
void game_name()
{
    printf("***ROCK-PAPER-SCISSOR***\n");
}

// score display - final
void score_count()
{
    printf("\nFinal Score is: \nYou = %d \t Computer = %d\n", score_you, score_computer);
    if(score_computer > score_you)
    {
        printf("\n Sorry Computer won!\n");
    }
    else if(score_computer < score_you)
    {
        printf("\n Congrats, You won!\n");
    }
    else
    {
        printf("It's a draw... try again");
    }
    
}

// driver program
int main()
{
    again:
    system("cls");
    score_you = 0;
    score_computer= 0;
    count = 0;
    printf("Enter the number of round you want to play: ");
    scanf("%d",&k);
    while(count != k)
    {
        system("cls");
        game_name();
        setup();
        logic();
    }
    system("cls");
    game_name();
    score_count();
    char ch;
    fflush(stdin);
    printf("\nDo you want to play again? Press y to continue and any other key to exit: ");
    scanf("%c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
        goto again;
    }
    getch();
    return 0;
}