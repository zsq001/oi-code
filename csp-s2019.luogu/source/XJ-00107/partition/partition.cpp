#include <bits/stdc++.h>
using namespace std;
long long temp,ss,ds,dt,a[100001],mint=pow(2,62),n,type;
int search(int k)
{
	for(int i=k;i<=n+1;i++)
	{
		ds+=a[i-1];
		if(ds>=ss)
		{
			
//			dt+=(a[i]*a[i]+2*(ds-a[i])*a[i]);
			
			dt+=(ds*ds-(ds-a[i-1])*(ds-a[i-1]));
//			if(dt>=mint) {dt-=ds*ds;return 0;};
			long long temp=ss;
			ss=ds;
			ds=0;
			if(i==n+1){if(dt<mint) mint=dt;}
			else {search(i+1);}
			ds=ss;
			ss=temp;
			dt-=(ds*ds-(ds-a[i-1])*(ds-a[i-1]));
			
//			dt-=(a[i]*a[i]+2*(ds-a[i])*a[i]);
			
		}
		ds-=a[i-1];
	}
	return 0;
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){ cout<<(a[1]*a[1])<<endl;return 0;}
	if(n==2){if(a[1]<=a[2])cout<<a[1]*a[1]+a[2]*a[2];else cout<<(a[1]+a[2])*(a[1]+a[2]);return 0;
	}
	ds=0;
	search(2);
	cout<<mint<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
