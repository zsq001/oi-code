#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1100001];
int b[1000010];
int main()
{
	cin>>a;
	int n=strlen(a),ju=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]=='0')
			b[i]=1;
		else if(a[i-1]=='1')
			b[i]=-1;
		if(a[i-1]=='0')
			ju=0;
	}
	if(ju==-1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		ans+=b[i];
		if(ans<=-1)
			ans=0;
		else	
			sum=max(sum,ans);
	}
	cout<<sum<<endl;
	return 0;
}
