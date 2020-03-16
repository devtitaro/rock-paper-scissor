/* 
 * File:   game.c
 * Author: titaro
 *
 */


// THIS IS A ROCK PAPER SCISSOR GAME

// Lets include the required header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Lets make some definitions
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WINS 1
#define PLAYER2_WINS 2
#define DRAW 0

// Lets prepare some prototypes
int permutations(int, int);
char roundResult(int, int);
int getInput();
void choices(int);

// Lets build the game functions
int permutations(int player1, int player2)
{
    if(player1 == ROCK && player2 == PAPER)
    {
        return PLAYER2_WINS;
    }
    else if(player1 == ROCK && player2 == SCISSOR)
    {
        return PLAYER1_WINS;
    }
    else if(player1 == PAPER && player2 == SCISSOR)
    {
        return PLAYER2_WINS;
    }
    else if(player2 == ROCK && player1 == SCISSOR)
    {
        return PLAYER2_WINS;
    }
    else if(player2 == PAPER && player1 == SCISSOR)
    {
        return PLAYER2_WINS;
    }
    else if(player2 == ROCK && player1 == PAPER)
    {
        return PLAYER1_WINS;
    }
    else
    {
        return DRAW;
    }
    
}

char roundResult(int a, int b)
{
    int n = permutations(a, b);
    switch(n)
    {
        case PLAYER1_WINS:
            return printf("Player wins the round.\n");
            break;
        case PLAYER2_WINS:
            return printf("Computer wins the round.\n");
            break;
        case DRAW:
            return printf("This round was a draw between player and computer.\n");
    }
}

void choices(int c)
{
    switch(c)
    {
        case PAPER:
            printf("Paper.\n");
            break;
        case ROCK:
            printf("Rock.\n");
            break;
        case SCISSOR:
            printf("Scissor.\n");
            break;
    }
}

int getInput()
{
    int input;
    
    do
    {
        printf("\nInstructions below: \n");
        printf("1 - Rock\n");
        printf("2 - Paper\n");
        printf("3 - Scissor\n");
        printf("Please select a number (1,2,3): ");
        scanf("%d", &input);
        if(!(input >= 1 && input <= 3))
        {
            printf("You choose the wrong input, only choose numbers from (1 - 3).");
        }
    } while(!(input >= 1 && input <= 3));
    
    return input;
}

int main()
{
    int player, computer;
    int player_score, computer_score, round;
    
    player_score = 0;
    computer_score = 0;
    
    int end = 0;
    round = 1;
    
    
    while(!end)
    {
        // Lets get the user choice
        player = getInput();
    
        // Lets get the computer choice
        int t;
        t = time(NULL);
        srand(t);
        computer = (rand() % 3) + 1;
        
        if(permutations(player, computer) == PLAYER1_WINS)
        {
            player_score++;
        }
        else if(permutations(player, computer) == PLAYER2_WINS)
        {
            computer_score++;
        }
        else
        {
            player_score++;
            computer_score++;
        }
        
        if(player != 0 && computer != 0)
        {
            printf("\n");
            printf("---------------------------------------------------\n");
            printf("Player Choose: ");
            choices(player);
            printf("Computer Choose: ");
            choices(computer);
            printf("\n");
            roundResult(player, computer);
            printf("---------------------------------------------------\n");
        }
        
        printf("Round(%d) scores:\n\n", round);
        printf("Player Score: %d\n", player_score);
        printf("Computer Score: %d\n", computer_score);
        printf("---------------------------------------------------\n");
        printf("\n");
        round++;
        
        
        printf("Press any number to continue and 0 to end game: ");
        int pick;
        scanf("%d", &pick);
        if(pick == 0)
        {
            end = 1;
        }
    }
    
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    
    if(player_score > computer_score)
    {
        printf("Final Result: Player wins the game with %d points.\n", player_score);
    }
    else if(computer_score > player_score)
    {
        printf("Final Result: Computer wins the game with %d points.\n", computer_score);
    }
    else
    {
        printf("Final Result: Player - (%d) and computer - (%d) ended the game in a draw .\n", player_score, computer_score);
    }
    
    printf("-------------------------------------------------------------------\n");
    
    return (EXIT_SUCCESS);
}
