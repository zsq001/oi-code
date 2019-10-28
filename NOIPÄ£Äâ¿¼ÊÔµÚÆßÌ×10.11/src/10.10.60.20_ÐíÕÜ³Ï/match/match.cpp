#include<stdio.h>
#include<algorithm>
using namespace std;


long long n,m,x,y,a[200000],c[200000],b[300000],i,j,d[200000],f[200000],s[200000];
long long w,t,q,k,ans;
int main()
{
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 scanf("%d %d %d %d",&n,&m,&x,&y);
 for(i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  b[++j]=a[i]-x;b[++j]=a[i]+y+1;
 }
 for(i=1;i<=m;i++)
 {
  scanf("%d",&c[i]);
  b[++j]=c[i];
 }
 sort(b+1,b+j+1);
 q=0;w=0;
 for(i=1;i<=j;i++)
 {
  if(b[i]!=b[i-1])b[++q]=b[i];
 }
 j=q;
 q=0;
 for(i=1;i<=j;i++)
 {
  if(a[q+1]-x==b[i])d[i]++,q++,i--;
 }
 for(i=1;i<=j;i++)
 {
  if(c[w+1]==b[i])s[i]++,w++,i--;
 }
 q=0;
 for(i=1;i<=j;i++)
 {
  if(a[q+1]+y+1==b[i])f[i]--,q++,i--;
 }
 w=j+1;
 q=0;t=0;k=0;
 for(i=1;i<=w;i++)
 {
  if(f[i]<0&&t>0){
  	if(f[i]+t>0)f[i]=0,t=t+f[i];
  	else f[i]=f[i]+t,t=0;
  }
  q=q+d[i]+f[i];
  ans+=min(q,s[i]);
  t+=min(q,s[i]);
  x=min(q,s[i]);
  q=q-x;

 }
 printf("%d",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
