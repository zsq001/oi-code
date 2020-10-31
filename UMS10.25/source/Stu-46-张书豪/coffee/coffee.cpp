#include <cstdio>
#include <cstring>
int a[100005],res[100005],q1[100005],q2[100005];
int main()
{
 freopen("coffee.in","r",stdin);
 freopen("coffee.out","w",stdout);
 int n,h,b,e;
 while(~scanf("%d%d%d%d",&n,&h,&b,&e))
 {
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  int l=0,r=0;
  memset(res,0,sizeof(res));
  for(int i=b;i<=e;i++)
  {
   while(l<r&&i-q1[l]>=h)
    l++;
   while(l<r&&a[i]<=q2[r-1])
    r--;
   q1[r]=i;
   q2[r++]=a[i];
   res[q1[l]]++;
  }
  for(int i=b;i<=e;i++)
   printf("%d ",res[i]);
  puts("");
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
