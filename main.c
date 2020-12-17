/*PROGRAM:  main.c
 *
 * PURPOSE: Execute the program for Part A
 */
#include "dice_A.h"

int main(){
    char exitMenu;
    int win=0;
    int lose=0;  /*calculate the number of Games lost and won*/
    int num; /*check if the player won the game*/ 
    int first=0,second=0;
    do{
        playGame();
        num = rollDice();
        if(num == 0){
            win++;
        }else if(num == 1){
            lose++;
        }
        first += win;
        second += lose;

        printf("Another Game? [ Y / N ] ");
        scanf("%s",&exitMenu);
        printf("\n");
        if(exitMenu == 'Y' || exitMenu == 'y'){
            getchar();
        }else if(exitMenu == 'N' || exitMenu == 'n'){
            printf("You won %d games and lost %d games!\n",first,second);
        }
    }while((exitMenu == 'Y') || (exitMenu == 'y'));
    return EXIT_SUCCESS;
}