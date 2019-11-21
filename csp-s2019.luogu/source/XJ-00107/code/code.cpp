#include <bits/stdc++.h>
using namespace std;
unsigned long long n,k,b,a[64];
int j,i;
bool ans[64],c=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	a[0]=1;
	for(j=1;j<=63;j++)
		a[j]=a[j-1]*2;
	b=a[n-1];
	for(i=n-1;i>=0;i--)
	{
		ans[i]=((k>=b)^c);
		if(i!=0) b+=(k<b)?(-a[i-1]):a[i-1];
		c^=ans[i];
	}
	for(j=n-1;j>=0;j--)
		cout<<ans[j];
	cout<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
