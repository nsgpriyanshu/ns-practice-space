#include <stdio.h>
#include <conio.h>
#include <string.h>

void computeLPS(char pat[], int lps[], int m)
{
    int len = 0, i = 1;

    lps[0] = 0;

    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void main()
{
    char text[100], pat[50];
    int n, m, i = 0, j = 0;
    int lps[50];

    clrscr();

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pat);

    n = strlen(text);
    m = strlen(pat);

    computeLPS(pat, lps, m);

    while(i < n)
    {
        if(pat[j] == text[i])
        {
            i++; j++;
        }

        if(j == m)
        {
            printf("Pattern found at position %d\n", i-j);
            j = lps[j-1];
        }
        else if(i < n && pat[j] != text[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }

    getch();
}