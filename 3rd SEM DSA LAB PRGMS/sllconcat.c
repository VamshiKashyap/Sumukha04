#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct node *next;
}*temp=NULL,*First=NULL,*second=NULL;
struct Node *create(int a[],int n){
    struct Node *t,*last;
    temp=(struct node*)malloc(sizeof(struct Node));
    temp->data=a[0];
    temp->next=NULL;
    last = temp;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
     return temp;
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
void concat(struct Node *First,struct Node *second){    
    struct Node *p=First;
    while(p->next!=NULL)
        p=p->next;
    
p->next=second;
second=NULL;
    
}
int main(){
    int a[]={9,7,4,3};
    int b[]={2,5,6,8};
    First=create(a,4);
    second=create(b,4);
    printf("\n1st Linked list: ");
    display(First);
    printf("\n2nd Linked list: ");
    display(second);
    concat(First,second);
    printf("\n Concatenated Linked LIst: \n");
    display(First);
return 0;
}
