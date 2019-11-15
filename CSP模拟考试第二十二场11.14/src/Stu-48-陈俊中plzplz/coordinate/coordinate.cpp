#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;

ll n;
const ll p=1e9+7;
struct node
{
	ll ma[3][3];
}ans;

node work(node x,node y)
{
	node ret;
	ret.ma[1][1]=ret.ma[1][2]=ret.ma[2][1]=ret.ma[2][2]=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				ret.ma[i][j]+=x.ma[i][k]*y.ma[k][j];
			}
			ret.ma[i][j]%=p;
		}
	return ret;	
				
	
}

void cal()
{
	node tmp;
	n-=2;
	tmp.ma[1][1]=tmp.ma[0][2]=0;
	tmp.ma[1][2]=1;
	tmp.ma[2][1]=1;
	tmp.ma[2][2]=2;
	while(n)
	{
		if(n&1) ans=work(tmp,ans);
		tmp=work(tmp,tmp);
		n>>=1;
	}
	printf("%lld",ans.ma[2][1]%p);
	
}

//1->3 2->7 3->17 4->34+7=41 f[i]=f[i-1]*2+f[i-2]
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%lld",&n);
	if(n==1)
	{
		puts("3"); 
		return 0;
	}
	if(n==2)
	{
		puts("7");
		return 0;
	}
	ans.ma[1][1]=3;
	ans.ma[2][1]=7;
	cal();
//	printf("%lld",);
	return 0;
}
