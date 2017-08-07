#define MM 20005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];

int  d[MM],low[MM];
int parent[MM], no_of_children =  0, tim = 0;
bool visited[MM], artiPoint[MM];


void findArti(int u)
{

    tim =  tim+1;
    low[u]=d[u] = tim;
    visited[u] = true;
    no_of_children =  0;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(v == parent[u]) continue;

        if (visited[v]) //This is a backedge
            low[u] = min(low[u], d[v]);

        if (!visited[v])
        {
            parent[v] = u;
            findArti(v);
            low[u] = min(low[u], low[v]);
            if (d[u] <= low[v] && u!=0)
            {
                artiPoint[u]=true;
            }
            if(u==0)
            no_of_children=no_of_children+1;
        }
        if(no_of_children>1 && u ==0)
            artiPoint[u]=true;

    }

}

int main()
{
//    freopen("in.txt", "r",stdin);

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

        artiPoint[i] = false;
        visited[i] = false;
        low[i]=d[i] = 0;
    }



    for(int i=0; i<n; i++)
    {
        if(d[i]==0)
        {
           findArti(i);

        }
    }

     for(int i=0; i<n; i++)
    {
        if(artiPoint[i])
        {
            printf("%d ", i);

        }

    }

    return 0;


}
