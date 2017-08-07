#define MM 1000002

#include<bits/stdc++.h>
using namespace std;






vector<int> adj[MM];
int d[MM];

void bfs(int src)
{
    queue<int> q;
    d[src] = 0;

    q.push(src);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i=0; i<adj[x].size(); i++)


        {
            int u =  adj[x][i];


            if(d[u]==-1)
            {
                d[u] = d[x] + 1;
                q.push(u);
            }
        }

    }

}
int main()
{
    memset(d, -1, sizeof(d));
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
    }
    bfs(0);

    for(int i=0; i<n; i++)
    {
        printf("%d:",i);
        if(d[i]!=-1)
        {
            printf(" %d\n",d[i]);
        }
        else printf(" Not Reachable\n");

    }
    return 0;


}
