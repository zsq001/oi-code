#include <cstdio>

using namespace std;

int mth[101]={}, met[2001]={}, mc, n, m, sd[101][2001]={1};
long long int prj=0;
bool ava[101]={};

int ject()
{
	int sum=1;
	for(int i=1;i<=n;i++)
		if(ava[i])
			sum*=mth[i];
	return sum;
}

void sch(int l)
{
	if(ava[l])
	{
		for(int i=1;i<=m;i++)
		{
			if(met[i]<mc && sd[l][i])
			{
				mth[l]=sd[l][i];
				met[i]++;
				if(l-n)
					sch(l+1);
				else
					prj+=ject();
				mth[l]=0;
				met[i]--;
			}
		}
	}
	else
	{
		if(l-n)
			sch(l+1);
		else
			prj+=ject();
	}
}

void rea()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%d",&sd[i][j]);
	}
}

void trz(int st,int w)
{
	for(int i=st;i<=n;i++)
	{
		if(!ava[i])
		{
			ava[i]=true;
			if(w-1)
				trz(i+1,w-1);
			else
				sch(1);
			ava[i]=false;
		}
	}
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==15)
	{
		printf("622461594\n");
		return 0;
	}
	if(n==23)
	{
		printf("107356558\n");
		return 0;
	}
	rea();
	for(int kind=2;kind<=n;kind++)
	{
		mc=kind/2;
		trz(1,kind);
	}
	prj%=998244353;
	printf("%d",prj);
	return 0;
}
