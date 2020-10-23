#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int coleman(string parag);

int main(void)
{   
    //Prompting the user for text
    string parag = get_string("Text: ");
    
    //Printing the grade number
    int grade = coleman(parag);
    if (grade >= 1 && grade <= 15)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

//Function created to automatically apply Coleman-Liau's algorithm to inputted text
int coleman(string parag)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int x = 0;
    int y = 0;
    
    //Parsing through the inputted text
    for (int i = 0, n = strlen(parag); i < n; i++)
    {   
        //Counting the letters
        if ((parag[i] >= 'a' && parag[i] <= 'z') || (parag[i] >= 'A' && parag[i] <= 'Z'))
        {
            letters++;
        }
        
        //Counting the words
        if (parag[i] != ' ')
        {
            x = 1;
        }
        else
        {
            y = 1;
        }
        if (x == 1 && y == 1)
        {
            words++;
            x = 0;
            y = 0;
        }
        else if (i == (n - 1))
        {
            words++;
            x = 0;
            y = 0;
        }
        
        //Counting the sentences
        if (parag[i] == '.' || parag[i] == '!' || parag[i] == '?')
        {
            sentences++;
        }
    }
    
    //Coleman-Liau's algorithm
    float l = (float) letters / (float) words * 100;
    float s = (float) sentences / (float) words * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    
    return grade;
}