#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    
    int height;
    
    //Ask for height to be used in the pyramid
    do
    {
        height = get_int("Height?(1-8): ");
    }
    while (height < 1 || height > 8);
    
    pyramid(height);
}

//Function builds the pyramid
void pyramid(int height)
{   
    //The loop that builds the pyramid, first loop creates new lines
    for (int i = 0; i < height; i++)
    {   
        //this loop creates spaces
        for (int s = height - 1; s > i; s--)
        {
            printf(" ");
        }
        //this loop creates the left side hashes
        for (int n = 0; n <= i; n++)
        {
            printf("#");
        }
        //creating the mandatory two spaces between the pyramid
        printf("  ");
        //this loop creates the right side hashes
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
