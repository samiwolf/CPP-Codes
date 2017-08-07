#define MM 1000002

#include<bits/stdc++.h>
using namespace std;






vector<int> adj[MM];
int d[MM];

void bfs(int src, int node)
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
                if(d[u]==-1 && u !=node)
                {
                    d[u] = d[x] + 1;
                    q.push(u);
                }
            }


    }

}

int main()
{ freopen("in.txt", "r",stdin);

    memset(d, -1, sizeof(d));
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    printf("Articulation Points:")

    for(int i=0; i<n; i++)
    {
        memset(d, -1, sizeof(d));



        if(i==0)
            bfs(1, i);
        else bfs(0, i);

        bool artistic = false;

        for(int j=0; j<n; j++)
        {
            if(d[j]==-1 && j!=i)
            {
                //printf("%d not visited when source is %d\n", j, i);
                artistic = true;
            }

        }
        if(artistic)
        printf(" %d", i);
    }
    return 0;


}
