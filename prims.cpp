/// Find Minimum Spanning Tree using prims Algorithm
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> PII;
bool marked[1000];
vector <PII> adj[1000];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {

        p = Q.top();
        Q.pop();
        x = p.second;

        if(marked[x] == true)
        {
            //cout<<"before == "<<x<<endl;
            continue;
            //cout<<"after == "<<x<<endl;
        }
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{

    int nodes, edges, x, y;
    long long weight, minimumCost;
    cout<<"Enter the number of nodes:"<<endl;
    cin >> nodes;
    cout<<"Enter the number of edges:"<<endl;
    cin >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
     }

    minimumCost = prim(1);
    cout << "Minimum_Cost="<<minimumCost << endl;
    return 0;
}
/*
Input:
Enter the number of nodes:
4
Enter the number of edges:
5
1 2 1
2 3 3
3 4 2
4 1 4
1 3 5
Output:
Minimum_Cost=6
*/
