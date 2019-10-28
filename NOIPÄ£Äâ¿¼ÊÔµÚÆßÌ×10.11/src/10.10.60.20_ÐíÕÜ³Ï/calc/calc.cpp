#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int e,r,cnt,q[300000],w[300000],n,ans;
char a[5000];
bool pd(int aa,int bb)
{
 int i,j;
 for(i=aa;i<=bb;i++)
 {
  if(a[i]==a[bb])bb--;
  else return false;
 }
 return true;
}
int main()
{
 int i,j;
 freopen("calc.in","r",stdin);
 freopen("calc.out","w",stdout);
 scanf("%s",a+1);
 n=strlen(a+1);
 for(i=1;i<=n;i++)
 {
  for(j=i;j<=n;j++)
  {
   if(pd(i,j)==true)q[++cnt]=i,w[cnt]=j;
  }
 }
 for(i=1;i<cnt;i++)
 {
  for(j=i+1;j<=cnt;j++)
  {
   e=w[i];r=q[j];
   if(w[i]<q[j])ans++;
  }
 }
 printf("%d",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
