#include<cstdio>
int n,m,q;
int h[10005],h1[10005],z[10005],z1[10005];
void frein()
{
 freopen("matrix.in","r",stdin);
 freopen("matrix.out","w",stdout);
}
void freout()
{
 fclose(stdin);
 fclose(stdout);
}
int main()
{
	frein();
 scanf("%d%d%d",&n,&m,&q);
 int v=1;
 while(v<=q)
 {
  int x,y,l;
  scanf("%d%d%d",&x,&y,&l);
  if(x==1)
  {
   z[y]=l;
   z1[y]=v;
  } 
  else if(x==2)
  {
   h[y]=l;
   h1[y]=v;
  } 
  v++;
 }
 for( int i=1;i<=n;i++)
 {
 for(int j=1;j<=m;j++)
 {
  if(h1[j]>z1[i])printf("%d ",h[j]);
  else if(h1[j]<z1[i])printf("%d ",z[i]);
  else printf("0 ");  
 }
 printf("\n");
}
freout();
return 0;
}
