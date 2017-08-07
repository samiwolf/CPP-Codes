#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0; i<n; i++)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define inf (1<<29)
#define ii64 long long
#define MM 3000

vector<int> adj[MM];
int d[MM], day[MM];

void bfs(int src)
{
    queue<int> q;
    d[src] = 0;

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
                d[u] = d[x] + 1;
                day[d[u]]++;
                q.push(u);
            }
        }

    }

}
int main()
{
        freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int E;
    cin>>E;
    FOR(i,E){
     int nof;
     cin>>nof;
     FOR(j,nof)
     {
         int f;
         cin>>f;
         adj[i].pb(f);
     }

    }

    int tc;
    cin>>tc;
    FOR(i,tc)
    {
     SET(d);
     CLR(day);
     int src;
     cin>>src;
     bfs(src);

     int mx = 0;
     int ind = -1;

     FOR(k,E)
     {
         if(day[k]>mx)
         {
             mx = day[k];
             ind = k;
         }

     }
     if(mx!=0)
     printf("%d %d\n", mx, ind);
     else printf("0\n");
    }


}
