#include<cstdio>
#include<cstring>
using namespace std;
char s[2010];
int ans;

bool check(int l,int r)
{
	while(l < r)
	{
		if(s[l] != s[r]) return false;
		l ++;r --;
	}
	return true;
}

int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int l = 1;l <= n;l ++)
	{
		for(int r = l;r <= n;r ++)
		{
			if(s[l] != s[r]) continue;
			if(l == r || check(l,r))
			for(int L = r+1;L <= n;L ++)
			{
				for(int R = L;R <= n;R ++)
				{
					if(s[L] != s[R]) continue;
					if(L == R || check(L,R)) ans ++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
