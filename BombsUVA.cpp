#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define inf (1<<29)
#define ii64 long long
#define MM 1000

struct data
{
    int x;
    int y;

    data(int a, int b)
    {
        x= a;
        y= b;
    }
};

vector<data> adj[MM][MM];
int ara[MM][MM];
int l[MM][MM];

int move_x[]= {1,-1,0,0};
int move_y[]= {0,0,1,-1};




bool isvalid(int x,int y, int n, int m)
{
    return x>=0&&x<n&&y>=0&&y<m;
}


void create(int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<4; k++)
            {
                if(isvalid(i+move_x[k],j+move_y[k], n, m))
                {

                    adj[i][j].push_back(data( i+move_x[k],j+move_y[k]));
                }
            }
        }
    }

}




void bfs(data src)
{
    queue<data>q;
    int xx = src.x;
    int yy = src.y;



    l[xx][yy] = 0;
    q.push(src);

    while(!q.empty())
    {
        data u = q.front();
        q.pop();
        int xxx =u.x;
        int yyy = u.y;

        for(int i = 0; i < adj[xxx][yyy].size(); i++)

        {
            data d = adj[xxx][yyy][i];
            int xc = d.x;
            int yc= d.y;

            if(l[xc][yc]==-1 && ara[xc][yc]!= -1)
            {
                l[xc][yc] = l[xxx][yyy] + 1;
                q.push(d);
            }

        }
    }
}



int main()
{
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int r, c;
    while(cin>>r>>c && r && c)
    {
        memset(ara, 0, sizeof(ara));
        memset(l, -1, sizeof(l));

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                adj[i][j].clear();
            }
        }

        create(r,c);

        int nr;
        cin>>nr;

        for(int i=0; i<nr; i++)
        {
            int row, rowindex;
            cin>>row>>rowindex;
            for(int j=0; j<rowindex; j++)
            {
                int colindex;
                cin>>colindex;
                ara[row][colindex] = -1;
            }
        }

        int sx, sy, dx, dy;
        cin>>sx>>sy;
        cin>>dx>>dy;
        bfs(data(sx,sy));
        printf("%d\n", l[dx][dy]);

    }
}
