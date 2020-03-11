///Depth First Search
#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
bool visited[10];
int  ti, discover[10], finish[10], color[10];
void dfs(int source)
{
    visited[source] = true;
    ti = ti+ 1;
    discover[source] = ti;
    color[source] = 1;
    for(int i = 0; i < adj[source].size(); ++i)
    {
        if(visited[adj[source][i]] == false)
            dfs(adj[source][i]);
    }
    color[source] = 2;
    ti = ti + 1;
    finish[source] = ti;
}

void initialize()
{
    for(int i = 0; i < 10; ++i)
        visited[i] = false;
}

int main()
{

    int nodes, edges, x, y, connectedComponents = 0;
    cout<<"Enter the number of nodes:"<<endl;
    cin >> nodes;
    cout<<"Enter the number of edges:"<<endl;
    cin >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    initialize();
    for(int i = 1; i <= nodes; ++i)
    {
        if(visited[i] == false)
        {
            dfs(i);
            connectedComponents++;
        }
    }
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}

/*
Input:
Enter the number of nodes:
6
Enter the number of edges:
5
1 2
1 3
3 2
4 5
5 6
Output:
Number of connected components: 2
*/
