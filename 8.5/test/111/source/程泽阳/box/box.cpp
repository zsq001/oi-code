#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];
long long cns,b[3];
int main()
{
	int t,i,j,n;
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1){
			printf("%d\n",a[1]);
			continue;
		}
		int l=1,r=n;
		while(l<r)
		{
			for(i=1;i<=2;i++)
			{
				if(a[l]>a[r]){
					b[i]+=a[l];
					l++;
				}
				else{
					b[i]+=a[r];
					r--;
				}
			}
		}
		
		cns=b[1]-b[2];
		printf("%lld\n",cns);
		b[1]=0;b[2]=0;cns=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
