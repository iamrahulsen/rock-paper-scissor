#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int Player;
Player you, computer;
int score_you=0, score_computer=0;
int count=0;

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
void setup()
{
    generate_again:
    computer = (rand()%4);
    if(computer == 0)
    {
        goto generate_again;   
    }

    you = menu();
}

void logic()
{
    switch (you)
    {
        case 1:
            if(computer == 1)
            {
                printf("Game draw\n");
                printf("Both of you have choosen ROCK");
            }
            else if(computer == 2)
            {
                printf("Computer won\n");
                printf("You = ROCK \t Computer = PAPER");
            }
            else          
            {
                printf("You won\n");
                printf("You = ROCK \t Computer = SCISSOR");
            }
            break;
        case 2:
            if(computer == 1)
            {
                printf("You won\n");
                printf("You = PAPER \t Computer = ROCK");
            }
            else if(computer == 2)
            {
                printf("Game draw\n");
                printf("Both of you have choosen PAPER");
            }
            else          
            {
                printf("Computer won\n");
                printf("You = PAPER \t Computer = SCISSOR");
            }
            break;
        case 3:
            if(computer == 1)
            {
                printf("Computer won\n");
                printf("You = SCISSOR \t Computer = ROCK");
            }
            else if(computer == 2)
            {
                printf("You won\n");
                printf("You = SCISSOR \t Computer = PAPER");
            }
            else          
            {
                printf("Game draw\n");
                printf("Both of you have choosen SCISSOR");
            }
            break;
        case 4:
            exit(0);
            break;
    
        default:
            printf("Invalid choice, please try again ");

    }
}

void game_name()
{
    printf("***ROCK-PAPER-SCISSOR***\n");
}

int main()
{
    do
    {
        game_name();
        setup();
        logic();
    } while (0);
    
    

    printf("Do you want to play again");
    return 0;
}