#define MM 20005
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[MM];
int V;
int indegree[MM];
bool visited[MM];

void all_possible_topsort_util(vector<int> &res)
{
    bool flag=false;

    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0 && !visited[i])
        {
            visited[i]=true;
            for(int j=0;j<adj[i].size();j++)
                indegree[adj[i][j]]--;
            res.push_back(i);

            all_possible_topsort_util(res);

            visited[i]=false;
            res.erase(res.end()-1);
            for(int j=0;j<adj[i].size();j++)
                indegree[adj[i][j]]++;

            flag=true;

        }
    }

    if(!flag)
    {
        for(int i=0;i<res.size();i++)
        {
            int c =res[i];
            if(i==0)
            cout<<c;
            else
                cout<<" "<<c;
        }
        cout<<endl;
    }
}

void all_possible_topsort()
{
    vector<int> res;

    memset(visited,0,sizeof visited);

    all_possible_topsort_util(res);

    memset(indegree,0,sizeof indegree);
}



int main()
{
    freopen("in.txt", "r", stdin);
    int u,v, m;
    scanf("%d %d",&V, &m);
    while(m--)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        //adj[v].push_back(u);
        indegree[v]++;
    }

   all_possible_topsort();
    return 0;


}
