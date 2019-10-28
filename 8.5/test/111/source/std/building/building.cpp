#include<bits/stdc++.h>
#define fi first
#define se second
#define FOR(a) for(int i=0;i<a;i++)
#define show(a) cout<<a<<endl;
#define show2(a,b) cout<<a<<" "<<b<<endl;
#define show3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> LP;
const ll inf=1e18;
const int N=100000+7;
const ll mod=1e3+3;

int l[N],r[N],belong[N],num,block;
int x,y,n,m;
vector<double> v[1005];
double k[N],mx[N];

void build()
{
	block=sqrt(n);
	num=n/block;
	if(n%block) num++;
	for(int i=1;i<=num;i++)
		l[i]=(i-1)*block+1,r[i]=i*block;
	r[num]=n;
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/block+1;
}
void update(int x,int y)
{
	double xx=x,yy=y;
	k[x]=yy/xx;
	mx[belong[x]]=0;
	v[belong[x]].clear();
	for(int i=l[belong[x]];i<=r[belong[x]];i++)
	{
		if(k[i]>mx[belong[x]])
		{
			mx[belong[x]]=k[i];
			v[belong[x]].push_back(k[i]);
		}
	}
}

int main()
{

	freopen("building.in", "r", stdin);
	freopen("building.out", "w", stdout);
	scanf("%d%d",&n,&m);
	build();
	while(m--)
	{
		scanf("%d%d",&x,&y);
		update(x,y);
		int ans=0;
		double tmp=0;
		for(int i=1;i<=num;i++)
		if(!v[i].empty())
		{
			ans+=v[i].end()-upper_bound(v[i].begin(),v[i].end(),tmp);
			tmp=max(tmp,mx[i]);
		}
		printf("%d\n",ans);
	}
}