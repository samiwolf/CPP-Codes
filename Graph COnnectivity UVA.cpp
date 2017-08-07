#define FOR(i,n) for(int i=0; i<n; i++)
#define Scan(a) scanf("%d",&a)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 210

#include<bits/stdc++.h>
using namespace std;

int d[MM];
vector<int>adj[MM];
int n,r,c;
int sx, sy, dx, dy;

void dfs(int src)
{
    d[src] = 1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            d[u] = 1;
            dfs(u);
        }
    }
}


int main()
{
    freopen("in.txt", "r", stdin);
 freopen("out.txt", "w", stdout);

    Scan(n);
    getchar();
    getchar();

    FOR(i,n)
    {
        CLR(d);
        FOR(y,MM)
        adj[y].clear();


        int m;
        char cc;
        scanf("%c", &cc);
        getchar();
        m = cc - 'A' + 1;

        string str;
        while (1)
        {
            getline(cin, str);

            if (str.length()==0 )
                break;
            int a, b;
            a = str[0] - 'A';
            b = str[1] - 'A';
            adj[a].pb(b);
            adj[b].pb(a);
        }

        int cn = 0;
        FOR(o,m)
        {

            if(d[o]==0)
            {
                dfs(o);
                cn++;
            }

        }
        printf("%d\n", cn);
        if(i!=n-1) printf("\n");

    }


}
