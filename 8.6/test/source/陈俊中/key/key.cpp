#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 300010
using namespace std;

int len,val=1;
char a[maxn];
int ans[maxn];

template<class T> inline void read(T &x)
{
    x=0;
    register char c=getchar();
    register bool f=0;
    while (!isdigit(c)) f ^=c=='-',c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}

template <class T> inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar('0'+x%10);
}

void calval()
{
	for(register int i=1;i<=len;i++)
	{
		 if(a[i]!=a[i-1]&&i!=1)val++;
	}
}

int main()
{
	freopen("key.ins","r",stdin);
	freopen("key.out","w",stdout);
	int cnt=0;
	scanf("%s",a+1);
	len=strlen(a+1);
	calval();
	if(val>=(len/3)*2) 
	{
		printf("0");
		return 0;
	}
	for(register int i=1;i<=len-2;i+=3)
	{
		if(a[i]=='0'&&a[i+1]=='0'&&a[i+2]=='1')
		{
			ans[++cnt]=i+1;
			a[i+1]='1';
			a[i+2]='0';
		}
		if(a[i]=='0'&&a[i+1]=='1'&&a[i+2]=='1')
		{
			ans[++cnt]=i;
			a[i]='1';
			a[i+1]='0';
		}
		if(a[i]=='1'&&a[i+1]=='1'&&a[i+2]=='0')
		{
			ans[++cnt]=i+1;
			a[i+1]='0';
			a[i+2]='1';
		}
		if(a[i]=='1'&&a[i+1]=='0'&&a[i+2]=='0')
		{
			ans[++cnt]=i;
			a[i]='0';
			a[i+1]='1';
		}
		if(a[i]=='1'&&a[i+1]=='1'&&a[i+2]=='1')
		{
			if(i==1) ans[++cnt]=1;
			else if(a[i-1]=='1')
			{
				ans[++cnt]=i;
				a[i]='0';
				a[i+1]='0';
			}
			else 
			{
				ans[++cnt]=i+1;
				a[i+1]='0';
				a[i+2]='1';
			}
		}
		if(a[i]=='0'&&a[i+1]=='0'&&a[i+2]=='0')
		{
			if(i==1) ans[++cnt]=1;
			else if(a[i-1]=='0')
			{
				ans[++cnt]=i;
				a[i]='1';
				a[i+1]='0';
			}
			else 
			{
				ans[++cnt]=i+1;
				a[i+1]='1';
				a[i+2]='0';
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
