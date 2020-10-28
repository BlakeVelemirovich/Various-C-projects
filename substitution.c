#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Defining the alphabets in upper and lower case
const string lalphabet = "abcdefghijklmnopqrstuvwxyz";
const string ualphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int checker(int argc, string argv[]);
void cipher(string argv[]);

int main(int argc, string argv[])
{   
    // Checks to see if the key inputted is the right specifications
    if (checker(argc, argv) == -1)
    {
        return 1;
    }

    // The function that encrypts the plaintext submitted by the user
    cipher(argv);

}

// Function designed to check for correct specifications
int checker(int argc, string argv[])
{   
    // Error message if more than one command-line arguement
    if (argc != 2)
    {
        printf("Only one argument please\n");
        return -1;
    }

    // Length of the command-line arguement
    int length = strlen(argv[1]);
    
    // Iterating through the command-line arguement
    for (int i = 0; i < length; i++)
    {   
        // Error message if command-line arguement is not all letters or more than 26 letters
        if (isalpha(argv[1][i]) != 1024 || length != 26)
        {   
            printf("Please input 26 unique letters\n");
            return -1;
        }
            
        // Comparing each letter with the rest of the string to check incase of duplicity in letters
        for (int n = i + 1; n < length; n++)
        {
            if (argv[1][i] == argv[1][n])
            {   
                printf("Make sure not to input the same letter twice\n");
                return -1;
            }
        }
    }
    return 1;
}

void cipher(string argv[])
{
    
    // Prompting user for plaintext and counting the length
    string pltext = get_string("plaintext: ");
    int plength = strlen(pltext);
    string cltext = pltext;
    
    // Iterating through the plaintext
    for (int i = 0; i < plength; i++)
    {   
        // Encryption for uppercase letters. Sifts through the alphabet until a match then grabs the corresponding letter from the key.
        if (isupper(pltext[i]))
        {
            for (int n = 0; n <= 26; n++)
            {
                if (pltext[i] == ualphabet[n])
                {
                    cltext[i] = toupper(argv[1][n]);
                    break;
                }
            }
        }
        // Encryption for uppercase letters. Sifts through the alphabet until a match then grabs the corresponding letter from the key.
        if (islower(pltext[i]))
        {
            for (int n = 0; n <= 26; n++)
            {
                if (pltext[i] == lalphabet[n])
                {
                    cltext[i] = tolower(argv[1][n]);
                    break;
                }
            }
        }
    }
    
    // Printing the encrypted text
    printf("ciphertext: %s\n", cltext);
}