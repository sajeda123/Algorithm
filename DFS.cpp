#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10]; ///vector <vector<int> > adj;
bool visited[10];
int color[10],discover[10],finish[10],t,connectedComponent;

void DFS(int s){
    visited[s]=true;
    t=t+1;
    discover[s]=t;
    color[s]=1;
    for(int i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]]==false){
             DFS(adj[s][i]);
        }
    }
    color[s]=2;
    t=t+1;
    finish[s]=t;

}

int main()
{
  int nodes,edges,m,n;
  cin>>nodes;
  cin>>edges;
  for(int i=1;i<=edges;i++){
        cin>>m>>n;
      adj[m].push_back(n);
      adj[n].push_back(m);
  }
  for(int i=1;i<=nodes;i++){
     if(visited[i]==false){
        DFS(i);
        connectedComponent++;
     }

  }
   cout<<"Connected Component="<<connectedComponent<<endl;
   int a;
   cin>>a;
   cout<<"Discover_Time="<<discover[a]<<endl;
   cout<<"Finish_Time="<<finish[a]<<endl;
}
