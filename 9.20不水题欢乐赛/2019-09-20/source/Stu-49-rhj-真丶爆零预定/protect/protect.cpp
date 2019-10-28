#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double inf=99999999.9999;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n;
struct Point
{
	int x,y;
}p[10];
bool cmp(Point a,Point b){return a.x<b.x;}
double k,b,ans=0;
bool flag=1;
double calc(int x1,int y1,int x2,int y2){return (x1-x2)*(x1-x2)*1.+(y1-y2)*(y1-y2)*1.;}
void dfs(int id,double lef,double rig,double sum)
{
	if(id>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(lef>0&&rig>0)
		dfs(id+1,rig-min(lef,rig),sqrt(calc(p[id+1].x,p[id+1].y,p[id+2].x,p[id+2].y)),sum+min(lef,rig)*min(lef,rig));
	dfs(id+1,rig,sqrt(calc(p[id+1].x,p[id+1].y,p[id+2].x,p[id+2].y)),sum);
}
int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
		read(p[i].x),read(p[i].y);
	if(n==2)
	{
		printf("%.2lf",calc(p[1].x,p[1].y,p[2].x,p[2].y));
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	k=(p[1].y-p[2].y)*1./(p[1].x-p[2].x)*1.,b=p[1].y*1.-k*1.*p[1].x;
	for(int i=3;i<=n;++i)
		if(k*p[i].x*1.+b!=p[i].y*1.) flag=0;
	if(flag) dfs(1,inf,sqrt(calc(p[1].x,p[1].y,p[2].x,p[2].y)),0);
	printf("%.2lf",ans);
	return 0;
}
