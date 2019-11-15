#include <cstdio>
#include <ctime>
int t1[1005],t2[1005],c1[1005],c2[1005];
int read()
{
 int num=0;
 char ch=getchar();
 while(ch<'0'||ch>'9')
  ch=getchar();
 while(ch>='0'&&ch<='9')
  num=num*10+ch-'0',ch=getchar();
 return num;
}
int main()
{
 freopen("matrix.in","r",stdin);
 freopen("matrix.out","w",stdout);
 int n=read(),m=read(),q=read();
 for(int i=1;i<=q;i++)
 {
  int x=read(),y=read(),z=read();
  if(x==1)t1[y]=i,c1[y]=z;
  else t2[y]=i,c2[y]=z;
 }
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   if(t1[i]>t2[j])printf("%d ",c1[i]);
   else printf("%d ",c2[j]);
  puts("");
 }
 //printf("Time: %g s\n",(double)clock()/CLOCKS_PER_SEC);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
