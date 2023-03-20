#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10
struct employee 
{
 int id;
 char name[15]; 
};
typedef struct employee EMP;
EMP emp[MAX];
int create(int key)
{
 int adr;
 adr = key % 10; 
 return adr;
}
int getemp(int pos) 
{
 printf("\nEnter emp id: "); 
 scanf("%d",&emp[pos].id); 
 printf("\nEnter emp name: ");
 scanf("%s",emp[pos].name); 
 return pos;
}
void display(int a[])
{
 int i, ch;
 printf("\n1.Display ALL\n2.Filtered Display"); 
 printf("\nEnter the choice: "); 
 scanf("%d",&ch);
 if(ch == 1) 
 {
 printf("\nThe hash table is:\n"); 
 printf("\nHTKey\tEmpID\tEmpName"); 
 for(i=0; i<MAX; i++)
 printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
 }
 else 
 {
 printf("\nThe hash table is:\n"); 
 printf("\nHTKey\tEmpID\tEmpName"); 
 for(i=0; i<MAX; i++)
 if(a[i] != -1)
 {
 printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name); 
 } 
 }
}
void linear_prob(int a[MAX], int adr, int key) 
{
 int flag, i, count = 0; flag = 0;
 if(a[adr] == -1) 
 {
 a[adr]=getemp(adr); 
 }
 else
 {
 printf("\nCollision Detected...!!!\n");
 for(i=0; i<MAX; i++)
if (a[i] != -1) 
 count++;
 if(count == MAX)
 {
 printf("\n Hash table is full");
 display(a); 
 exit(1);
 }
 printf("\nCollision avoided successfully using LINEAR PROBING\n"); 
 for(i=adr+1; i<MAX; i++)
 if(a[i] == -1)
 {
 a[i] = key;
 getemp(i);
 flag = 1;
 break;
 }
 i = 0;
 while((i < adr) && (flag == 0))
 {
 if(a[i] == -1) 
 {
 a[i] = key;
 getemp(i); 
 flag=1; 
 }
 i++;
 } // end while
 } // end else
} // end linear_prob()
void main()
{
 int a[MAX],key,adr,i; 
 int ans = 1; 
 printf("\nCollision handling by linear probing: "); 
 for (i=0; i < MAX; i++)
 {
 a[i] = -1;
 }
 do 
 {
 printf("\nEnter the data: ");
 scanf("%d", &key);
 adr=create(key);
 linear_prob(a, adr, key);
 printf("\nDo you wish to continue? (1/0): "); 
 scanf("%d",&ans);
 }while(ans); 
 display(a); 
}