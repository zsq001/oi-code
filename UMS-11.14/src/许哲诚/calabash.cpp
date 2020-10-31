#include<stdio.h>

int dd[500000],n,m,x,y,z,g[10000],e,i,cnt,hh[10000],h,t;
bool d[100000];
double l[10000];
struct node
{
 int v,z,next;
}b[10000];
void add(int aa,int bb,int cc)
{
 b[++cnt].v=bb;
 b[cnt].next=hh[aa];
 b[cnt].z=cc;
 hh[aa]=cnt;
}
void spfa(int q)
{
 
 for(i=1;i<=n;i++)
  l[i]=70000000;
 g[q]=1;
 l[q]=0;
 while(1)
 {
  if(h>t)break;
  for(i=hh[q];i;i=b[i].next)
  {
   e=b[i].v;
   if((b[i].z+l[q]*g[q])/(g[q]+1)<l[e]){
   	l[e]=(b[i].z+l[q]*g[q])/(g[q]+1);
   	g[e]=g[q]+1;
   	if(d[e])continue;
   	d[e]=true;
   	dd[++t]=e;
   } 
  }
  d[q]=false;
   q=dd[++h];
 }
}
int main()
{
 freopen("calabash.in","r",stdin);
 freopen("calabash.out","w",stdout);
 scanf("%I64d %I64d",&n,&m);
 for(i=1;i<=m;i++)
 {
  scanf("%I64d %I64d %I64d",&x,&y,&z);
  z=z*1000;
  add(x,y,z);
 }
 spfa(1);
 l[n]=int(l[n]);
 l[n]=l[n]/1000;
 printf("%.3lf",l[n]);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
