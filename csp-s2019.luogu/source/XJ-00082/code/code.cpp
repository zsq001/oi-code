#include<bits/stdc++.h>
using namespace std;
int code(int,int);
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	long k;
	cin>>n>>k;
	code(n,k);
	fclose(stdin);fclose(stdout);
	return 0;
}
int  code(int n,int k)
{
	if(n==0) return 0;
	if(k<=pow(2,n-1)-1)
	{
		cout<<"0";
	}
	else
	{
		cout<<"1";
		k=pow(2,n)-k-1;
	}
	return code(n-1,k);
}
