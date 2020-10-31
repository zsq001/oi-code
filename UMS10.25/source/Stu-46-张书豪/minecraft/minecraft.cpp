#include <iostream>
#include <algorithm>
using namespace std;
int b,n,d,m;
namespace sub1
{
 int x[100005];
 void solve()
 {
  for(int i=1;i<=n;i++)
   cin>>x[i];
  sort(x+1,x+n+1);
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
   int tmp=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
   ans+=tmp-i;
  }
  cout<<ans<<endl;
 } 
}
namespace sub2
{
 struct point
 {
  int x,y;
 }p[100005];
 namespace task2
 {
  void solve()
  {
   int ans=0;
   for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
     if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)<=d)ans++;
   cout<<ans<<endl;
  }
 }
 void solve()
 {
  for(int i=1;i<=n;i++)
   cin>>p[i].x>>p[i].y;
  if(n<=100)sub2::task2::solve();
 }
}
namespace sub3
{
 struct point
 {
  int x,y,z;
 }p[100005];
 namespace task2
 {
  void solve()
  {
   long long ans=0;
   for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
     if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)+abs(p[i].z-p[j].z)<=d)ans++;
   cout<<ans<<endl;
  }
 }
 void solve()
 {
  for(int i=1;i<=n;i++)
   cin>>p[i].x>>p[i].y>>p[i].z;
  if(n<=100)sub3::task2::solve();
 }
}
int main()
{
 freopen("minecraft.in","r",stdin);
 freopen("minecraft.out","w",stdout);
 ios::sync_with_stdio(false);
 cin>>b>>n>>d>>m;
 if(b==1)sub1::solve();
 else if(b==2)sub2::solve();
 else sub3::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
