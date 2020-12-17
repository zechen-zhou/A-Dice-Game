/*PROGRAM: dice_A.c
 *
 * PURPOSE: function implementation
 */

#include "dice_A.h"

/**********************************************************
 * 
 * Function name: playGame()
 * Purpose: When the player is ready to play, (s)he would 
 *          use the key ENTER to roll the dice.
 *          If the user wins in his/her first roll, 
 *          congratulate the player and return with WON.
 *          If the user looses in his/her first roll, 
 *          return with LOOSE and apologize.

 * Function In parameters: N/A
 * Function Out parameters: 0
 **********************************************************/
int playGame(void){
    printf("\t\t     ROLL THE DICE [ENTER]\n");
    getchar();
    printf("-------------------------------------------------------------\n");
    printf("  ROLL NUM\tDICE #1\t    DICE #2\tTOTAL ROLL\tPOINT MATCH\n");
    printf("-------------------------------------------------------------\n");
    return 0;
}

/****************************************************************
 * 
 * Function name: rollDice()
 * Purpose: use rand( ) to randomly generate a number between 1 – 6
 *
 * Function In parameters: N/A
 * Function Out parameters: Return a random number between 1 – 6
 ***************************************************************/

int rollDice(void){
    int rollNum=1,result=-1,check,exit=0; /*result=-1
                                    check=1 Initial state
                                    check=0 The first roll is any other number -> continue rolling the dice
                                    exit=0 Keep looping */
    int firstRoll,diceFirst,diceSecond,total,pointMatch=0;
    srand(time(0));
    do{
        check = 1;
        
        diceFirst=0;
        diceSecond=0;
        
        diceFirst = (rand() % (6-1+1)) + 1 ;
        diceSecond = (rand() % (6-1+1)) + 1 ;
        total = diceFirst+diceSecond;
        if(rollNum == 1 ){
            firstRoll = diceFirst + diceSecond;
            if(firstRoll != 7 && firstRoll != 11 && firstRoll != 2 && firstRoll != 3 && firstRoll != 12){
                check = 0;
            }else if(firstRoll == 7 || firstRoll == 11){
                /*return WON;*/
                result = WON;
                exit = 1;
            }else if(firstRoll == 2 || firstRoll == 3 || firstRoll == 12 ){
                /*return LOOSE;*/
                result = LOOSE;
                exit = 1;
            }
        }
        if(total>=pointMatch){
            pointMatch = total;
            if(rollNum != 1)
                exit = 1;
        }
        printf("  \t%d\t    %d\t\t%d\t     %d\t\t     %d\n",rollNum,diceFirst,diceSecond,total,pointMatch);
        rollNum++;
    }while(((check == 1) && (total < pointMatch)) || exit == 0 || ((rollNum == 1) && (exit == 0)));
    
    if(result == -1){
        result=0;
    }

    if((rollNum-1) == 1 && result == 0){
        printf("\nCongratulation you roll %d and WON at your first try!!!\n",pointMatch);
    }else if((rollNum-1) != 1 && result == 0){
        printf("\nCongratulation you roll %d and WON\n",pointMatch);
    }else if(result == 1){
        printf("\nSorry, you roll %d and you loose!!!\n",pointMatch);
    }

    return result;
}