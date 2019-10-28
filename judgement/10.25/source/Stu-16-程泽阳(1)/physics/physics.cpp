#include<cstdio>
#include<algorithm>
using namespace std;
double num,ans,Vt;
struct node{
	double a;
	int t;
	long long aa;
}e[10010];

bool CMP(node x,node y)
{
	return x.aa>y.aa;
}

int main()
{
	int n,i,j;
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%d",&e[i].a,&e[i].t);
		e[i].aa=e[i].a*e[i].t;
		num+=Vt*e[i].t+0.5*(e[i].a*e[i].t*e[i].t);
		Vt=Vt+e[i].a*e[i].t;
	}
	sort(e+1,e+1+n,CMP);
	Vt=0.0;
	for(i=1;i<=n;i++)
	{
		ans+=Vt*e[i].t+0.5*(e[i].a*e[i].t*e[i].t);
		Vt=Vt+e[i].a*e[i].t;
	}
	printf("%.1lf",ans-num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
