#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int res[5];
bool dfs(int d,int maxa,int v)
{
 if(d==3)
 {
  res[d]=v;
  return true;
 }
 for(int i=maxa;i>=res[d-1];i--)
  if(v%i==0)
  {
   res[d]=i;
   bool flag=dfs(d+1,sqrt(v/i),v/i);
   if(flag)return true;
   res[d]=0;
  }
 return false;
}
int main()
{
 freopen("box.in","r",stdin);
 freopen("box.out","w",stdout);
 int v;
 cin>>v;
 for(int i=1;i<=v;i++)
  if(i*i*i>v)
  {
   dfs(1,i-1,v);
   break;
  }
 long long ans=0;
 for(int i=1;i<=3;i++)
  for(int j=i+1;j<=3;j++)
   ans+=2*res[i]*res[j];
 cout<<ans<<endl;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
