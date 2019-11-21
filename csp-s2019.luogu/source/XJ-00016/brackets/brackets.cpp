#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int n,pow[500010];
long long ans[500010];
bool map[500010];
char c;//c[500010];
long long yihuo(long long a,long long b)
{
	long long ans=0,base=1;
	while(a!=0||b!=0)
	{
		if(a%2!=b%2)ans+=base;
		a/=2;b/=2;
		base*=2;
	}
	return ans;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if(c=='(')map[i]=1;
		if(c==')')map[i]=0;
	}
//for(long long i=1;i<=n;i++)cout<<b[i];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&pow[i]);
	}
	for(int i=2;i<=n;i++)
	{
		int cnt=0,st=i;//,ans=0,sh=0;
		while(st>=1)
		{
			
			if(map[st]==0)cnt++;
			if(map[st]==1)
			{
				if(cnt>0)
				{
					cnt--;ans[i]++;
				}
			}
			st/=2;
		//	cout<<"nb";
		}
	//	cout<<"ojbk";
	}
//	cout<<"ok";
	
	for(long long st=2;st<=n;st++)ans[st]*=pow[st];
	long long anss=0;
	for(int st=2;st<=n;st++)anss=yihuo(anss,ans[st]);
	cout<<anss;
	fclose(stdin);fclose(stdout);
	return 0;
}
