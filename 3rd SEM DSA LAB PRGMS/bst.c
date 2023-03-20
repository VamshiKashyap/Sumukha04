#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST *NODE;

NODE create()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct BST));
    printf("\nEnter the value");
    scanf("%d",&temp->data);
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
void insert(NODE root,NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);

void insert(NODE root,NODE newnode)
{
    if(newnode->data < root->data)
    {
        if(root->lchild==NULL)
            root->lchild=newnode;
        else
            insert(root->lchild,newnode);
    }
    if(newnode->data > root->data)
    {
        if(root->rchild==NULL)
            root->rchild=newnode;
        else
            insert(root->rchild,newnode);
    }
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d",root->data);
    }
}
void main()
{
    int ch,key,val,i,n;
    NODE root = NULL,newnode;
    while(1)
    {
        printf("\n~~~BST MENU~~~\n");
        printf("\n1.Create a BST\n2.BST Traversals\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of elements: ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                newnode = create();
                if(root == NULL)
                    root=newnode;
                else
                    insert(root,newnode);
            }
            break;
            case 2:if(root==NULL)
                printf("\nThe tree is not created");
            else
            {
                printf("\nThe preorder display: ");
                preorder(root);
                printf("\nThe Inorder display: ");
                inorder(root);
                printf("\nThe postorder display: ");
                postorder(root);
            }
            break;
            case 3:exit(0);
}
    }
}
