#define MM 20005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int compn = 1;
int d[MM], start[MM], finish[MM], tim = 0, cn[MM];

void dfs(int src, int cmn)
{
    d[src] = 1;
    ++tim;
    start[src] = tim;
    // printf("start %d at time %d\n",src, tim);
    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            d[u] = 1;
            cn[u] = cmn;
            dfs(u, cmn);
        }
    }
    ++tim;

    finish[src] = tim;
    cn[src] = cmn;
    //printf("finish %d at time %d\n",src, tim);
}

int main()
{
    memset(d, 0, sizeof(d));
    memset(cn, 0, sizeof(cn));
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
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i=0; i<n; i++)
    {
        if(d[i]==0)
        {
            dfs(i, compn);
            ++compn;
        }

    }

    for(int i=0; i<n; i++)
    {
        printf("%d:",i);
        printf(" %d %d %d\n",cn[i], start[i], finish[i]);
    }
    return 0;


}
