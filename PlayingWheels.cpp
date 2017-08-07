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
#define MM 10

#include<bits/stdc++.h>
using namespace std;

struct data
{
    int w;
    int x;
    int y;
    int z;

    data(int a, int b, int c, int d)
    {
        w= a;
        x= b;
        y= c;
        z= d;
    }
};

vector<data> adj[MM][MM][MM][MM];
int dis[MM][MM][MM][MM];
char arr[MM][MM][MM][MM];

int move_w[]= {1,-1,0,0,0,0,0,0};
int move_x[]= {0,0,1,-1,0,0,0,0};
int move_y[]= {0,0,0,0,1,-1,0,0};
int move_z[]= {0,0,0,0,0,0,1,-1};

int wow,xox,yoy,zoz;


data update (data a)
{
    if(a.w==-1) a.w = 9;
    if(a.x==-1) a.x = 9;
    if(a.y==-1) a.y = 9;
    if(a.z==-1) a.z = 9;

    if(a.w==10) a.w = 0;
    if(a.x==10) a.x = 0;
    if(a.y==10) a.y = 0;
    if(a.z==10) a.z = 0;

    return a;
}

void bfs(data src)
{
    queue<data>q;

    int ww = src.w;
    int xx = src.x;
    int yy = src.y;
    int zz = src.z;

    //  cout<<ww<<" "<<xx<<" "<<yy<<" "<<zz<<" "<<endl;

    arr[ww][xx][yy][zz] = 1;
    dis[ww][xx][yy][zz] = 0;
    q.push(src);

    while(!q.empty())
    {
        //cout<<"1"<<endl;
        data u = q.front();
        q.pop();

        for(int i = 0; i < 8; i++)
        {

            int wc = u.w + move_w[i];
            int xc = u.x + move_x[i];
            int yc = u.y + move_y[i];
            int zc = u.z + move_z[i];

            data temp = data(wc,xc,yc,zc);
            temp = update(temp);

            wc = temp.w;
            xc = temp.x;
            yc = temp.y;
            zc = temp.z;

            if(arr[wc][xc][yc][zc] == 0)
            {
                arr[wc][xc][yc][zc] = 1;
                dis[wc][xc][yc][zc] = dis[u.w][u.x][u.y][u.z] + 1;
                q.push(data(wc,xc,yc,zc));
            }
        }
    }
}


int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {

        int  dw, dx, dy, dz;


        memset(arr, 0, sizeof(arr));
        cin>>wow>>xox>>yoy>>zoz;
        cin>>dw>>dx>>dy>>dz;

        int t;
        cin>>t;

        FOR(i,t)
        {
            int fw,fx,fy,fz;
            cin>>fw>>fx>>fy>>fz;
            arr[fw][fx][fy][fz] = -1;
        }

        bfs(data(wow,xox,yoy,zoz));

        if(arr[dw][dx][dy][dz]==1)
            cout<<dis[dw][dx][dy][dz]<<endl;
        else
            cout<<"-1"<<endl;

    }
    return 0;
}
