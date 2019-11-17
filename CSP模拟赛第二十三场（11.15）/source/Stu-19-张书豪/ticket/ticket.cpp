#include <cstdio>
#include <algorithm>
#define MAXT 25000
using namespace std;
char s[35],res[35];
int tot,l,c;
void dfs(int d,int x,int cnt1,int cnt2)
{
 if(tot>=MAXT)return;
 if(d==l)
 {
  if(cnt1&&cnt2>=2)
  {
   puts(res);
   tot++;
  }
  return;
 }
 if(x==c)return;
 for(int i=x;i<c;i++)
 {
  res[d]=s[i];
  if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
   dfs(d+1,i+1,cnt1+1,cnt2);
  else
   dfs(d+1,i+1,cnt1,cnt2+1);
  if(tot>=MAXT)return;
 }
}
int main()
{
 freopen("ticket.in","r",stdin);
 freopen("ticket.out","w",stdout);
 scanf("%d%d",&l,&c);
 for(int i=0;i<c;i++)
  scanf("%s",s+i);
 sort(s,s+c);
 dfs(0,0,0,0);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
