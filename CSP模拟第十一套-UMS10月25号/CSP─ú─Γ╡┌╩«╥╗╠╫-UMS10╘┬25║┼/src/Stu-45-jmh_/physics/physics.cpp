#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

struct node{
	int a,t;
}s[100050];
int n,v;
double s1,s2;

bool cmp(node a,node b){
	return a.a>b.a;
}

int_ main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&s[i].a,&s[i].t);
		s1+=v*s[i].t;
		s1+=((double)s[i].a/2)*1.0*s[i].t*s[i].t;
		v+=s[i].a*s[i].t;
	}
	sort(s+1,s+1+n,cmp);
	v=0;
	for(int i=1;i<=n;i++){
		s2+=v*s[i].t;
		s2+=((double)s[i].a/2)*1.0*s[i].t*s[i].t;
	    v+=s[i].a*s[i].t;
	}
	printf("%.1lf",s2-s1);
	return 0;
}
