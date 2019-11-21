#include <cstdio>
#include <iostream>
#define MOD 998244353
using namespace std;
int a[105][2005],n,m;
namespace sub1
{
 int res[5],ans;
 bool check()
 {
  bool flag=true;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    flag&=(a[i][j]<2);
  return flag;
 }
 void dfs(int d)
 {
  if(d==n+1)
  {
   int sum=0;
   for(int i=1;i<=m;i++)
    sum+=res[i];
   if(!sum)return;
   sum/=2;
   bool flag=true;
   for(int i=1;i<=m;i++)
    flag&=(res[i]<=sum);
   ans+=flag;
   return;
  }
  for(int i=1;i<=m;i++)
   for(int j=0;j<=a[d][i];j++)
   {
    res[i]+=j;
    dfs(d+1);
    res[i]-=j;
   }
 }
 void solve()
 {
  dfs(1);
  cout<<ans<<endl;
 }
}
namespace sub2
{
 long long f[15][15][15][15];
 bool check()
 {
  if(n>10||m>3)return false;
  bool flag=true;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    flag&=(a[i][j]<2);
  return flag;
 }
 void solve()
 {
  f[0][0][0][0]=1;
  for(int i=0;i<n;i++)
   for(int j=1;j<=m;i++)
    for(int k=0;k<n;k++)
     for(int l=0;l<n;l++)
      for(int p=0;p<n;p++)
       for(int q=0;q<=a[i][j];q++)
        f[i+1][k+q*(j==1)][l+q*(j==2)][p+q*(j==3)]+=f[i][k][l][p];
  long long ans=0;
  for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    for(int k=0;k<=n;k++)
     if(i+j+k)
     {
      int sum=(i+j+k)/2;
      if(i<=sum&&j<=sum&&k<=sum)ans=(ans+f[n][i][j][k])%MOD;
     }
  cout<<ans<<endl;
 }
}
int main()
{
 freopen("meal.in","r",stdin);
 freopen("meal.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   cin>>a[i][j];
 if(sub1::check())sub1::solve();
 else if(sub2::check())sub2::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
