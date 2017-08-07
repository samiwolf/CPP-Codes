#define FOR(i,n) for(int i=0; i<n; i++)
#define Scan(a) scanf("%d",&a)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 30

#include<bits/stdc++.h>
using namespace std;

int d[MM], start[MM], finish[MM];
vector<int>adj[MM];
stack<int> tops;
int tim = 0;
void dfs(int src)
{
    d[src] = 1;
    start[src] = ++tim;
    for(int i=0; i<adj[src].size(); i++)
    {
        int u =  adj[src][i];

        if(d[u]==0)
        {
            dfs(u);
        }
    }
    finish[src] = ++tim;
    tops.push(src);
}


int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt",  "w", stdout);
         int valid[MM];
         CLR(valid);
         CLR(d);
         CLR(start);
         CLR(finish);

         FOR(i,MM)
         adj[i].clear();

        string str;
        while (1)
        {
            getline(cin, str);

            if (str[0]=='#')
            {
                break;
            }

            int c = str.length();
            FOR(k,c-1)
            {
                int a = str[k] - 65;
                int b = str[k+1] - 65;

                valid[a] = 1;
                valid[b] = 1;

                adj[a].pb(b);
               // adj[b].pb(a);
            }
        }

        FOR(i,MM)
        {
            if(d[i]==0 && valid[i]==1)
            {
                dfs(i);
            }
        }

        while(!tops.empty())
        {
            int n = tops.top();
            tops.pop();
            printf("%c", n + 65);
        }




    }


