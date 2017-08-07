#include <bits/stdc++.h>
#define MM 10010
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 999999999

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

int d[MM];

vector<edge> vec;


void BF(int src)
{
    FOR(k,n)
    d[k] = inf;

    d[src] = 0;

    FOR(i, n-1)
    {

        FOR(k, vec.size())
        {
            int u = vec[k].u;
            int v = vec[k].v;
            int cost = vec[k].cost;

            if(d[u] + cost < d[v])
                d[v] = d[u] + cost;


        }


    }

    bool NC = false;

    FOR(k, vec.size())
        {
            int u = vec[k].u;
            int v = vec[k].v;
            int cost = vec[k].cost;

            if(d[u] + cost < d[v])
               NC = true;


        }

    if(NC)
        printf("Has Neg Cyc\n");
    else{
    FOR(i,n)
    {
        printf("distance of %d is %d\n ", i, d[i]);
    }
    }



}


int main()
{

    scanf("%d %d", &n, &m);

    FOR(i,m)
    {
        int u, v, cos;
        scanf("%d %d %d", &u, &v, &cos);
        vec.pb(edge(u,v,cos));
    }
    int src;
    scanf("%d", &src);
    BF(src);



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
