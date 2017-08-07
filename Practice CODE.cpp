#include <bits/stdc++.h>
#define MM 1005
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 100000000

using namespace std;



vector<int>adj[MM];


void traverse(int src)
{
    if(adj[src].size() == 0)
        return;
    int next  = adj[src][0];
    adj[src].erase(adj[src].begin());
    traverse(next);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    scan(cas);

    FOR(tc, cas)
    {


        int child;
        scan(child);
        while(child--)
        {
            int n;
             scan(n);
             while(n--)
             {
                 int u, v;
                 scan(u);
                 scan(v);
                 if(!mp[make_pair(u,v)])
                 {
                     mp[make_pair(u,v)] = 1;
                     adj[u].pb(v);
                 }
             }
        }

        FOR(g, 1000)
        {
            sort(adj[g].begin(), adj[g].end());
        }

        traverse(0);
        string possible = "YES";
        FOR(h, 1000)
        if(adj[h].size() > 0)
        {
            possible = "NO";
            break;
        }
     cout<<"Case "<<tc+1<<": "<<possible<<endl;
    }

}
