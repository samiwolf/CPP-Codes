#define MM 105

#include<bits/stdc++.h>
using namespace std;

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
int l[MM][MM];
char arr[MM][MM];
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

            if(l[xc][yc]==-1 && arr[xc][yc]!= '#')
            {


                l[xc][yc] = l[xxx][yyy] + 1;
                q.push(d);
            }

        }
    }
}


int main()
{
    freopen("input.txt","r", stdin);

    memset(l, -1, sizeof(l));
    memset(arr, 0, sizeof(arr));
    int n,u,v, m;
    scanf("%d %d",&n, &m);
    getchar();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }


    if( (arr[n-1][m-1]!='#') && (arr[0][0]!='#'))
    {

        create(n,m);

        bfs(data(0,0));

        printf("%d\n", l[n-1][m-1]);
    }

    else
    {
        printf("-1\n");
    }
    return 0;


}
