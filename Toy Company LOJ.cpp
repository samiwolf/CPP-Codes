#include <bits/stdc++.h>
#define MM 26
#define FOR(i,n) for(int i=0; i<n; i++)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define scan(a) scanf("%d",&a);
#define inf 1e17

using namespace std;

int s1,s2,s3,d1,d2,d3;
int ara[MM][MM][MM];
int d[MM][MM][MM];


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

data update( data d)
{
    if(d.x==26) d.x=0;
    if(d.y==26) d.y=0;
    if(d.z==26) d.z=0;

    if(d.x==-1) d.x=25;
    if(d.y==-1) d.y=25;
    if(d.z==-1) d.z=25;

    return data(d.x, d.y, d.z);


}



int move_x[]= {1,-1,0,0,0,0};
int move_y[]= {0,0,1,-1,0,0};
int move_z[]= {0,0,0,0,1,-1};




bool isvalid(int x,int y,int z, int n, int m, int l)
{
    return x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<l;
}





void bfs(data src)
{
    queue<data>q;
    int xx = src.x;
    int yy = src.y;
    int zz = src.z;

    d[xx][yy][zz] = 0;
    q.push(src);

    while(!q.empty())
    {
        data u = q.front();
        q.pop();
        int xxx =u.x;
        int yyy = u.y;
        int zzz = u.z;

        for(int i = 0; i < 6; i++)
        {
            int xcc = xxx + move_x[i];
            int ycc = yyy + move_y[i];
            int zcc = zzz + move_z[i];

            data temp = update(data(xcc,ycc,zcc));

            int xc = temp.x;
            int yc = temp.y;
            int zc = temp.z;

            if(d[xc][yc][zc]==-1 && ara[xc][yc][zc]!= -1)
            {
                d[xc][yc][zc] = d[xxx][yyy][zzz] + 1;
                q.push(temp);
            }

        }
    }
}


int main()
{
  //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    string source, desti;
    string str1, str2, str3;
    int tc;
    scan(tc);
    getchar();
    FOR(tt,tc)

    {

        SET(d);
        CLR(ara);

        cin>>source >> desti;
        s1 = source[0]-97;
        s2 = source[1]-97;
        s3 = source[2]-97;


        d1 = desti[0]-97;
        d2 = desti[1]-97;
        d3 = desti[2]-97;

        int m;
        scan(m);

        while(m--)
        {
            cin>>str1>>str2>>str3;
           // cout<<str1<<str2<<str3<<endl;

            int l1= str1.length();
            int l2= str2.length();
            int l3= str3.length();

            FOR(i,l1)
            FOR(j,l2)
            FOR(k,l3)
            {
                int i1 = str1[i] - 97;
                int j1 = str2[j] - 97;
                int k1 = str3[k] - 97;
              // printf("%c %c %c\n",i1+97,j1+97,k1+97);
                ara[i1][j1][k1] = -1;
            }
        }

        if(ara[s1][s2][s3]!=-1)
        bfs(data(s1,s2,s3));

    if(d[d1][d2][d3]!=-1)
     printf("Case %d: %d\n",tt+1, d[d1][d2][d3]);
else printf("Case %d: -1\n",tt+1);

    }





    return 0;


}
