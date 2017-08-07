#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 10

#include<bits/stdc++.h>
using namespace std;

int d[MM][MM];
int ara[MM][MM];
int r,c;
int sx, sy, dx, dy;

bool isValid(int x, int y)
{
    return x>=0&&x<r&&y>=0&&y<c;
}

int move_x[]= {0,0,-1};
int move_y[]= {1,-1,0};

struct data
{
    int x;
    int y;
    data(int a, int b)
    {
        x=a;
        y=b;
    }
};
queue<data>result;

void dfs(int x, int y)
{
    ara[x][y] = 1;

    for(int i=0; i<3; i++)
    {
        int xx = x+move_x[i];
        int yy = y+move_y[i];

        if(ara[xx][yy]==0 && isValid(xx,yy))
        {
            result.push(data(move_x[i], move_y[i]));
            dfs(xx, yy);
        }
    }


}


int main()
{
  //  freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int tc;
    cin>>tc;
    FOR(pp,tc)
    {

        cin>>r>>c;
        getchar();
        FOR(i,r)
        {
            FOR(j,c)
            {
                char ch;

                scanf("%c",&ch);
                if(ch=='I' || ch=='E' ||ch=='H' ||ch=='O'|| ch=='V' || ch=='A')
                {
                    ara[i][j]=0;
                }
                else if(ch=='@')
                {
                    ara[i][j]=0;
                    sx = i;
                    sy = j;
                }
                else if(ch=='#')
                {
                    ara[i][j]=0;
                    dx = i;
                    dy = j;
                }
                else ara[i][j] = 1;

                //printf("%c",ch);
            }
            getchar();
        }


        dfs(sx, sy);
       // printf("%d %d\n",sx, sy);
      //  printf("case - %d dest visit %d", pp+1, ara[dx][dy]);
        int c = 0;
        while(!result.empty())
        {
            data d = result.front();
            result.pop();
            if(c++>0)
                printf(" ");
            if(d.x==0 && d.y==1) printf("right");
            else if(d.x==0 && d.y==-1) printf("left");
            else if(d.x==-1 && d.y==0) printf("forth");
        }
        printf("\n");



    }


}

/*FOR(i,r)
    {
        FOR(j,c)
        {
            printf("%d",ara[i][j]);
        }
        printf("\n");
    }*/
