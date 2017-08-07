#include<bits/stdc++.h>
using namespace std;






vector<int> adj[1000002];

int main()
{
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d:",i);
        for(int j=0; j<adj[i].size(); j++)
        {
            printf(" %d",adj[i][j]);
        }
        puts("");
    }
    return 0;


}
