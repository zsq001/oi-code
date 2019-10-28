#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
int T;
int e[10010];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>T;
	int ans  = 0;
	while(T--)
	{
		memset(e,0,sizeof(e));
		ans = 0;
		int n;
		cin>>n;
		for(int i = 1;i <= n;i ++)
		{
			cin>>e[i];
		}
	    for(int i = 1;i <= n;i ++)
	    {
	    	if((e[i]+e[i+1])%3==0)ans++;
	    	else if((e[i-1]+e[i+1])%3 == 0)ans++;
		}
		cout<<ans<<endl;
	}
}
