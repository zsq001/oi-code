#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[2][10002][100002];
int main()
{
	int i1=0;
	double ans=0;
	while(1)
	{
		i1++;
		gets(a[0][i1]);
		if(a[0][i1][0]=='E')
		break;	
		
	}
	int i2=0;
	while(1)
	{
		i2++;
		gets(a[1][i2]);
		if(a[1][i2][0]=='E')
		break;
		int len=strlen(a[1][i2]);
		for(int j=0,k=0;j<len;j++)
		if(a[1][i2][j]=='<')
		{
            a[1][i2][j]='/';
			k=j;
			while(k--)
			{
				if((a[1][i2][k]>='a'&&a[1][i2][k]<='z')||a[1][i2][k]==' '||a[1][i2][k]=='.')
				{
					a[1][i2][k]='/';
					break;
				}
			}
		}
	}
	double t;
	cin>>t;
	for(int j=0;j<i1;j++)
	{
		int w=-1;
		int len2=strlen(a[1][j]);
		for(int i=0;i<len2;i++)
		{
			if((a[1][j][i]>='a'&&a[1][j][i]<='z')||a[1][j][i]==' '||a[1][j][i]=='.')
			{
				++w;
				if(a[1][j][i]==a[0][j][w])
				ans++;
			}
		}
	}
	t/=60.000;
	ans/=t;
	int qwq;
	//cout<<ans;
	qwq=ans;
	if(ans-qwq>=0.45)
	qwq++;
	cout<<qwq;
	return 0;
}
