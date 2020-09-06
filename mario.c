#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{

    int height;

    //Ask the user for input, if not between 1 and 8 then ask again until it is
    do
    {
        height = get_int("Height? (1-8): ");
    }
    while (height < 1 || height > 8);
    
    pyramid(height);

}

void pyramid(int height)
{
    //nested for loop prints the dots, then the hash, then prints the line break
    //Line break
    for (int i = 0; i < height; i++)
    {   
        //space
        for (int s = height - 1; s > i; s--)
        {
            printf(" "); 
        }
        //Hash
        for (int n = 0; n <= i; n++)
        {   
            printf("#");
        }
        printf("\n");
    }
}