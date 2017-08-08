#define MM 502
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
bool isFs[MM], valid[MM];

int  n, d[MM], dis[MM];




void diax(int src)
{
  // printf("started from %d\n", src);
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
                q.push(v);
            }
        }

    }

}






int main()
{
    freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);


    int tc;
    scan(tc);
    FOR(tt, tc)
    {
        int m, tp;

        CLR(isFs);
        CLR(dis);

        for(int i=0; i<MM; i++)
        {
            adj[i].clear();
            cost[i].clear();
            d[i] = inf;
        }


        scanf("%d %d", &n, &m);

        FOR(i,n)
        {
            int fs;
            scan(fs);
            isFs[fs] = true;
        }



        FOR(i,m)
        {
            int u, v, cos;
            scanf("%d %d %d", &u, &v, &cos);
            adj[u].push_back(v);
            cost[u].push_back(cos);
            adj[v].push_back(u);
            cost[v].push_back(cos);

            valid[u]=true;
            valid[v]=true;
        }

        FOR(i,MM)
        {

            if(isFs[i] && valid[i])
            {
                diax(i);
            FOR(xx,MM)
            {
                if(valid[xx])
                dis[xx]+=d[xx];
                d[xx] = inf;
            }
            }

        }

        int mi = -1, mx = -999999;

        FOR(i,MM)
        {


            if(!isFs[i] && valid[i])
            {
                if(dis[i]>mx)
                {
                    mx = dis[i];
                    mi = i;
                }
            }

        }

        printf("%d\n", mi);
        if(tt!=tc-1)
        printf("\n");


    }
    return 0;
}
