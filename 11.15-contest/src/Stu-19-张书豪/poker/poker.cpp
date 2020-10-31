#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;
int a[5];
int main()
{
 freopen("poker.in","r",stdin);
 freopen("poker.out","w",stdout);
 int n,m;
 cin>>n>>m;
 q.push(m);
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  q.push(x);
 }
 long long ans=0;
 while(1)
 {
  bool flag=false;
  for(int i=0;i<3;i++)
  {
   flag|=q.empty();
   if(flag)break;
   else a[i]=q.top(),q.pop();
  }
  if(flag)break;
  ans+=a[2];
  for(int i=0;i<3;i++)
  {
   a[i]-=a[2];
   if(a[i])q.push(a[i]);
  }
 }
 cout<<ans<<endl;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
