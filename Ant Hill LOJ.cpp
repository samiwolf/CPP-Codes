#define MM 10010
#define scan(a) scanf("%d",&a);
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];

int  d[MM],low[MM];
int parent[MM], child =  0, tim = 0;
bool visited[MM], artiPoint[MM];

int noc = 0;
void findArti(int u)
{

    tim =  tim+1;
    low[u]=d[u] = tim;
    visited[u] = true;


    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(v == parent[u]) continue;

        if (visited[v])
            low[u] = min(low[u], d[v]);

        if (!visited[v])
        {
            parent[v] = u;
            findArti(v);
            low[u] = min(low[u], low[v]);
            if (d[u] <= low[v] && u!=0)
            {
                artiPoint[u]=true;
            }
            if(u==0)
                child=child+1;
        }
        if(child>1 && u ==0)
            artiPoint[u]=true;

    }

}

int main()
{
  //  freopen("in.txt", "r",stdin);
 //   freopen("out.txt", "w",stdout);
    int tc;
    scan(tc);
    for(int tt=0; tt<tc; tt++)
    {


        for(int i=0; i<MM; i++)
        {
            adj[i].clear();
        }
        child = 0;


        int n,u,v, m;
        scanf("%d %d",&n, &m);
        while(m--)
        {
            scanf("%d %d",&u, &v);
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        for(int i=0; i<n; i++)
        {

            artiPoint[i] = false;
            visited[i] = false;
            low[i]=d[i] = 0;
        }
        findArti(0);



        int sum = 0;

        for(int i=0; i<n; i++)
        {
            if(artiPoint[i])
            {

                sum++;
            }

        }

        printf("Case %d: %d\n",tt+1, sum);
    }
    return 0;


}

