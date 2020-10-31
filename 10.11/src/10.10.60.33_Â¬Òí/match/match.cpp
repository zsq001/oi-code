#include<cstdio>
#include<algorithm>
using namespace std;
int tree[4000010];
int A[100000],B[100000];
int n,m,x,y;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&B[i]);
	}
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(A[j] - x <= B[i] && B[i] <= A[j] + y)ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
