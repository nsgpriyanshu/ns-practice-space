#include<stdio.h>
#include<conio.h>

void main()
{
    int mutex=1, wrt=1, readCount=0;
    int choice;

    clrscr();
    printf("READER WRITER PROBLEM USING SEMAPHORES\n");
    printf("--------------------------------------\n");

    do
    {
        printf("\n1. Start Reader");
        printf("\n2. Stop Reader");
        printf("\n3. Start Writer");
        printf("\n4. Stop Writer");
        printf("\n5. Display Status");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(wrt==0 && readCount==0)
                {
                    printf("\nWriter is writing!");
                }
                else
                {
                    mutex--;
                    readCount++;

                    if(readCount==1)
                    {
                        wrt--;
                    }

                    printf("\nReader started reading.");
                    printf("\nActive Readers: %d",readCount);
                    mutex++;
                }
                break;

            case 2:
                if(readCount==0)
                {
                    printf("\nNo Reader is reading!");
                }
                else
                {
                    mutex--;
                    readCount--;

                    printf("\nReader stopped reading.");
                    printf("\nActive Readers: %d",readCount);

                    if(readCount==0)
                    {
                        wrt++;
                    }

                    mutex++;
                }
                break;

            case 3:
                if(wrt==1 && readCount==0)
                {
                    wrt--;
                    printf("\nWriter started writing.");
                }
                else
                {
                    printf("\nWriter cannot write!");
                }
                break;

            case 4:
                if(wrt==0 && readCount==0)
                {
                    wrt++;
                    printf("\nWriter stopped writing.");
                }
                else
                {
                    printf("\nNo Writer is writing!");
                }
                break;

            case 5:
                printf("\nMutex = %d",mutex);
                printf("\nWrite Lock = %d",wrt);
                printf("\nRead Count = %d",readCount);
                break;

            case 6:
                printf("\nProgram Terminated.");
                break;

            default:
                printf("\nInvalid Choice!");
        }
    }
    while(choice!=6);

    getch();
}