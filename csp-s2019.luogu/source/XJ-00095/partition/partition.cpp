#include <cstdio>
#include <iostream>
#define INF 5e18
using namespace std;
int n,type;
long long a[500005],sum[500005];
namespace sub1
{
 long long ans;
 void dfs(int d,int ls,int sum,long long res)
 {
  if(res>=ans)return;
  if(d==n+1)
  {
   if(ls>sum)return;
   ans=min(ans,res+sum*sum);
   return;
  }
  if(sum>=ls)dfs(d+1,sum,a[d],res+sum*sum);
  dfs(d+1,ls,sum+a[d],res);
 }
 void solve()
 {
  ans=INF;
  dfs(1,0,0,0);
  cout<<ans<<endl;
 }
}
namespace sub2
{
 long long f[405][405];
 bool check(int x,int y,int z)
 {
  return sum[x]-sum[y-1]>=sum[y-1]-sum[z-1];
 }
 void solve()
 {
  for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    f[i][j]=INF;
  //f[0][0]=0;
  for(int i=1;i<=n;i++)
   f[i][1]=sum[i]*sum[i];
  for(int i=1;i<=n;i++)
   for(int j=1;j<=i;j++)
    for(int k=1;k<=j;k++)
     if(check(i,j,k))
      f[i][j]=min(f[i][j],f[j-1][k]+(sum[i]-sum[j-1])*(sum[i]-sum[j-1]));
  long long ans=INF;
  for(int i=0;i<=n;i++)
   ans=min(ans,f[n][i]);
  cout<<ans<<endl;
 }
}
namespace sub3
{
 long long f[5005];
 int p[5005];
 bool check(int x,int y,int z)
 {
  return sum[x]-sum[y-1]>=sum[y-1]-sum[z-1];
 }
 void solve()
 {
  for(int i=1;i<=n;i++)
   f[i]=INF;
  f[1]=a[1]*a[1],p[1]=1;
  for(int i=2;i<=n;i++)
   for(int j=p[i-1];j<=i;j++)
    if(check(i,j,p[i-1]))
    {
     if(f[i]>f[j-1]+(sum[i]-sum[j-1])*(sum[i]-sum[j-1]))
     {
      f[i]=f[j-1]+(sum[i]-sum[j-1])*(sum[i]-sum[j-1]);
      p[i]=j;
     }
    }
  cout<<f[n]<<endl;
 }
}
int main()
{
 freopen("partition.in","r",stdin);
 freopen("partition.out","w",stdout);
 cin>>n>>type;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  sum[i]=sum[i-1]+a[i];
 }
 if(n<=10)sub1::solve();
 else if(n<=400)sub2::solve();
 else if(n<=5000)sub3::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
