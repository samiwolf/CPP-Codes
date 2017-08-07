#include <bits/stdc++.h>
#define MM 2005
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 100000000

using namespace std;



vector<int>adj[MM], temp[MM];
int num = 0;
int cn[MM], in[MM], out[MM];
bool d[MM], valid[MM];
stack<int> tops;


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
    tops.push(src);
}

void scc(int src)
{
    cn[src] = num;
    d[src] = 1;
    for(int i=0; i<temp[src].size(); i++)
    {
        int u =  temp[src][i];


        if(d[u]==0)
        {
            d[u] = 1;
            scc(u);
        }
    }
}

int main()
{
   freopen("in.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
    int cas;
    scan(cas);

    FOR(tc, cas)
    {
        num = 0;
        FOR(jjj,MM)
        {
            adj[jjj].clear();
            temp[jjj].clear();
            cn[jjj] = -1;
            d[jjj] = 0;
            in[jjj] = 0;
            out[jjj] = 0;
            valid[jjj] = 0;
        }


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
                valid[u]=1;

                adj[u].pb(v);
                temp[v].pb(u);

            }
        }

        FOR(i, 1000)
        {
            if(d[i]==0 && valid[i])
                dfs(i);
        }


        CLR(d);


        while(!tops.empty())
        {
            int n = tops.top();
            tops.pop();
            if(d[n]==0)
            {
                scc(n);
                num++;

            }


        }


        FOR(u, 1000)
        {
            if(valid[u])
            {
                FOR(uu, adj[u].size())
                {
                    int v = adj[u][uu];
                    if(cn[u]!=cn[v])
                    {
                        out[ cn[u]]++;
                        in[cn[v]]++;
                    }
                }

            }

        }

        bool flag = false;

        if(num==1 && adj[0].size() > 0)
            flag = true;

        else
        {

            int indegreeonenode = 0;
            int outdegreeonenode = 0;
            int zerodegree = 0;

            int cnzero = cn[0];

            bool ze = false;

            if(out[cnzero]==1 && in[cnzero]==0)
            {
                ze = true;
            }

            FOR(i, num)
            {
                if(out[i]==1 && in[i]==0)
                    outdegreeonenode++;

                if(in[i]==1 && out[i]==0)
                    indegreeonenode++;

                 if(out[i]==1 && in[i]==1)
                    zerodegree++;
            }

            if(indegreeonenode==1 && outdegreeonenode==1 && ze && zerodegree== num - 2)
                flag = true;



        }


        if(flag)  cout<<"Case "<<tc+1<<": "<<"YES"<<endl;
        else  cout<<"Case "<<tc+1<<": "<<"NO"<<endl;



    }

}

