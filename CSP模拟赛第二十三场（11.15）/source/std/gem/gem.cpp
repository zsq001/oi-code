#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,m,w[1000010],x[2100000],y[2100000],a[2100000],b[2100000],c[2100000],p;
long long f[2100000];
inline void down(int i,int k)
{
	if(x[i])
	  {
	   x[i<<1]=1;
	   y[i<<1]=y[i];
	   f[i<<1]=(L)y[i]*k>>1;
	   x[i<<1|1]=1;
	   y[i<<1|1]=y[i];
	   f[i<<1|1]=(L)y[i]*k>>1;
	   x[i]=0;
	  }
}
inline long long sum(int i,int j,int k,int l,int r)
{
	if(l<=j && k<=r)
	  return f[i];
	else
	  {
	   L p=0;
	   down(i,k-j+1);
	   if(l<=(j+k>>1))
	     p+=sum(i<<1,j,j+k>>1,l,r);
	   if(r>(j+k>>1))
	     p+=sum(i<<1|1,(j+k>>1)+1,k,l,r);
	   return p;
	  }
}
inline void amend(int i,int j,int k,int l,int r,int p)
{
	if(l<=j && k<=r)
	  {
	   x[i]=1;
	   y[i]=p;
	   f[i]=(L)p*(k-j+1);
	  }
	else
	  {
	   down(i,k-j+1);
	   if(l<=(j+k>>1))
	     amend(i<<1,j,j+k>>1,l,r,p);
	   if(r>(j+k>>1))
	     amend(i<<1|1,(j+k>>1)+1,k,l,r,p);
	   f[i]=f[i<<1]+f[i<<1|1];
	  }
}
inline void down2(int i,int k)
{
	if(a[i])
	  {
	   a[i<<1]=1;
	   b[i<<1]=b[i];
	   c[i<<1]=c[i];
	   a[i<<1|1]=1;
	   b[i<<1|1]=b[i]+(c[i]*k>>1);
	   c[i<<1|1]=c[i];
	   a[i]=0;
	  }
}
inline int ask(int i,int j,int k,int p)
{
	if(j==k)
	  return b[i];
	else
	  {
	   down2(i,k-j+1);
	   if(p<=(j+k>>1))
	     return ask(i<<1,j,j+k>>1,p);
	   else
	     return ask(i<<1|1,(j+k>>1)+1,k,p);
	  }
}
inline void amend(int i,int j,int k,int l,int r,int p,int q)
{
	if(l<=j && k<=r)
	  {
	   a[i]=1;
	   b[i]=p;
	   c[i]=q;
	  }
	else
	  {
	   down2(i,k-j+1);
	   if(l<=(j+k>>1))
	     {
	      amend(i<<1,j,j+k>>1,l,r,p,q);
	      p+=q*((j+k>>1)+1-l);
	      l=(j+k>>1)+1;
		 }
	   if(r>(j+k>>1))
	     amend(i<<1|1,(j+k>>1)+1,k,l,r,p,q);
	  }
}
int main()
{
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(p=1;p<n;p<<=1);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&w[i]);
	   amend(1,1,p,i,i,w[i],0);
	  }
	for(i=2;i<=n;i++)
	  f[p+i-1]=max(w[i]-w[i-1],0);
	for(i=p-1;i>0;i--)
	  f[i]=f[i<<1]+f[i<<1|1];
	while(m--)
	  {
	   scanf("%d",&i);
	   if(i==1)
	     {
		  scanf("%d%d",&i,&j);
		  printf("%lld\n",i==j?0:sum(1,1,p,i+1,j));
		 }
	   else
	     {
		  scanf("%d%d%d%d",&i,&j,&k,&l);
		  amend(1,1,p,i,j,k,l);
		  if(i<j)
		    amend(1,1,p,i+1,j,max(l,0));
		  if(i>1)
		    amend(1,1,p,i,i,max(k-ask(1,1,p,i-1),0));
		  if(j<n)
		    amend(1,1,p,j+1,j+1,max(ask(1,1,p,j+1)-(k+(j-i)*l),0));
		 }
	  }
	return 0;
}

