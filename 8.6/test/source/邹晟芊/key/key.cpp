#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib> 
using namespace std;
char a[301000];
int b[300010],c[300010];
int cnt=0,ans=0;
int main()
{
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		b[i]=a[i]-'0';
	}
	for(int i=1;i<len;i++)
	{
		if(b[i]!=b[i-1])
		cnt++;
	}
	if(cnt+1>len/3*2)
	{
		cout<<"0";
		return 0;
	}
	if(len<=3)
	{
		if((b[1]==0&&b[2]==0&&b[0]==0)||(b[1]==1&&b[2]==1&&b[0]==1))
		{
			cout<<1<<endl<<1;
			exit(0);
		}
		if((b[0]==1&&b[1]==0&&b[2]==1)||(b[0]==0&&b[1]==1&&b[2]==0))
		{
			cout<<0;
			exit(0);
		}
		if((b[0]==1&&b[1]==1&&b[2]==0)||(b[0]==0&&b[1]==1&&b[2]==1))
		{
			cout<<0;
			exit(0);
		}
		if((b[0]==0&&b[1]==0&&b[2]==1)||(b[0]==1&&b[1]==0&&b[2]==0))
		{
			cout<<0;
			exit(0);
		}
	}
	for(int i=2;i<len-3;i++)
	{
		if(b[i-1]==b[i-2]&&b[i-1]!=b[i+1]&&b[i+1]==b[i+2])
		{
			b[i]=!b[i],b[i+1]=!b[i+1];
			ans++;
			c[i]++;
		}
	}
	int x=ans,i=0;
	cout<<ans<<endl;
	if(ans==0)
	return 0;
	while(x)
	{
		i++;
		if(c[i]!=0)
		{
			cout<<i+1<<" ";
			x--;
		}
	}
	return 0;
}
