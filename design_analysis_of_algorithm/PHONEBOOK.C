#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 100

struct Contact {
    char name[30];
    char phone[15];
};

void sort(struct Contact c[], int n)
{
    int i, j;
    struct Contact temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(strcmp(c[j].name, c[j+1].name) > 0)
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
}

int load(struct Contact c[])
{
    FILE *fp;
    int n = 0;

    fp = fopen("phone.txt", "r");

    if(fp == NULL)
        return 0;

    while(fscanf(fp, "%s %s", c[n].name, c[n].phone) != EOF)
        n++;

    fclose(fp);
    return n;
}

void save(struct Contact c[], int n)
{
    FILE *fp;
    int i;

    fp = fopen("phone.txt", "w");

    for(i = 0; i < n; i++)
        fprintf(fp, "%s %s\n", c[i].name, c[i].phone);

    fclose(fp);
}

void addContact()
{
    struct Contact c[SIZE];
    int n = load(c);

    printf("Enter name: ");
    scanf("%s", c[n].name);

    printf("Enter phone: ");
    scanf("%s", c[n].phone);

    n++;

    sort(c, n);
    save(c, n);

    printf("Contact Added");
}

void display()
{
    struct Contact c[SIZE];
    int n = load(c);
    int i;

    printf("\nContacts:\n");

    for(i = 0; i < n; i++)
        printf("%s - %s\n", c[i].name, c[i].phone);
}

void search()
{
    struct Contact c[SIZE];
    int n = load(c);
    int i;
    char name[30];

    printf("Enter name to search: ");
    scanf("%s", name);

    for(i = 0; i < n; i++)
    {
        if(strcmp(c[i].name, name) == 0)
        {
            printf("Found: %s - %s", c[i].name, c[i].phone);
            return;
        }
    }

    printf("Not Found");
}

void update()
{
    struct Contact c[SIZE];
    int n = load(c);
    int i;
    char name[30];

    printf("Enter name to update: ");
    scanf("%s", name);

    for(i = 0; i < n; i++)
    {
        if(strcmp(c[i].name, name) == 0)
        {
            printf("Enter new phone: ");
            scanf("%s", c[i].phone);
            save(c, n);
            printf("Updated");
            return;
        }
    }

    printf("Not Found");
}

void deleteContact()
{
    struct Contact c[SIZE];
    int n = load(c);
    int i, j;
    char name[30];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for(i = 0; i < n; i++)
    {
        if(strcmp(c[i].name, name) == 0)
        {
            for(j = i; j < n-1; j++)
                c[j] = c[j+1];

            n--;
            save(c, n);
            printf("Deleted");
            return;
        }
    }

    printf("Not Found");
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n1.Add\n2.Update\n3.Delete\n4.Search\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addContact(); break;
            case 2: update(); break;
            case 3: deleteContact(); break;
            case 4: search(); break;
            case 5: display(); break;
        }

    } while(choice != 6);

    getch();
}