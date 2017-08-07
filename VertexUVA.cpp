#define FOR(i,n) for(int i=0; i<n; i++)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back

#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define inf (1<<29)
#define ii64 long long
#define MM 1000

#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int n;
int d[MM];

void dfs(int src)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            d[u] = 1;
            dfs(u);
        }
    }
    //printf("finish %d at time %d\n",src, tim);
}

void inaccess(int src)
{
    CLR(d);

    dfs(src);

    int cccc = 0;
    for(int o=1; o<=n; o++)
    {

        if(d[o]==0)
        {
            cccc++;
        }

    }
    if(cccc)
    {
        cout<<cccc;
        for(int o=1; o<=n; o++)
        {

            if(d[o]==0)
            {
                printf(" %d",o);
            }


        }
    }
    else cout<<cccc;



}

int main()
{
//    freopen("in.txt", "r", stdin);

  //  freopen("out.txt", "w", stdout);

    while(cin>>n && n)
    {
        FOR(y,MM)
        adj[y].clear();

        int u;
        while(cin>>u && u)
        {
            int v;
            while(cin>>v && v)
            {
                adj[u].push_back(v);
            }


        }
        int tc;
        cin>>tc;
        FOR(k,tc)
        {
            int c;
            cin>>c;
            inaccess(c);
            printf("\n");
        }

    }

    return 0;


}
