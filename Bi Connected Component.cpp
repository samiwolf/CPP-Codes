
#include <bits/stdc++.h>
#define MM 2005
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 100000000

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

void dfs(int src)
{
    d[src] = 1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0 && !artiPoint[u])
        {
            printf(" %d",u);
            dfs(u);
        }
    }

}

int main()
{
   freopen("in.txt", "r",stdin);
    CLR(d);
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
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

    CLR(d);

    int cnt = 1;

    for(int i=0; i<n; i++)
    {

        if(d[i]==0 && !artiPoint[i])
        {
            printf("BCC %d - %d",cnt++, i);
            dfs(i);
            printf("\n");

        }


    }

    return 0;


}




