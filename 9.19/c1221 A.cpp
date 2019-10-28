#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[110];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		memset(a,0,sizeof(a));
		int m,k=0;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			if(k==1)
			continue;
			if(x>2048)
			continue;
			else if(x==2048)
			{
				cout<<"YES"<<endl;
				k=1;
				continue;
			}
			else if(x==1024)
			{
				a[1]++;
			}
			else if(x==512)
			a[2]++;
			if(x==256)
			a[3]++;
			if(x==128)
			a[4]++;
			if(x==64)
			a[5]++;
			if(x==32)
			a[6]++;
			if(x==16)
			a[7]++;
			if(x==8)
			a[8]++;
			if(x==4)
			a[9]++;
			if(x==2)
			a[10]++;
			if(x==1)
			a[11]++;
		}
		for(int i=11;i>1;i--)
		while(a[i]>1)
		{
			a[i]-=2;
			a[i-1]++;
		}
		if(k!=1)
		{
			if(a[1]>1)
		cout<<"YES"<<endl;
		else 
		cout<<"NO"<<endl;
		}
	}
	return 0;
}
