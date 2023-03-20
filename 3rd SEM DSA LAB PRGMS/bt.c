#include<stdio.h> 
#include<stdlib.h> 
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
typedef struct node NODE;
NODE* newNode(int d)
{
 NODE *point;
 point = (NODE*)malloc(sizeof(NODE));
 point->data = d;
 point->left = NULL;
 point->right = NULL;
 return point;
}
NODE* insertLevelOrder(int a[], NODE *root, int i, int n)
{
 if(i<n)
 {
 root = newNode(a[i]);
 root->left = insertLevelOrder(a, root->left, 2*i+1, n);
 root->right = insertLevelOrder(a, root->right, 2*i+2, n);
 }
 return root;
}
void inOrder(NODE *root)
{
 if(root != NULL)
 {
 inOrder(root->left);
 printf("%d\t", root->data);
 inOrder(root->right);
 }
}
int main()
{
 int n, i, a[40];
 NODE *root;
 printf("\n Enter the number of nodes in the tree:");
 scanf("%d",&n);
 printf("\n Enter the nodes for the Binary tree:");
 for(i=0; i<n; i++)
 scanf("%d",&a[i]);
 root = insertLevelOrder(a, root, 0, n);
 printf("\nNodes of the Binary tree constructed in level order fashion are:");
 inOrder(root);
}
