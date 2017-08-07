#include <bits/stdc++.h>

using namespace std;
//vector<string> adj;
int parent[1000];
map< string,int> name;
map<int,string> rev;
vector<int> adj[1000];
int d, cnt=1;        ;
void shortest_path_util(int src,int dist[])
{
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    parent[src]=src;
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


void shortest_path_print(int dest)
{
    if(parent[dest]==dest)
        return;
    shortest_path_print(parent[dest]);

    string a = rev[dest];
    string b = rev[parent[dest]];


    cout<<b<<" "<<a<<endl;
}

void shortest_path(int src)
{
    int dist[1000];
    memset(dist,-1,sizeof dist);
    memset(parent,-1,sizeof parent);

    shortest_path_util(src,dist);

    if(dist[d]==-1)
        cout<<"No route"<<endl;
    else  shortest_path_print(d);


    ///for(int i=0;i<total;i++)
    /// if(dist[i]==-1)
    ///  shortest_path_util(i,dist);
}

int main()
{
  //  freopen("in.txt", "r", stdin);
   //  freopen("out.txt", "w", stdout);

    int n;
    int c = 1;
    string s1,s2,d1,d2;
    while(cin>>n)
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
        cin>>d1>>d2;
        if(!name[d1])
        {
            name[d1] = cnt++;
            rev[cnt-1] = d1;
        }
        if(!name[d2])
        {
            name[d2]= cnt++;
            rev[cnt-1] = d2;
        }
        int s = name[d1];
        d = name[d2];

        if(c++>1)
            puts("");
        shortest_path(s);
        name.clear();
        rev.clear();
        for(int i=0; i<1000;i++)
        adj[i].clear();
        cnt = 1;
    }
    return 0;
}

