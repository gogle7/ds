#include <stdio.h>
 #define MAX 5
int queue[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("1.Insert token number of patient into the queue \n");
        printf("2.Remove token number of patient from queue \n");
        printf("3.Display the token numbers of patients in the queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:             insert();             break;
            case 2:             delete();             break;
            case 3:            display();            break;
            case 4:            exit(1);
            default:            printf("Wrong choice \n");
        }
    }
}

insert()
{
    int e;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)

        front = 0;
        printf("Insert the token number of the new patient : ");
        scanf("%d", &e);
        rear = rear + 1;
        queue[rear] = e;
    }
}

delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Token number of patient deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Token numbers of patients in the Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
