#include <bits/stdc++.h>
#define MM 50005
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 100000000

using namespace std;



int adj[MM];

bool d[MM], valid[MM];
int c[MM];

void dfs(int src, int cnt)
{
    d[src] = 1;
    ++cnt;

    int u =  adj[src];

    if(d[u]==0)
    {
        dfs(u, cnt);
    }

    c[src] = cnt;
}


int main()
{
    freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
    int cas;
    scan(cas);

    FOR(tc, cas)
    {
        CLR(adj);
        CLR(d);
        CLR(valid);
        CLR(c);

        int nodes;
        scan(nodes);
        FOR(i, nodes)
        {
            int u, v;
            scan(u);
            scan(v);
            valid[u]=true;
            adj[u]=v;
        }

        for(int i = 1; i<=nodes; i++)
        {
            if(d[i]==0 && valid[i])
                dfs(i, 0);
        }

        for(int i = 1; i<=nodes; i++)
        {
            printf("%d nodes visitable from %d\n", c[i], i);
        }




    }

}
