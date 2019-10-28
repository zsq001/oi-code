#include<cstdio>
#include<algorithm>
using namespace std;
int ans[4510];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int len = ((n*(n-1))/2);
	for(int i = 1;i <= len;i ++)
	{
		scanf("%d",&ans[i]);
	}
	
	sort(ans+1,ans+len+1,cmp);
	if(n == 3)
	{
		puts("1");
		int c = (ans[2]-ans[1]+ans[3])/2;
		int b = ans[3] - c;
		int a = ans[1] - b;
		printf("%d %d %d",c,b,a);
	}
	
	
	return 0;
}
