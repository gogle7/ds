#include<stdio.h>
#include<stdlib.h>

void insert_begin();
void insert_end();
void insert_pos();
void display();

struct node
{
        int id;
        char name[20];
        int sem;
        struct node *next;
};
struct node *start=NULL;
main()
{
        int choice;
        while(1){
                printf("\n 1.Insert at the beginning    \n");
                printf("\n 2.Insert at the end  \n");
                printf("\n 3.Insert at specified position       \n");
                printf("\n 4.Display     \n");
                printf("\n 5.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        insert_begin();
                                        break;
                        case 2:
                                        insert_end();
                                        break;
                        case 3:
                                        insert_pos();
                                        break;
                        case 4:
                                        display();
                                        break;
                        case 5:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
}

void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the ID, name and semester:\t" );
        scanf("%d %s %d",&temp->id,temp->name,&temp->sem);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}

void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the ID, name and semester:\t" );
        scanf("%d %s %d",&temp->id,temp->name,&temp->sem);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}

void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the ID, name and semester:\t");
        scanf("%d %s %d",&temp->id,temp->name,&temp->sem);
        temp->next=NULL;
        if(pos==1)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-2;i++)
                {
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d %s %d\t\t",ptr->id,ptr->name,ptr->sem);
                        ptr=ptr->next ;
                }
        }
}
