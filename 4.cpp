#define MM 200005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int compn = 1;
bool cycle = false;
int d[MM], start[MM], finish[MM], tim = 0, cn[MM], col[MM];

void dfs(int src, int cmn)
{
    d[src] = 2;
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
        else if(d[u]==2){
      //printf("Found %d at %d\n", u, src);
        cycle = true;
        }
    }
    ++tim;

    finish[src] = tim;
    cn[src] = cmn;
    d[src] = 1;
    //printf("finish %d at time %d\n",src, tim);
}

int main()
{
    memset(d, 0, sizeof(d));
    memset(cn, 0, sizeof(cn));
    memset(col, -1, sizeof(col));
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
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
            // memset(d, 0, sizeof(d));

        }

    }
    if(cycle)
        printf("Yes\n");
  else printf("No\n");


    return 0;


}
