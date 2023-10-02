#include <stdio.h>
#include <stdlib.h>
int *queue, max, d, f = -1, r = -1;
void enqueue()
{
    printf("Enter the data: ");
    scanf("%d", &d);
    if ((f == 0 && r == max - 1) || (f == (r + 1) % max))
        printf("OVERFLOW.\n");
    else
    {
        if (f == -1)
            f = r = 0;
        else if (r == max - 1 && f != 0)
            r = 0;
        else
            r = (r + 1) % max;
        printf("Element inserted at the position: %d", r);
        queue[r] = d;
    }
}
void dequeue()
{
    if (f == -1)
        printf("UNDERFLOW.\n");
    else
    {
        if (f == r)
            f = r = -1;
        else if (f == max - 1)
            f = 0;
        else
            f = (f + 1) % max;
    }
}
void display()
{
    if (f == -1)
    {
        printf("UNDERFLOW.\n");
        return;
    }
    else if (r >= f)
    {
        for (int i = f; i <= r; i++)
            printf("%d\t", queue[i]);
    }
    else
    {
        for (int i = f; i < max; i++)
            printf("%d\t", queue[i]);
        for (int i = 0; i <= r; i++)
            printf("%d\t", queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("Enter the size of the circular queue :");
    scanf("%d", &max);
    queue = malloc(max * sizeof(int));
    do
    {
        printf("\n1. Enqueue\n 2.Dequeue\n 3.Display\n 4. exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter a valid choice");
        }
    } while (1);
    free(queue);
    return 0;
}
