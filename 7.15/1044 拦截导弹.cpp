#include<iostream>
#define mmm 10000
int a[mmm],dp1[mmm],dp2[mmm];
using namespace std;
int main()
{
	int iin,n=0,ans1=0,ans2=0;
	while(cin>>iin)
		a[n++]=iin;
	for(int i=0; i<n; i++)
	{
		dp1[i]=1;
		dp2[i]=1;
		for(int j=0; j<i; j++)
		{
			if(a[i]<=a[j])
				dp1[i]=max(dp1[i],dp1[j]+1);
			if(a[i]>a[j])
				dp2[i]=max(dp2[i],dp2[j]+1);
		}
		ans1=max(ans1,dp1[i]);
		ans2=max(ans2,dp2[i]);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
