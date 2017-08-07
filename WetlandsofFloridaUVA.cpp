#define FOR(i,n) for(int i=0; i<n; i++)
#define Scan(a) scanf("%d",&a)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 110

#include<bits/stdc++.h>
using namespace std;

int d[MM][MM];
int ara[MM][MM];
vector<int>adj[MM];
int n,r=0,c=0;
int sx, sy, dx, dy;
int area = 0;

int move_x[]= {-1,-1,-1,1,1,1,0,0};
int move_y[]= {-1,1,0,1,-1,0,1,-1};

bool isValid(int x,int y)
{
    return x>=0 && x<r && y>=0 && y<c;
}

void dfs(int x, int y)
{
    // printf("%d %d\n", x, y);

    d[x][y] = 1;
    area++;
    for(int i=0; i<8; i++)
    {
        int xx = x + move_x[i];
        int yy = y + move_y[i];

        if(isValid(xx,yy) && ara[xx][yy]==1 && d[xx][yy]==0)
        {
            dfs(xx,yy);
        }
    }
}


int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);

    Scan(n);
    getchar();
    getchar();

    FOR(i,n)
    {
        r = 0;
        c = 0;
        int a, b;
        CLR(d);
        CLR(ara);
        FOR(y,MM)
        adj[y].clear();
        string str;
        while (1)
        {
            getline(cin, str);
            stringstream ss;
            ss<<str;
            if (str[0]>='0' && str[0]<='9')
            {
                ss>>a;
                ss>>b;
                a -= 1;
                b -= 1;
                break;
            }

            c = str.length();
            FOR(k,c)
            {
                if(str[k]=='L')
                    ara[r][k] = 2;
                else if(str[k]=='W')
                    ara[r][k] = 1;
            }
            r++;
        }

        while (1)
        {
            //printf("\n");
            area = 0;
            CLR(d);
            dfs(a,b);
            printf("%d\n", area);

            getline(cin, str);
            int l = str.length();
            if (l==0)
            {
                break;
            }
            stringstream ss;
            ss<<str;
            ss>>a;
            ss>>b;
            a -= 1;
            b -= 1;

        }
        if(i!=n-1)
            printf("\n");

    }


}
