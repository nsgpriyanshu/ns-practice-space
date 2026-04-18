#include <stdio.h>
#include <conio.h>
#include <string.h>

#define d 256
#define q 101

void main()
{
    char text[100], pat[50];
    int i, j, n, m, t = 0, p = 0, h = 1;

    clrscr();

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pat);

    n = strlen(text);
    m = strlen(pat);

    for(i = 0; i < m-1; i++)
        h = (h * d) % q;

    for(i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(i = 0; i <= n - m; i++)
    {
        if(p == t)
        {
            for(j = 0; j < m; j++)
                if(text[i+j] != pat[j])
                    break;

            if(j == m)
                printf("Pattern found at position %d\n", i);
        }

        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i+m]) % q;
            if(t < 0) t = t + q;
        }
    }

    getch();
}