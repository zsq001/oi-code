#include <stdio.h>
#include <string.h>
char str[500005],s[500][500];
long long ans[500];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i][1]);

	}
	for(int j=n;j>=2;j--)
		for(int i=n-1;i>=1;i--)
			s[i][j-i+1]=s[j][1];
	if(n<=200)
	{
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=n;j++)
				{
					int cnt=0;
					for(int l=j;l<=n&&(cnt>=0);l++)
					{
						if(s[i][l]=='(')cnt++;
							else cnt--;
						if(cnt==0)ans[i]++;
					}
				}
			ans[i]*=(n-i+1);
		}
		for(int i=2;i<=n;i++)
			ans[1]^=ans[i];
		printf("%lld\n",ans[1]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
