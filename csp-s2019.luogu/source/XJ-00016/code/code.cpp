#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
long long k,la,l,r,mi,cnt=0;
long long n;
bool a[1000000],si=0;
long long fas(long long a,long long b)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)ans*=base;
		base*=base;
		b/=2;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
//	cout<<fas(n,k);
//	cout<<n<<k;
	la=fas(2,n);
//	cout<<n<<k<<endl<<la<<endl;
	l=1,r=la,a[0]=0;
	while(l<r)
	{
		cnt++;//cout<<cnt<<endl;
		mi=l+(r-l)/2;
		if(mi>=k)
		{
			//si=1
			if(a[cnt-1])si=!si;
			if(!si)a[cnt]=0;
			else a[cnt]=1;
//			cout<<cnt<<"<"<<a[cnt-1]<<"<"<<a[cnt]<<endl;
			r=mi;
		}
		else
		{
			if(a[cnt-1])si=!si;
			if(!si)a[cnt]=1;
			else a[cnt]=0;
//			cout<<cnt<<">"<<a[cnt-1]<<">"<<a[cnt]<<endl;
			l=mi+1;
		}
	}
	for(int i=1;i<=cnt;i++)
	cout<<a[i];
	fclose(stdin);fclose(stdout);
	return 0;
}
