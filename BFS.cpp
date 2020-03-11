#include<vector>
#include<queue>
#include<stdio.h>
#define NIL -1
using namespace std;
vector<int> V[13];
queue<int> bfsq;
int parent[10], dist[10], visited[10], color[10], N, M;
void BFS(int source)
{
    int u, v, i;
    bfsq.push(source);
    visited[source]=1;
    color[source]=1;
    dist[source]=0;
    parent[source]=NIL;
    while(!bfsq.empty())
    {
        u=bfsq.front();
        bfsq.pop();
        for(i=0; i<V[u].size(); i++)
        {
            v=V[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                color[v]=1;
                dist[v]=dist[u]+1;
                parent[v]=u;
                bfsq.push(v);
            }
        }
        color[u]=2;
    }
    //for(int i=0;i<10;i++) printf("%d\n",dist[i]);
}

void GraphCreate()
{
    int a, b, i;
    printf("How many  vertices?");
    scanf("%d", &N);
    printf("How many edges?");
    scanf("%d", &M);
    i=1;
    printf("Enter edges:\n");
    while(i<=M)
    {
        scanf("%d%d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
        i++;
    }
}

void BFSDisplay(int source)
{
    for(int i=0;i<=10;i++)
        printf("distance of node%d from node source node %d is %d\n",i,source,dist[i]);

}


void display()
{
    int i, j;
    for(i=1; i<N; i++)
    {
        printf("%d", i);
        for(j=0; j<V[i].size(); j++)
        {
            printf("%4d", V[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    //freopen("t.txt","r",stdin);
    int source;
    GraphCreate();
    printf("Graph has been created.....\n");
    display();
    while(1)
    {
        scanf("%d", &source);
        if(source==-1)
            break;
        BFS(source);
        BFSDisplay(source);
    }
    return 0;

}
