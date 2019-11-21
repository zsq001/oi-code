#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack <int>s;
char a[100010];
inline int digit(int l,int r)
{
	int cnt = 0;
	char left;
	for(int i = l;i <= r;i ++)
	{
		s.push(a[i]);
		if(s.top() == ')' && left == '(')
		{
			s.pop();
			s.pop();
			++cnt;
			left = s.top();
		}
		left = s.top();
	}
	return cnt;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		cin>>a[i];
		if(a[i] == EOF || a[i] == ' '||a[i] =='\n')
		{
			a[i] = 0;
			break;
		}
	}
	int father[100010];
	for(int i = 1;i <= n - 1;i ++)
	{
		cin>>father[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		int k = digit(1,i);
		ans ^= (k * i);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}
