#define MM 1000002

#include<bits/stdc++.h>
using namespace std;






vector<int> adj[MM];
int d[MM], prev[MM];

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
            {    prev[u] = x;
                d[u] = d[x] + 1;
                q.push(u);
            }
        }

    }

}

void printPath(int i)
{
   if(i==0)
   {
    printf(" 0");
   return;
   }
   printPath(prev[i]);
   printf(" %d", i);

}
int main()
{
   // freopen("input.txt", "r", stdin);
    memset(d, -1, sizeof(d));
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
        prev[i] = i;
    }

    bfs(0);

    if(n>0){


    printf("0: 0\n");

    for(int i=1; i<n; i++)
    {
        printf("%d:",i);
        if(prev[i]!=i)
        {
            printPath(i);
            printf("\n");
        }
        else printf(" Not Reachable\n");

    }


    }
    return 0;


}
