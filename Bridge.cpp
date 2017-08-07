#define MM 2005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];

int  d[MM],low[MM];
int parent[MM], tim = 0;
bool visited[MM];


void findBridge(int u)
{

    low[u]=d[u] = ++tim;
    visited[u] = true;


    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];




        if (!visited[v])
        {
            parent[v] = u;
            findBridge(v);

            low[u] = min(low[u], low[v]);

            if (d[u] < low[v] )
            {
                cout<<u<<"---"<<v<<endl;
            }
        }
        else if (v!= parent[u])
            low[u] = min(low[u], d[v]);

    }

}

int main()
{
     //freopen("in.txt", "r",stdin);

    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++)
    {
        visited[i] = false;
        low[i]=d[i] = 0;
    }



    for(int i=0; i<n; i++)
    {
        if(d[i]==0)
        {
           findBridge(i);

        }
    }


    return 0;


}

