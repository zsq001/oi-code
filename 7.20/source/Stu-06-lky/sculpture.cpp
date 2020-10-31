#include<cstdio>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int tot,a[10086];

void print(int l,int r)
{
	for(int i=l;i<=r;i++){
		tot+=a[i];
	}
	printf("%d\n",tot);
	tot=0;
}

void boom(int l,int r){for(int i=l;i<=r;i++)a[i]=sqrt(a[i]);}

int main()
{
	int n,m,x,l,r;
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1)print(l,r);
		if(x==0)boom(l,r);
	}
	return 0;
}
