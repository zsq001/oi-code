#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n;
int a[500001];
int f[500001];
long long ans;
int findd(int k)
{
	if(f[k]==k)return k;
	return f[k]=findd(f[k]);
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int t;
	read(n);
	read(t);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		f[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]<a[i-1]){
			if(a[i-1]<a[i+1]||a[i+1]==0)f[i]=findd(i-1);
			else f[i]=findd(i+1);
		}
	}
	int p=a[1];
	for(int i=1;i<=n;++i)
	{
		if(findd(i)==findd(i+1))p+=a[i+1];
		else ans+=p*p,p=a[i+1];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
