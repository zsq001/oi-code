#include <cstdio>
#include <iostream>
using namespace std;
int f[500005],n;
char s[500005];
namespace sub1
{
 void solve()
 {
  int ans=0;
  for(int k=1;k<=n;k++)
  {
   int res=0;
   for(int i=1;i<=k;i++)
   {
    int sum=0;
    for(int j=i;j<=k;j++)
    {
     sum+=((s[j]=='(')?1:-1);
     if(sum==0)res++;
     if(sum<0)break;
    }
   }
   //cout<<res<<endl;
   ans^=res*k;
  }
  cout<<ans<<endl;
 }
}
namespace sub2
{
 int tmp[500005],res[500005];
 void solve()
 {
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
   int sum=0;
   for(int j=i;j<=n;j++)
   {
    sum+=((s[j]=='(')?1:-1);
    if(sum==0)tmp[j]++;
    if(sum<0)break;
   }
  }
  for(int i=1;i<=n;i++)
   res[i]=res[i-1]+tmp[i];
  for(int i=1;i<=n;i++)
   ans^=res[i]*i;
  cout<<ans<<endl;
 }
}
int main()
{
 freopen("brackets.in","r",stdin);
 freopen("brackets.out","w",stdout);
 ios::sync_with_stdio(false);
 cin>>n;
 cin>>(s+1);
 for(int i=2;i<=n;i++)
  cin>>f[i];
 if(n<=200)sub1::solve();
 else if(n<=2000)sub2::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
