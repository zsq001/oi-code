#include<cstdio>
int a[1000005],b[1000005],ans;
int main()
{
 int n,m,x,y;
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 scanf("%d%d%d%d",&n,&m,&x,&y);
 for(int i=1;i<=n;i++)
 scanf("%d",&a[i]);
 for(int j=1;j<=m;j++)
 scanf("%d",&b[j]);   
 int head=1;
 for(int i=1;i<=m&&head<=n;i++)
 {
  if(a[head]-x<=b[i]&&b[i]<=a[head]+y){ans++;head++;}
  else if(b[i]<a[head]-x)continue;
  else if(b[i]>a[head]+y){head++;i--;}
 }
 printf("%d",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
