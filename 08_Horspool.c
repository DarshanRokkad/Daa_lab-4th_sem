/*
Consider the problem of searching for genes in DNA sequences using Horspool’s
algorithm. A DNA sequence is represented by a text on the alphabet {A, C, G,
T}, and the gene or gene segment is the pattern. A gene segment of your
chromosome 10 has the pattern TCCTATTCTT . Design and develop a program
in C to locate the above pattern in the following DNA sequence by applying
Horspool’s algorithm.
TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT.
Also compute the number of comparisons using this method as compared to
linear search method
*/

#include <stdio.h>
#include <string.h>
#define MAX 500
int table[MAX];

// for construction of shift table
void shift_table(char pattern[])
{
    int pattern_len = strlen(pattern);
    for (int i = 0; i < MAX; i++)
    {
        table[i] = pattern_len;
    }
    for (int i = 0; i < pattern_len - 1; i++)
    {
        table[pattern[i]] = pattern_len - 1 - i;
    }
}

// horspool algorithm which returns the index of the first occurance of the pattern 
int horspool(char text[], char pattern[])
{
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    printf("Length of text : %d\n", text_len);
    printf("Length of pattern : %d\n", pattern_len);
    int i = pattern_len - 1;
    while (i < text_len)
    {
        int k = 0;
        while (k < pattern_len && pattern[pattern_len - 1 - k] == text[i - k])
        {
            k++;
        }
        if (k == pattern_len)
        {
            return (i - pattern_len + 1);
        }
        else
        {
            i += table[text[i]];
        }
    }
    return -1;
}

// linear pattern searching to compare with horspool
int linear_search(char text[], char pattern[])
{
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    printf("Length of text : %d\n", text_len);
    printf("Length of pattern : %d\n", pattern_len);
    if (text_len > pattern_len)
    {
        for (int i = 0; i < text_len; i++)
        {
            int j;
            for (j = 0; j < pattern_len; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == pattern_len)
            {
                return i;
            }
        }
    }
    else
    {   
        return -1;
    }
}

int main()
{
    char text[100], pattern[100];
    printf("Enter the text in which pattern is to be searched : ");
    gets(text);
    printf("Enter the pattern to be searched : ");
    gets(pattern);
    shift_table(pattern);
    int position = horspool(text, pattern);
    if (position >= 0)
    {
        printf("The desired pattern was found starting from position : %d\n", position + 1);
    }
    else
    {
        printf("The pattern was not found in given text.\n");
    }
    position = linear_search(text, pattern);
    if (position >= 0)
    {
        printf("The desired pattern was found starting from position : %d\n", position + 1);
    }
    else
    {
        printf("The pattern was not found in given text.\n");
    }

    return 0;
}

/* Sample input and output

Enter the text in which pattern is to be searched : TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT
Enter the pattern to be searched : TCCTATTCTT
Length of text : 38
Length of pattern : 10
The desired pattern was found starting from position : 29

*/