#include<stdio.h>
#include<conio.h>

#define MAX 10

void main()
{
    int buffer[MAX], size, in=0, out=0;
    int empty, full=0, mutex=1;
    int item, choice;

    clrscr();
    printf("PRODUCER CONSUMER PROBLEM USING SEMAPHORES\n");
    printf("------------------------------------------\n");

    printf("Enter buffer size (maximum %d): ", MAX);
    scanf("%d",&size);

    if(size>MAX || size<=0)
    {
        printf("\nInvalid buffer size!");
        getch();
        return;
    }

    empty=size;

    do
    {
        printf("\n1. Produce\n2. Consume\n3. Display Status\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(empty==0)
                {
                    printf("\nBuffer is FULL!");
                }
                else
                {
                    empty--;
                    mutex--;
                    printf("Enter item: ");
                    scanf("%d",&item);

                    buffer[in]=item;
                    printf("Produced: %d",item);
                    in=(in+1)%size;

                    mutex++;
                    full++;
                }
                break;

            case 2:
                if(full==0)
                {
                    printf("\nBuffer is EMPTY!");
                }
                else
                {
                    full--;
                    mutex--;

                    item=buffer[out];
                    printf("\nConsumed: %d",item);
                    out=(out+1)%size;

                    mutex++;
                    empty++;
                }
                break;

            case 3:
                printf("\nEmpty = %d",empty);
                printf("\nFull = %d",full);
                printf("\nMutex = %d",mutex);
                break;

            case 4:
                printf("\nProgram Terminated.");
                break;

            default:
                printf("\nInvalid Choice!");
        }
    }
    while(choice!=4);

    getch();
}