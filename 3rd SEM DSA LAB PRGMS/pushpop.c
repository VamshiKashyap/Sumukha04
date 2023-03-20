#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int s[MAX];
int top=-1;
void push (int item);
int pop();
void display();
void main()
{
    int choice, item;
    while(1)
    {
        printf("\n\n\n ~~~~~~~~~~ MENU ~~~~~~~~~ \n\n\n");
        printf("\n =>1. Push an element to stack and overflow");
        printf("\n =>2. Pop an element from stack and overflow");
        printf("\n =>3. Display");
        printf("\n =>4. Exit");
        printf("\n enter your choice");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be pushed\n");
            scanf("%d",&item);
            push(item);
            break;
            case 2: item =pop();
            if(item != -1)
            printf("Element popped is %d", item);
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default:printf("Invalid Choice\n");
            break;
        }
    }
}
void push(int item)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    s[top]=item;
}
int pop()
{
    int item;
    if( top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
}
void display()
{
    int i;
    if( top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(i=top;i>=0;i--)
    printf("|%d|\n", s[i]);
}