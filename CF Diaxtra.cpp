#include<bits/stdc++.h>
using namespace std;

struct graph
{
    vector<int>adj[100005];
    vector<int>cost[100005];
    int n, prev[100005];
    long long  d[100005];
    graph()
    {


        for(int i=0; i<100004; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }

        for(int i=0; i<100004; i++)
        {
            d[i] = 1e17;
            prev[i] = -1;
        }

    }

    void input(int u, int v, int cos)
    {

        cost[u].push_back(cos);
        adj[u].push_back(v);

        cost[v].push_back(cos);
        adj[v].push_back(u);

    }

    void diax(int src)
    {
        priority_queue<int> q;
        d[src] = 0;
        q.push(src);

        while(!q.empty())
        {
            int u = q.top();
            q.pop();
            for(int i=0; i<adj[u].size(); i++)

            {
                int v =  adj[u][i];
                if(d[u] + cost[u][i] < d[v])
                {
                    d[v] = d[u] + cost[u][i];
                    prev[v] = u;
                    q.push(v);
                }
            }

        }

    }

    void printPath(int n, int i)
    {
        if(i==n)
        {
            printf("%d ", n);
            return;
        }
        printPath(prev[n],  i);

        printf("%d ", n);

    }

} g;



int main()
{
    int m, tp;
    scanf("%d %d", &g.n, &m);

    for(int i=0; i<m; i++)
    {
        int u, v, cos;
        scanf("%d %d %d", &u, &v, &cos);
        g.input(u, v, cos);
    }


    g.diax(1);
    if(g.prev[g.n] != -1)
    {
        g.printPath(g.prev[g.n], 1);
        printf("%d\n", g.n);
    }
    else printf("-1\n");



    return 0;
}
