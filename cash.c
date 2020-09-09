#include <stdio.h>
#include <cs50.h>
#include <math.h>

void coinsowed(float);

int main(void)
{
    
    float dollars;
    
    //Prompt user for dollars
    do
    {
        dollars = get_float("Coins owed?: ");
    }
    while (dollars < 0);
    
    coinsowed(dollars);
}

void coinsowed(float dollars)
{
    
    int coins = 0;
    
    //Turn dollars into cents
    int cents = round(dollars * 100);
    
    //calculates how many coins are needed. For each coin added it takes away the required cents used
    while (cents > 0)
    {
        //quarters
        if (cents >= 25)
        {
            coins ++;
            cents = cents - 25;
        }
        //dimes
        else if (cents >= 10)
        {
            coins ++;
            cents = cents - 10;
        }
        //nickels
        else if (cents >= 5)
        {
            coins ++;
            cents = cents - 5;
        }
        //pennies
        else
        {
            coins ++;
            cents = cents - 1;
        }
    }
    
    printf("%i \n", coins);
}