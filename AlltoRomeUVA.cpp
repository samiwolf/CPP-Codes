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
#define MM 100

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[MM];
int dist[MM], parent[MM];
map<string, int>toInt;
map<int, string>toStr;

void bfs (int src)
{
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    parent[src]=-1;
    while(!Q.empty())
    {
        int s=Q.front();
        Q.pop();
        for(int i=0; i<adj[s].size(); i++)
        {
            if(dist[adj[s][i]]==-1)
            {
                parent[adj[s][i]]=s;
                dist[adj[s][i]]=dist[s]+1;
                Q.push(adj[s][i]);
            }
        }
    }

}
void printPath(int dest)
{
    if(parent[dest]==-1)
    {
        cout<<toStr[dest][0];
        return;
    }


    printPath(parent[dest]);
    cout<<toStr[dest][0];

    // printPath(parent[src]);
}
void shortest(int src, int dest)
{
    SET(parent);
    SET(dist);
    bfs(src);
    printPath(dest);
    cout<<endl;


}


int main()
{

//    freopen("in.txt", "r", stdin);

  //  freopen("out.txt", "w", stdout);

    int t, c=0;

    cin>>t;

    FOR(k,t)
    {
        if(c++>0)
            printf("\n");
        int n, number = 1, query;
        FOR(k,MM)
        adj[k].clear();
        toInt.clear();
        toStr.clear();

        cin>>n>>query;

        FOR(i,n)
        {
            string s1, s2;
            cin>>s1>>s2;
            if(!toInt[s1])
            {
                toInt[s1]= number++;
                toStr[number-1] = s1;
            }
            if(!toInt[s2])
            {
                toInt[s2]= number++;
                toStr[number-1]=s2;
            }

            adj[toInt[s1]].pb(toInt[s2]);

            adj[toInt[s2]].pb(toInt[s1]);
        }


        FOR(i,query)
        {
            string src, dest;
            cin>>src>>dest;
            shortest(toInt[src],toInt[dest]);

        }


    }




}

