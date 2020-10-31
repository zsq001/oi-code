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
bool fl;
int p,n;long long ans;
int f[2001],g[2001];char s[2001];
bool pppp(int x,int y)
{
	while(x<y)
	{
		if(s[x]!=s[y])return false;
		++x;
		--y;
	}
	return true;
}
int main()
{
		freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		p=i;
		fl=true;
		while(p<=n)
		{
			if(s[p]!=s[i])fl=false;
			if(fl){
				++f[i];
				++g[p];
			}
			else if(pppp(i,p)){
				++f[i];
				++g[p];
			}
			++p;
		}
	}
	for(int i=1;i<n;++i)
	 for(int j=i+1;j<=n;++j)
	 {
	 	ans+=g[i]*f[j];
	 }
	 printf("%lld",ans);
	 fclose(stdin);
	fclose(stdout);
	return 0;
}
