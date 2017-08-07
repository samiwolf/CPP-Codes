#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
int  dp[65][65][65];
string a,b,c;
int solve(int i,int j,int k)
{
    if(k==c.size())
        return 1;
    if(i==a.size() && j==b.size())
        return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int cnt = 0;
    if(i<a.size())cnt = ((cnt%MOD) + (solve(i+1,j,k)%MOD))%MOD;
    if(j<b.size())cnt = ((cnt%MOD) + (solve(i,j+1,k)%MOD))%MOD;
    if(i<a.size() && j<b.size())cnt = ((cnt%MOD) + (solve(i+1,j+1,k)%MOD))%MOD;
    if(a[i]==c[k]) cnt = ((cnt%MOD) + (solve(i+1,j,k+1)%MOD))%MOD;
    if(b[j]==c[k])cnt = ((cnt%MOD) + (solve(i,j+1,k+1)%MOD))%MOD;
    return dp[i][j][k] = cnt;
}
int main ()
{
    memset(dp,-1,sizeof(dp));
    cin>>a>>b>>c;
    cout<<a<<b<<c<<endl;
    cout<<solve(0,0,0);
    return 0;
}
