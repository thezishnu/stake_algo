#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int trade_number;
    char result[10]; // "Profit" or "Loss"
    int amount;
    int balance;
} Trade;

int main(){
    int current_amount, trade_input, trade_times;
    int initial_amount;
    int initial_trade_input;
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

    // Dynamic array to store trade history
    Trade *trade_history = (Trade*)malloc(trade_times * sizeof(Trade));
    int trade_count = 0;

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
        
        // Store trade in history
        trade_history[trade_count].trade_number = i + 1;
        trade_history[trade_count].amount = trade_input;
        
        if(profit_or_loss == 1){
            current_amount += trade_input;
            total_profit += trade_input;
            sprintf(trade_history[trade_count].result, "Profit");
            trade_history[trade_count].balance = current_amount;
            printf("Trade %d: Profit! Current amount: %d\n", i+1, current_amount);
            trade_input = initial_trade_input;
            continuous_loss = 0;
        } else {
            current_amount -= trade_input;
            total_profit -= trade_input;
            sprintf(trade_history[trade_count].result, "Loss");
            trade_history[trade_count].balance = current_amount;
            printf("Trade %d: Loss! Current amount: %d\n", i+1, current_amount);
            trade_input *= 2;
            continuous_loss++;
        }
        trade_count++;
    }

    printf("\n=== Trading Summary ===\n");
    printf("Initial Balance: %d\n", initial_amount);
    printf("Final Balance: %d\n", current_amount);
    printf("Total Profit/Loss: %+d\n", total_profit);
    printf("Net Change: %+d\n", current_amount - initial_amount);
    
    // Additional statistics using the stored data
    printf("\n=== Trade History ===\n");
    int profit_count = 0, loss_count = 0;
    int max_balance = initial_amount, min_balance = initial_amount;
    
    for(int i = 0; i < trade_count; i++){
        printf("Trade %d: %s | Amount: %d | Balance: %d\n", 
               trade_history[i].trade_number,
               trade_history[i].result,
               trade_history[i].amount,
               trade_history[i].balance);
        
        if(trade_history[i].result[0] == 'P') profit_count++;
        else loss_count++;
        
        if(trade_history[i].balance > max_balance) max_balance = trade_history[i].balance;
        if(trade_history[i].balance < min_balance) min_balance = trade_history[i].balance;
    }
    
    printf("\n=== Statistics ===\n");
    printf("Total Trades: %d\n", trade_count);
    printf("Profitable Trades: %d\n", profit_count);
    printf("Loss Trades: %d\n", loss_count);
    printf("Win Rate: %.2f%%\n", (float)profit_count / trade_count * 100);
    printf("Current Balance: %d\n", current_amount);
    printf("Max Balance Reached: %d\n", max_balance);
    printf("Min Balance Reached: %d\n", min_balance);

    free(trade_history);

    return 0;
}