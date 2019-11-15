#include <cstdio>
#include <cstring>
#include <iostream>
#define MOD 1000000007
using namespace std;
int n;
namespace sub4
{
 long long f[1000005];
 void solve()
 {
  f[0]=1,f[1]=3;
  for(int i=2;i<=n;i++)
   f[i]=(2*f[i-1]+f[i-2])%MOD;
  cout<<f[n]<<endl;
 }
}
namespace sub5
{
 struct mat
 {
  long long a[5][5];
  mat()
  {
   memset(a,0,sizeof(a));
  }
 };
 mat operator*(mat a,mat b)
 {
  mat ans;
  for(int k=1;k<=2;k++)
   for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
     ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
  return ans;
 }
 mat fpow(int x)
 {
  mat tmp,ans;
  tmp.a[1][1]=2,tmp.a[1][2]=tmp.a[2][1]=1;
  ans.a[1][1]=3,ans.a[1][2]=1;
  while(x)
  {
   if(x&1)ans=ans*tmp;
   tmp=tmp*tmp;
   x>>=1;
  }
  return ans;
 }
 void solve()
 {
  cout<<fpow(n-1).a[1][1]<<endl;
 }
}
int main()
{
 freopen("coordinate.in","r",stdin);
 freopen("coordinate.out","w",stdout);
 cin>>n;
 if(n<=1000000)sub4::solve();
 else sub5::solve();
 return 0;
}
