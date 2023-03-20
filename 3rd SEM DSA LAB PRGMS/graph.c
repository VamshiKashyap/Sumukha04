#include<stdio.h>
#include<stdlib.h>
int a[10][10],n,m,i,j,source,s[10],b[10];
int visited[10];
void create()
{
    printf("\nEnter the no of vertices of the digraph:");
    scanf("%d",&n);
    printf("\nEnter the adjacent matrix of the graph:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
}
void bfs()
{
    int q[10],u,front=0,rear=-1;
    printf("\nEnter the source vertex to find other nodes rechable or not: ");
    scanf("%d",&source);
    for(i=0;i<0;i++)
    visited[i]=0;
    q[++rear]=source;
    visited[source]=1;
    printf("\n The reachable vertices are:");
    while(front<=rear)
    {
        u=q[front++];
        for(i=1;i<=n;i++)
        {
            if(a[u][i]==1 && visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
                printf("\n %d",i);
            }
        }
    }
}
void dfs(int source)
{
    int v,top=-1;
    s[++top]=1;
    b[source]=1;
    for(v=1;v<=n;v++)
    {
        if (a[source][v]==1 && b[v]==0)
        {
            printf("\n%d->%d",source,v);
            dfs(v);
        }        
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create graph\n2.BFS\n3.Check graph connected or not\n4.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                break;
            case 2: bfs();
                for(i=1;i<n;i++)
                    if(visited[i]==0)
                        printf("\n The vertex that is not rechable is %d",i);
                break;
            case 3: printf("\nEnter the source vertex to find the connectivity: ");
            scanf("%d",&source);
            m=1;
            for(i=0;i<10;i++)
                b[i]=0;
            dfs(source);
            for(i=1;i<=n;i++)
            {
                if(b[i]==0)
                m=0;
            }
            if(m==1)
            printf("\nGraph connected");
            else
            printf("\nGraph not connected");
            default:exit(0);
        }
    }
}