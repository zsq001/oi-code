#include <stdio.h>
#include <algorithm>
using namespace std;
int qvmin(int x,int y){if(x<y)return x;else return y;}
int c[55];
int main()
{
	int n,m,ans;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	c[++n]=m;
	sort(c+1,c+n+1);
	c[3]-=c[2];
	ans=c[2]+qvmin(c[3],c[1]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
