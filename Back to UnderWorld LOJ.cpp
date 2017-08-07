#include <bits/stdc++.h>
#define MM 20005
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 1e17

using namespace std;

int n;

int maxx = 0;

vector<int> adj[MM];
int col[MM];
bool d[MM], valid[MM];


void bfs(int src)
{
    int zero = 0;
    int one = 1;

    queue<int> q;
    d[src] = 1;
    col[src] = 1;

    q.push(src);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i=0; i<adj[x].size(); i++)

        {
            int u =  adj[x][i];


            if(d[u]==0)
            {
                d[u] = 1;
                col[u] = 1 - col[x];

                if(col[u]==0)
                    zero++;
                else if(col[u]==1)
                    one++;

                q.push(u);
            }
        }

    }

    if(zero>one)
        maxx+=zero;
    else maxx+=one;

}
int main()
{
     //  freopen("in.txt", "r", stdin);
   //  freopen("out.txt", "w", stdout);
    int tc;
    scan(tc);

    FOR(tt, tc)
    {

        maxx=0;
        CLR(d);
        CLR(valid);
        SET(col);

        FOR(h, MM) adj[h].clear();


        scan(n);
        while(n--)
        {
            int u,v;
            scanf("%d %d",&u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            valid[u]=1;
            valid[v]=1;
        }

        for(int k = 1; k<=20000; k++)
            if(valid[k] && d[k]==0)
              bfs(k);
       printf("Case %d: %d\n", tt+1, maxx);

    }
        return 0;


    }
