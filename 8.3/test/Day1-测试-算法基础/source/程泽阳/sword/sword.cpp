#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000010],num;
bool CMP(int x,int y)
{
	return x<y;
}
void print()
{
	for(int i=1;i<=num;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int n,m,k,i,j;
	int x,s;
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&x,&s);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&j);
		a[++num]=j;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&j);
		a[++num]=j;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&j);
		a[++num]=j;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&j);
		a[++num]=j;
	}
	sort(a+1,a+1+num);
	int ss=k;
	for(i=2;i<=m;i++)
	{
		ss=ss*k;
	}
	printf("%d",ss);
//	print();
	printf("%d",a[ss]);
	return 0;
}
