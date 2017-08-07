#define MM 100005

#include<bits/stdc++.h>
using namespace std;






vector<int> adj[MM];
int d[MM], prev[MM], col[MM];
int n,u,v, m, temp=0;
int bfs(int src)
{
    queue<int> q;
    d[src] = 0;
    col[src] = 0;
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
                prev[u] = x;
                col[u] = 1 - col[x];
                d[u] = d[x] + 1;
                q.push(u);
                temp = u;
                //printf("hi\n");
            }
        }

    }

   // printf("%d\n", temp);
    return temp;

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

bool isBipartite()
{
    memset(col, 0, sizeof(col));
    memset(d, -1, sizeof(d));
    for(int i=0; i<n; i++)
    {
        if(d[i]==-1) bfs(i);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)

        {
            int x =  adj[i][j];
            if(col[i]==col[x]) return false;
        }
    }

    return true;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    memset(d, -1, sizeof(d));

    scanf("%d",&n);
    m = n-1;
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    int u = bfs(0);

    memset(d, -1, sizeof(d));
    int v = bfs(u);
    printf("%d\n", d[v]);


    return 0;


}
