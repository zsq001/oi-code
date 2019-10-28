#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int l,r;
 bool operator<(const node&a)const
 {
  return l<a.l||(l==a.l&&r<a.r);
 }
 node(int x=0,int y=-1)
 {
  l=x,r=y;
 }
}a[4000005];
char s[2005],s1[4005];
int cnt;
long long ans;
int main()
{
 freopen("calc.in","r",stdin);
 freopen("calc.out","w",stdout);
 cin>>(s1+1);
 int len=strlen(s1+1);
 s[1]='#';
 for(int i=1;i<=len;i++)
 {
  s[2*i]=s1[i];
  s[2*i+1]='#';
 }
 len=2*len+1;
 for(int i=1;i<=len;i++)
  for(int j=0;i-j>0&&i+j<=len;j++)
  {
   if(s[i-j]!=s[i+j])break;
   if(s[i-j]!='#')a[++cnt]=node(i-j,i+j);
  }
 sort(a+1,a+cnt+1);
 for(int i=1;i<=cnt;i++)
 {
  int pos=lower_bound(a+1,a+cnt+1,node(a[i].r+1))-a;
  ans+=cnt-pos+1;
 }
 cout<<ans<<endl;
 //cout<<"Time: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
 return 0;
}
