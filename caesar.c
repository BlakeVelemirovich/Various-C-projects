#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checker(int argc, string argv[]);
string cipher(int key);

int main(int argc, string argv[])
{   
    // Checks for correct usage, if not end the program with an error message
    int key = checker(argc, argv);
    if (key == -1)
    {
        return 1;
    }
    
    // Gives the cipher function the key from the checker function if usage is correct
    cipher(key);
}    

// Checks for correct usage, and obtains the encryption key
int checker(int argc, string argv[])
{
    // Needs a single command line arguement 
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return -1;
    }
    
    // Iterating through the command line arguement to make sure they're alphanumeric
    int n = strlen(argv[1]);
    
    for (int i = 0; i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return -1;
        }

    }
    
    // If everything is correct, it converts the alphanumeric key into an integer from a string
    int key = atoi(argv[1]);
    return key;
}

// The function that handles the encryption
string cipher(int key)
{
    // Prompt user for plaintext
    string pltext = get_string("plaintext: ");
    string citext = pltext;
    int n = strlen(pltext);
    
    // Iterating through the plaintext, rotates letters through ascii values and leaves anything else the same
    for (int i = 0; i < n; i++)
    {   
        // Handles uppercase letters
        if (isupper(pltext[i]))
        {   
            for (int m = 0; m < key; m++)
            {
                citext[i]++;
                // If the key roates the letters past the ascii value of Z, then we reset back to A
                if (citext[i] > 'Z')
                {
                    citext[i] = 65;
                }
            }
        }
        // Handles lowercase letters
        else if (islower(pltext[i]))
        {
            for (int ii = 0; ii < key; ii++)
            {
                citext[i]++;
                // If the key roates the letters past the ascii value of z, then we reset back to a
                if (citext[i] > 'z')
                {
                    citext[i] = 97;
                }
            }
        }
        
    
    }
    
    printf("ciphertext: %s\n", citext);
    return citext;
}
