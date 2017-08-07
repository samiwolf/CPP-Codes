#define MM 10010
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

vector<int> adj[MM];

int  d[MM],low[MM];
int parent[MM], tim = 0;
bool visited[MM];
bool vis[MM];


void findBridge(int u)
{


    low[u]=d[u] = ++tim;
    visited[u] = true;


    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if (!visited[v] && v!=-1)
        {
            parent[v] = u;
            findBridge(v);

            low[u] = min(low[u], low[v]);

            if (d[u] < low[v] )
            {

                FOR(kk, adj[u].size())
                if(adj[u][kk]==v)
                    adj[u][kk] =-1;

                FOR(kk, adj[v].size())
                if(adj[v][kk]==u)
                    adj[v][kk] =-1;

               // cout<<u<<"---"<<v<<endl;
            }
        }
        else if (v!= parent[u])
            low[u] = min(low[u], d[v]);

    }



}


void dfs(int src)
{

    vis[src] = true;

    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(vis[u]==0 && u!=-1)
        {
            dfs(u);
        }
    }


}

int main()
{
    freopen("in.txt", "r",stdin);
    freopen("out.txt", "w",stdout);
    tim = 0;
    int tc;
    scan(tc);
    for(int tt=0; tt<tc; tt++)
    {


        for(int i=0; i<MM; i++)
        {
            adj[i].clear();
            vis[i] = false;
            visited[i] = false;
            d[i] = low[i] = 0;
            parent[i] = i;
        }



        int n,u,v, m;
        scanf("%d %d",&n, &m);
        while(m--)
        {
            scanf("%d %d",&u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


            findBridge(0);

         int cnt = 0;
         FOR(i,n)
         {
             if(!vis[i])
             {
                 dfs(i);
                 cnt++;
             }
         }


          //printf("\n\n%f\n", f);

         printf("Case %d: %d\n",tt+1, (int) ceil(cnt/2));



       // printf("Case %d: %d\n",tt+1, sum);
    }
    return 0;


}

