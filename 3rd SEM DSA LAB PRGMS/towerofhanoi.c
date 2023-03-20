#include<stdio.h>
#include<math.h>
void tower(int n, int source, int temp, int destination)
{
    if(n==0)
    return;
    tower(n-1, source, destination, temp);
    printf("\n Move disc %d from %c to %c", n, source, destination);
    tower(n-1, source, temp, destination);
}
void main()
{
    int n;
    printf("Enter the number of discs: \n\n");
    scanf("%d", &n);
    printf("The sequence of moves involved in the tower of hanoi are\n");
    tower(n, 'A', 'B', 'C');
    printf("\n\nTotal number of moves are: %d\n", (int)pow(2, n)-1);
}