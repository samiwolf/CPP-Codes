#define MM 20005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM], other[MM];
vector<int> tops;
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
    tops.push_back(src);
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
        //  adj[v].push_back(u);
        other[v].push_back(u);
        other[u].push_back(v);
    }


    bool connected = true;

    dfs(0, compn);
    ++compn;

    for(int i=0; i<n; i++)
    {
        if(cn[i]!=1)
        {
            connected = false;
            break;
        }
    }

    if(!connected)
    {
        compn = 1;
        memset(d, 0, sizeof(d));
        memset(cn, 0, sizeof(cn));
        dfs(0, compn);
        bool wcc = true;
        for(int i=0; i<n; i++)
        {
            if(d[i]!=1)
            {
                wcc = false;
                break;
            }
        }

        if(wcc)
            printf("WCC\n");
        else printf("Not WCC\n");


    }

    else printf("Already Connected\n");



    return 0;


}
