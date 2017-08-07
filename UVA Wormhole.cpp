#include <bits/stdc++.h>
#define MM 2010
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 100000000

using namespace std;

int n, m;

struct edge
{
    int u;
    int v;
    int cost;

    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        cost = c;
    }

};



vector<edge> vec;


bool BF()
{
    int d[n+5];

    FOR(k,n+5)
    d[k] = inf;

    d[0] = 0;

    FOR(i, n-1)
    {
        FOR(k, m)
        {
            int u = vec[k].u;
            int v = vec[k].v;
            int cost = vec[k].cost;

            if(d[u] != inf)
            if(d[u] + cost < d[v])
                d[v] = d[u] + cost;

        }
    }

    bool NC = false;

    FOR(k, m)
        {
            int u = vec[k].u;
            int v = vec[k].v;
            int cost = vec[k].cost;

            if(d[u] + cost < d[v] )
             {
                 return true;
             }

        }
return false;



}


int main()
{
   //freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
   int tc;
   scan(tc);
   while(tc--)
   {

    vec.clear();
    scanf("%d %d", &n, &m);

    FOR(i,m)
    {
        int u, v, cos;
        scanf("%d %d %d", &u, &v, &cos);
        vec.pb(edge(u,v,cos));
    }
    puts(BF() ? "possible" : "not possible");
   }


return 0;
}



/*

4 5
0 1 2
1 2 1
0 2 5
0 3 4
2 3 9


*/
