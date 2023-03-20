#include<stdio.h>
#include<stdlib.h>
void create(int);
void search();
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void main()
{
    int choice,item,loc;
    do
    {
        printf("\n1.create\n2.search\n3.exit");
        printf("\nEnter your choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the item\n");
            scanf("%d",&item);
            create(item);
            break;
            case 2:search();
            break;
            case 3: exit(0);
            break;
            default:printf("\nInvalid choice");
        }
    }while(choice!=3);
}
void create(int item)
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\nNode Inserted\n");
    }
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter the element you want to search: \n");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("item found at location %d",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1)
        {
            printf("Item not found\n");
        }
    }
}
