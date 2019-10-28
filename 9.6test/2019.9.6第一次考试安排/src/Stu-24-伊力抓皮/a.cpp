#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		int n,cnt1 = 0,cnt2 = 0,cnt3 = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
		{
			int x;
			scanf("%d",&x);
			x %= 3;
			if(x == 0) cnt3 ++;
			else if(x == 1) cnt1 ++;
			else cnt2 ++;
		}
		int k = min(cnt1,cnt2);
		cnt1 -= k;
		cnt2 -= k;
		
		cnt3 = cnt3 + k + (cnt1/3) + (cnt2/3);
		printf("%d\n",cnt3);
	}
	return 0;
}
