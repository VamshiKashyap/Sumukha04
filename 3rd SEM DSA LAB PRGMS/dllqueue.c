#include<stdio.h>
#include<stdlib.h>
struct node
{
    char ID[100], name[100], branch[100], specialisation[100];
    struct node *rlink;
    struct node *llink; 
};
typedef struct node *NODE;
NODE first= NULL;
int count=0;
NODE create()
{
    NODE enode;
    enode=(NODE)malloc(sizeof(struct node));
    if(enode == NULL)
    {
        printf("\n Runnig out of Memory\n");
        exit(0);
    }
    printf("\n Enter the ID, Name, Branch , Area of Speacialisation\n");
    scanf("%s%s%s%s", enode->ID, enode->name, enode->branch, enode->specialisation);
    enode->llink=NULL;
    enode->rlink=NULL;
    count ++;
    return enode;
}
NODE insert()
{
    NODE cur, temp;
    temp=create();
    if(first==NULL)
    {
        return temp;
    }
    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    return first;
}
NODE delete()
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nDoubly Lnked List is empty\n");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("The employee node with SSN %s is deleted\n", first->ID);
        free(first);
        count--;
        return NULL;
    }
    temp=first;
    first=first->rlink;
    temp->rlink=NULL;
    first->llink=NULL;
    printf("\n The employee node with SSN %s is deleted", temp->ID);
    free(temp);
    count--;
    return first;
}
void display()
{
    NODE cur;
    int nodeno=1;
    cur=first;
    if(cur==NULL)
    printf("\n No contents to dsiplay in DLL\n");
    while(cur!=NULL)
    {
        printf("\nEnode:%d\n ID:%s\n Name:%s\n Branch:%s\n Area of Specialisation:%s\n", nodeno, cur->ID, cur->name, cur->branch, cur->specialisation);
        cur=cur->rlink;
        nodeno++;
    }
    printf("\n NO of employee nodes are: %d", count);
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n Queue operation\n");
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:first=insert();
            break;
            case 2:first=delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:return;
        }
    }
}