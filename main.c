#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int Player;
Player you, computer;

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
    computer = rand()%4;
    if(computer == 0)
    {
        goto generate_again;   
    }

    you = menu();
}

void game_name()
{
    printf("***ROCK-PAPER-SCISSOR***\n");
}

int main()
{
    game_name();
    setup();
    return 0;
}