#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    long credit;
    int ccount = 0;
    int ccount2 = 0;
    int ccount3 = 0;
    long checksum;
    long checksum2;
    long creditcard;
    int digits = 0;
    int digits2 = 0;

    //prompt user for credit card number
    do
    {
    credit = get_long("Credit card number?: ");
    }
    while (credit < 0);

    checksum = credit;
    checksum2 = credit;
    creditcard = credit;

    //counting how many digits there are
    while (credit != 0)
    {
        credit = credit / 10;
        ccount ++;
        ccount2 ++;
        ccount3 ++;
    }
    ccount = ccount / 2;
    int x;
    int y;
    int z;
    //The sum of every other digit starting from the second last digit moving left multiplied by 2
    while (ccount != 0)
    {
        x = 2 * ((checksum % 100) / 10);
        if (x >= 10) 
        {
            y = x % 10;
            z = (x % 100) / 10;
            x = 0;
        }
        digits = digits + x + y + z;
        checksum = checksum / 100;
        y = 0;
        z = 0;
        ccount --;
    }
    
    //The sum of the remaining digits
    while (ccount2 != 0)
    {
        digits2 = digits2 + (checksum2 % 10);
        checksum2 = checksum2 / 100;
        ccount2 --;
    }
    
    //The sum of both sums
    int sum = digits + digits2;

    int mcard = creditcard / 100000000000000;
    int amex = creditcard / 10000000000000;
    long visad;
    
    if (ccount3 == 13)
    {
        visad = 10000000000;
    }
    else if (ccount3 == 16)
    {
        visad = 10000000000000;
    }
    else
    {
        visad = 1;
    }
    int visa = creditcard / visad;
    
    //Mastercard, Amex, Visa or Invalid checker
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (ccount3 == 16 && (mcard == 51 || mcard == 52 || mcard == 53 || mcard == 54 || mcard == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (ccount3 == 15 && (amex = 34 || amex == 37))
    {
        printf("AMEX\n");
    }
    else if ((ccount == 13 || ccount == 16) && visa == 4)
    {
        printf("VISA\n");
    }
    
}
