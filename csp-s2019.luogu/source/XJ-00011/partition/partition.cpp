#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	int type;
	long n,j,k,l;
	long long ans=0;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(l=i-1;l>=1;l--)
			if(a[l])
				break;
		for(k=i;k<=n;k++)
			if(a[k])
				break;
		for(j=k+1;j<=n+1;j++)
			if(a[j])
				break;
		if(a[k]<a[l])
		{
			if(((a[l]<a[j])&&(a[k]<=a[j]-a[l]))||(a[j]==0))
				{
					a[l]+=a[k];
					a[k]=0;
				}
			else
			{
				a[k]+=a[j];
				a[j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i])
			ans+=a[i]*a[i];
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
