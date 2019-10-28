#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n;
struct node
{
	int a,t;
}s[100005];
ll v;
double x1,x2;
bool cmp(node a,node b){return a.a>b.a;}
int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(s[i].a),read(s[i].t);
		x1+=(double)(v*s[i].t*1.);
		v+=s[i].a*s[i].t;
	}
	sort(s+1,s+n+1,cmp);
	v=0;
	for(int i=1;i<=n;++i)
	{
		x2+=(double)(v*s[i].t*1.);
		v+=s[i].a*s[i].t;
	}
	printf("%.1lf",x2-x1);
	return 0;
}
