#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
typedef int int_;
#define int long long
#define maxn 500050
using namespace std;
int maxx,ans=1,fymax,x,y,f;
double k[maxn],mmax[maxn],fmax;
deque<double> d;
int_ main()
{
	int n,m;
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f=1;
	mmax[1]=k[1];
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		k[x]=y/x;
		d.push_back(k[1]);
		for(int i=2;i<=n;i++)
		{
			if(k[i]>d.back())
			{
				d.push_back(k[i]); 
			}
		}
		if(d.front()==0)
		{
			d.pop_front();
		}
		printf("%lld\n",d.size());
		d.clear();
		/*mmax[x]=max(mmax[x-1],k[x-1]);
		if(x>f&&k[x]>d.back())
		{
			d.push_back(k[x]);
			f=x;
			fmax=mmax;
			mmax=k[x];
		}
		else if(x<f&&k[x]>fmax)
		{
			it=x;
			d.insert(it,k[x]); 
		}
		printf("%d\n",d.size());*/
	}
	return 0;
}
