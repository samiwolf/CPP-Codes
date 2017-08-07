#define MM 10010
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 999999999

#include<bits/stdc++.h>
using namespace std;


vector<int>adj[MM];
vector<int>cost[MM];

int  n, d[MM];




void diax(int src)
{
    priority_queue<int> q;
    d[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        printf("%d.. \n", u);
        for(int i=0; i<adj[u].size(); i++)

        {
            int v =  adj[u][i];
            if(d[u] + cost[u][i] < d[v])
            {
                d[v] = d[u] + cost[u][i];
                q.push(v);
            }
        }

    }

}






int main()
{
    int m, tp;

    memset(d, 0, sizeof(d));

    for(int i=0; i<MM; i++)
    {
        adj[i].clear();
        cost[i].clear();
        d[i] = inf;
    }


        scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int u, v, cos;
        scanf("%d %d %d", &u, &v, &cos);
        adj[u].push_back(v);
        cost[u].push_back(cos);
    }

    diax(0);

    FOR(j,n)
    {
        printf("%d - %d\n", j, d[j]);
    }


    return 0;
}

/*4 5
0 1 2
1 2 1
0 2 5
0 3 4
2 3 9*/
