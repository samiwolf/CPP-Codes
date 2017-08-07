#define MM 20005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
vector<int> temp[MM];
stack<int> tops;
int compn = 1;
int d[MM], start[MM], finish[MM], tim = 0, cn[MM];

void dfs(int src)
{
    d[src] = 1;
    ++tim;
    start[src] = tim;
    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            d[u] = 1;
            cn[u] = compn;
            dfs(u);
        }
    }
    ++tim;

    finish[src] = tim;
    cn[src] = compn;
    tops.push(src);
}

void ddffss(int src)
{
    //printf("%d ",src);
    d[src] = 1;
    for(int i=0; i<temp[src].size(); i++)

    {
        // printf("%d when %d\n",d[2], src);
        int u =  temp[src][i];


        if(d[u]==0)
        {
            d[u] = 1;
            ddffss(u);
        }
    }
}


int main()
{
    memset(d, 0, sizeof(d));
    memset(cn, 0, sizeof(cn));
    int n,u,v, m, cnt = 0;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        temp[v].push_back(u);
    }



    for(int i=0; i<n; i++)
    {
        if(d[i]==0)
        {
            dfs(i);
            ++compn;
        }

    }


    memset(d, 0, sizeof(d));


    while(!tops.empty())
    {
        int n = tops.top();
        tops.pop();
        if(d[n]==0)
        {
            cnt++;
            ddffss(n);
//            printf("\n");
        }

    }

    printf("%d\n", cnt);
    return 0;


}
