#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int current_amount, trade_input, trade_times;
    int initial_amount;
    int initial_trade_input;
    int continuous_profit = 0;
    int continuous_loss = 0;
    int total_profit = 0;
    srand(time(0));

    printf("Enter current amount: ");
    scanf("%d", &current_amount);
    initial_amount = current_amount;
    
    printf("Enter trade input amount: ");
    scanf("%d", &trade_input);
    initial_trade_input = trade_input;
    
    printf("Enter number of trades you want to make: ");
    scanf("%d", &trade_times);

    for(int i = 0; i < trade_times; i++){
        if(continuous_loss >= 10){
            printf("Stopping trades due to 10 continuous losses.\n");
            break;
        }

        if(current_amount < trade_input){
            printf("Insufficient balance to continue trading.\n");
            break;
        }

        int profit_or_loss = rand() % 2;
        
        if(profit_or_loss == 1 && continuous_profit >= 4){
            profit_or_loss = 0; 
        }
        
        if(profit_or_loss == 1){
            current_amount += trade_input;
            total_profit += trade_input;
            continuous_profit++; 
            printf("Trade %d: Profit! Current amount: %d\n", i+1, current_amount);
            trade_input = initial_trade_input;
            continuous_loss = 0;
        } else {
            current_amount -= trade_input;
            total_profit -= trade_input;
            printf("Trade %d: Loss! Current amount: %d\n", i+1, current_amount);
            trade_input *= 2;
            continuous_loss++;
            continuous_profit = 0;
        }
    }

    printf("\n=== Trading Summary ===\n");
    printf("Initial Balance: %d\n", initial_amount);
    printf("Final Balance: %d\n", current_amount);
    printf("Total Profit/Loss: %+d\n", total_profit);
    printf("Net Change: %+d\n", current_amount - initial_amount);

    return 0;
}