#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
stack <int> st;
char s[100010];
int pipei[100010],pipein[100010];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i = 0;i < n;i++)
	{
		if(s[i] == '(')
			st.push(i);
		else
		{
			pipei[i] = -1;
			if(st.empty())
				continue;
			pipei[st.top()] = i;
			pipein[i]++;
			st.pop();
		}
	}
	long long ans = 0;
	for(int i = 0;i < n;i++)
		pipein[i] += pipein[i - 1];
	for(int i = 0;i < n;i++)
	{
		ans = ans ^ ((i + 1) * pipein[i]);
	}
	printf("%lld",ans);
	return 0;
}
