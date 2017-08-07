#define MM 12
#define NL() printf("\n")
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int d[MM];
int length[MM];
int parent[MM];
vector<int> par;
void shortest_bfs(int src)
{
    queue<int> q;
    d[src] = 0;

    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)


        {
            int v =  adj[u][i];


            if(d[v]==-1)
            {
                parent[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }

    }

}

bool isValid(int v)
{
    FOR(k, par.size())
    if(v==par[k])
        return false;
    return true;
}

void bfs(int src)
{
    queue<int> q;
    d[src] = 0;

    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v =  adj[u][i];


            if(d[v]==-1 && isValid(v))
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }

    }

}


int main()
{
    SET(d);
    CLR(length);
    SET(parent);
    freopen("in.txt", "r", stdin);
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dest;
    scan(dest);
    shortest_bfs(1);
    int best1 = d[dest];

    if(best1==-1)
    {
        printf(" Not Reachable\n");
    }
    else
    {
        SET(d);
        int ddd = dest;
        printf("shortest path length is %d\n", best1);

        while(ddd[parent]!=-1)
        {
            par.pb(ddd[parent]);
            ddd = ddd[parent];
        }

        FOR(k,par.size())
        printf("%d", par[k]);
        NL();

        FOR(k,par.size())
        {
            int len = k+1;
            int fb = par[k];

            if(k==0)
            {

                printf("%d is found\n", par[k]);
                FOR(h,adj[fb].size())
                {

                    int x = adj[fb][h];
                    printf("%d\n", x);
                    if(x!=dest)
                    {
                        SET(d);
                        bfs(x);
                        printf("node %d normal len %d short len %d", x,len, d[dest]);
                        if(d[dest] + 1 > len)
                            length[x] = d[dest]-len + 1;
                        NL();
                    }
                }
            }

            else
            {
                SET(d);
                bfs(fb);
                printf("node %d normal len %d short len %d", fb,len, d[dest]);
                if(d[dest] > len)
                    length[fb] = d[dest]-len;
                NL();
            }
        }

        int secmin = 9999;
        for(int k =0; k<=MM; k++)
        {
            printf("extra from %d is %d\n", k, length[k]);
            if(length[k]!=0 && length[k]<secmin)
                secmin = length[k];
        }

        printf("sec min = %d\n", best1 + secmin);


    }


    return 0;


}
