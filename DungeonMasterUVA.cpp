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
#define MM 32

#include<bits/stdc++.h>
using namespace std;

struct data
{
    int x;
    int y;
    int z;

    data(int a, int b, int c)
    {
        x= a;
        y= b;
        z= c;
    }
};

vector<data> adj[MM][MM][MM];
int dis[MM][MM][MM];
char arr[MM][MM][MM];

int move_x[]= {1,-1,0,0,0,0};
int move_y[]= {0,0,1,-1,0,0};
int move_z[]= {0,0,0,0,1,-1};




bool isvalid(int x,int y,int z, int n, int m, int l)
{
    return x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<l;
}


void create(int n, int m, int l)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int p = 0; p<l; p++)
            {
                for(int k=0; k<6; k++)
                {
                    if(isvalid(i+move_x[k],j+move_y[k], p+move_z[k], n, m, l))
                    {

                        adj[i][j][p].push_back(data( i+move_x[k],j+move_y[k],p+move_z[k]));
                    }
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
    int zz = src.z;



    dis[xx][yy][zz] = 0;
    q.push(src);

    while(!q.empty())
    {
        data u = q.front();
        q.pop();
        int xxx =u.x;
        int yyy = u.y;
        int zzz = u.z;

        for(int i = 0; i < adj[xxx][yyy][zzz].size(); i++)
        {
            data d = adj[xxx][yyy][zzz][i];
            int xc = d.x;
            int yc = d.y;
            int zc = d.z;

            if(dis[xc][yc][zc]==-1 && arr[xc][yc][zc]!= '#')
            {
                dis[xc][yc][zc] = dis[xxx][yyy][zzz] + 1;
                q.push(d);
            }

        }
    }
}


int main()
{
  // freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);

    int l, r, c;
    int sx, sy, sz, dx, dy, dz;

    while(cin>>l>>r>>c && l && r && c)
    {

    memset(dis, -1, sizeof(dis));
    memset(arr, 0, sizeof(arr));
    FOR(i,32)
    FOR(j,32)
    FOR(k,32)
    adj[i][j][k].clear();


    getchar();
    FOR(k,l)
    {


        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                scanf("%c", &arr[i][j][k]);

                if(arr[i][j][k]=='S')
                {
                    sx = i;
                    sy = j;
                    sz = k;
                }
                if(arr[i][j][k]=='E')
                {
                    dx = i;
                    dy = j;
                    dz = k;
                }
            }
            getchar();
        }
        getchar();

    }

    create(r,c,l);
    bfs(data(sx,sy,sz));
    if(dis[dx][dy][dz]!=-1)
    printf("Escaped in %d minute(s).\n", dis[dx][dy][dz]);
    else printf("Trapped!\n");

    }





    return 0;


}
