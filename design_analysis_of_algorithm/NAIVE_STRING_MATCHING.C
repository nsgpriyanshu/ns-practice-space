#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char text[100], pat[50];
    int i, j, n, m, flag;

    clrscr();

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pat);

    n = strlen(text);
    m = strlen(pat);

    for(i = 0; i <= n - m; i++)
    {
        flag = 1;
        for(j = 0; j < m; j++)
        {
            if(text[i+j] != pat[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("Pattern found at position %d\n", i);
    }

    getch();
}