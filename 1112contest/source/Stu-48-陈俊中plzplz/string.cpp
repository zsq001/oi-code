#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010
using namespace std;

int n,t,next[maxn],ans;
char f[maxn],ff[maxn];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d ",&n);
		next[1]=0;
//		if(n<2)
//		{
//			puts("0\n");
//			continue;
//		}
		scanf("%s",ff+1);
//		int L=1;
		for(int i=2,j=0;i<=n;next[i++]=j)
		{
			while(ff[j+1]!=f[i]&&j) j=next[j];
			if(ff[j+1]==ff[i]) ++j;
		}
		ans=n-next[n];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-1;j++) f[j]=(j<i)?ff[j]:ff[j+1];
			for(int j=2,k=0;j<=n;next[j++]=k)
			{
				while(f[k+1]!=f[j]&&k) k=next[k];
				if(f[k+1]==f[j]) ++k;
			}
			ans=min(ans,n-next[n-1]-1);
		}//KMP求最小循环节 
		printf("%d\n",ans);
	}
	return 0;
}
