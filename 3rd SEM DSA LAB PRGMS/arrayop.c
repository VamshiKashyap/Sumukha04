#include<stdio.h>
#include<stdlib.h>
int a[10], n, i, val, pos;
void create();
void display();
void insert();
void delete();

void create()
{
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
     scanf("%d", &a[i]);
    }
}
void display()
{
    int i;
    printf("The array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
}
void insert()
{
    printf("Enter the position of element to be inserted\n");
    scanf("%d", &pos);
    printf("Enter the element to be inserted\n");
    for(i=n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=val;
    n=n+1;
}
void delete()
{
    printf("Enter the position of element to be deleted\n");
    scanf("%d", &pos);
    val=a[pos];
    for(int i=0;i<=n-1;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
    printf("The deleted element is %d\n", val);
}
int main()
{
    int choice;
    while(choice)
    {
        printf("\n\n----------MENU----------\n\n");
        printf("1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
            case 4: delete();
            break;
            case 5: exit(0);
            break;
            default:printf("Invalid Entry\n");
        }
    }
    return 0;
}