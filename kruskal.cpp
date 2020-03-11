/// Find Minimum Spanning Tree using Kruskal Algorithm

#include <bits/stdc++.h>
using namespace std;
int id[1000], nodes, edges;
pair <long long, pair<int, int> > p[1000];
void initialize()
{
    for(int i = 0; i < 1000; ++i)
        id[i] = i;
}
int root(int x)
{
    while(id[x] != x)
    {
        //id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    //freopen("t.txt","r",stdin);
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cout<<"Enter the number of nodes:"<<endl;
    cin >> nodes;
    cout<<"Enter the number of edges:"<<endl;
    cin >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin  >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout <<" Minimum_Cost:"<< minimumCost << endl;
    return 0;
}

/*
Input:
Enter the number of nodes:
5
Enter the number of edges:
7
1 2 1
1 3 7
2 3 5
2 4 4
3 5 6
4 5 2
3 4 3
Output:
Minimum_Cost:10

*/
