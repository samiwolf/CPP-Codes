#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 10100

#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int n;
int d[MM];
int sum = 0;

//int cnt = 0;

void dfs(int src)
{
    d[src] = 1;
    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            dfs(u);
        }
    }
}


int main()
{
    int tc;
    freopen("in.txt", "r", stdin);

  freopen("out.txt", "w", stdout);

    cin>>tc;
    FOR(i,tc)
    {

        int m,l;
        cin>>n>>m>>l;

        FOR(h,10100)
        adj[h].clear();
        CLR(d);

        FOR(j,m)
        {
            int d1, d2;
            cin>>d1>>d2;
            adj[d1].pb(d2);
        }

        FOR(k,l)
        {
            int src;
            cin>>src;
            dfs(src);
        }

        int s=0;

        for(int r = 1 ; r<=n; r++)
        {
            if(d[r]==1)
                s++;
        }
        cout<<s<<endl;

    }

    return 0;


}

