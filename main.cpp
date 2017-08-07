#include <bits/stdc++.h>

using namespace std;
//vector<string> adj;
int parent[1000];
map< int,int> name;
map<int,int> rev;
vector<int> adj[1000];
int ttl, cnt=1, cs=1;        ;
void shortest_path_util(int src,int dist[])
{
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;

//    cout<<src<<endl;
    parent[src]=src;
    while(!Q.empty())
    {
        int s=Q.front();
        Q.pop();
        for(int i=0; i<adj[s].size(); i++)
        {
            if(dist[adj[s][i]]==-1)
            {
                // cout<<adj[s][i]<<endl;

                parent[adj[s][i]]=s;
                dist[adj[s][i]]=dist[s]+1;
                Q.push(adj[s][i]);
            }
        }
    }
}


void shortest_path_print(int dest)
{
    if(parent[dest]==dest)
        return;
    shortest_path_print(parent[dest]);

//    string a = rev[dest];
    //  string b = rev[parent[dest]];


    //cout<<b<<" "<<a<<endl;
}

void shortest_path(int src)
{
    int dist[100];
    memset(dist,-1,sizeof dist);
    memset(parent,-1,sizeof parent);

    shortest_path_util(src,dist);

    int ans=0;
    for(int i = 1; i < cnt; i++)
    {
        if(  dist[i]>ttl || dist[i]==-1 )
            ans++;
    }

    cout<<"Case "<<cs++<<": "<<ans<<" nodes not reachable from node "<<rev[src]<<" with TTL = "<<ttl<<"."<<endl;

    ///for(int i=0;i<total;i++)
    /// if(dist[i]==-1)
    ///  shortest_path_util(i,dist);
}

int main()
{
   // freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
    int s;
    int n;
    int c = 1;
    int s1,s2,d1,d2;
    while(cin>>n && n)
    {

        for(int i=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(!name[s1])
            {
                name[s1] = cnt++;
                rev[cnt-1] = s1;
            }

            if(!name[s2])
            {
                name[s2]= cnt++;
                rev[cnt-1] = s2;
            }

            adj[name[s1]].push_back(name[s2]);

            adj[name[s2]].push_back(name[s1]);


        }

        while(cin>>d1>>d2 && (d1 !=0 || d2!=0))
        {
            if(!name[d1])
            {
                cout<<"Case "<<cs++<<": "<<cnt-1<<" nodes not reachable from node "<<d1<<" with TTL = "<<ttl<<"."<<endl;
            }
            else
            {
                s = name[d1];
                ttl = d2;
                shortest_path(s);

            }





        }
        //if(c++>1)
        //  puts("");
        //shortest_path(s);
        name.clear();
        //rev.clear();
        for(int i=0; i<1000; i++)
            adj[i].clear();
        cnt = 1;
    }
    return 0;
}
