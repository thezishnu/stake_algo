/*We are going to create an C language algorithm for current amount and trade input is given by user.
also input should ask how many times user wants to trade. 
 if profit reset to default trade input.
 if loss double the trade input.
 but keep the stop if 10 continuous loss trade
 give profit and loss - random
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int current_amount, trade_input, trade_times;
    int continuous_loss = 0;
    srand(time(0));

    printf("Enter current amount: ");
    scanf("%d", &current_amount);
    printf("Enter trade input amount: ");
    scanf("%d", &trade_input);
    printf("Enter number of trades you want to make: ");
    scanf("%d", &trade_times);

    for(int i = 0; i < trade_times; i++){
        if(continuous_loss >= 10){
            printf("Stopping trades due to 10 continuous losses.\n");
            break;
        }

        int profit_or_loss = rand() % 2; // 0 for loss, 1 for profit
        if(profit_or_loss == 1){
            current_amount += trade_input;
            printf("Trade %d: Profit! Current amount: %d\n", i+1, current_amount);
            trade_input = trade_input; // reset to default trade input
            continuous_loss = 0; // reset continuous loss count
        } else {
            current_amount -= trade_input;
            printf("Trade %d: Loss! Current amount: %d\n", i+1, current_amount);
            trade_input *= 2; // double the trade input
            continuous_loss++;
        }
    }

    printf("Final amount after trades: %d\n", current_amount);
    return 0;
}