#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n;
int a[1000][1000];
int x[11];
int y[11];
double maxx;
double ju(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	int x1,y1;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i]);
		read(y[i]);
		a[x[i]][y[i]]=1;
	}
	if(n==3){
		for(int i=1;i<=n;++i)
		 for(int j=1;j<=n;++j)
		 {
		 	if(i!=j&&ju(i,j)>maxx)maxx=ju(i,j),x1=i,y1=j;
		 }
		 int u;
		 if(x1==1&&y1==2)u=3;
		 else if(x1==1&&y1==3)u=2;
		 else if(x1==2&&y1==3)u=1;
		 double m=max(ju(x1,u),ju(y1,u));
		 double mm=ju(x1,y1)-m;
		 printf("%.2lf",mm*mm+m*m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
