#define FOR(i,n) for(int i=0; i<n; i++)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define inf (1<<29)
#define ii64 long long
#define MM 10010

#include<bits/stdc++.h>
using namespace std;


struct data
{
    int a, b;

    data(int x, int y)
    {
        a = x;
        b = y;
    }

    bool operator<(const data& rhs) const
    {
        if (a < rhs.a) return true;
        if (a == rhs.a) return b < rhs.b;
        return false;
    }
};



vector<int> adj[MM];
vector<data>vec;
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
                if(u<=v)
                vec.push_back(data(u,v));
                else vec.push_back(data(v,u));
            }
        }
        else if (v!= parent[u])
            low[u] = min(low[u], d[v]);

    }

}

int main()
{
   // freopen("in.txt", "r",stdin);
  //  freopen("out.txt", "w",stdout);

    int n,u,v, m,tc;
    cin>>tc;
    FOR(p,tc)
    {

        tim = 0;
        vec.clear();
        FOR(o, 10010)
        adj[o].clear();

        cin>>n;
        FOR(i,n)
        {
            visited[i] = false;
            low[i]=d[i] = 0;
            parent[i] = -1;

            int node;
            int non;
            scanf("%d ", &node);
            scanf("(%d)", &non);
            while(non--)
            {
                int k;
                cin>>k;
                adj[node].push_back(k);
                adj[k].push_back(node);

            }
        }

        FOR(i,n) if(d[i]==0) findBridge(i);

        sort(vec.begin(), vec.end());

        int sz = vec.size();

        printf("Case %d:\n", p+1);

        printf("%d critical links\n",sz);

        FOR(i, sz)
        {
            data d = vec[i];
            printf("%d - %d\n", d.a, d.b);
        }






    }
    /*
    FOR(i,n)

    {
        FOR(k, adj[i].size())
        {
            printf("%d ", adj[i][k]);
        }
        printf("\n");
    }

    /*for(int i=0; i<n; i++)
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
    }*/

    // /home/samiul/Algo_lab_localoj_2017_07_17/Critical Links LOJ.cpp|64|error: request for member ‘push_back’ in ‘v’, which is of non-class type ‘int’|
    return 0;


}

