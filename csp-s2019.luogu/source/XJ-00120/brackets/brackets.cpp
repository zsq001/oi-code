#include <bits/stdc++.h>
#include <stack>
using namespace std;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
ll n,g,cnt(0);
int tot=0, ans=0,ok[100010]={0};
typedef struct nt
{int num=0,to[500];
char con;
}ms[1000];
stack<string> s;
inline int read()
{
	int x=0;
	char ch=getchar();
	if(ch=='('||ch==')')return ch-'(';
	x=(x<<1)+(x<<3)+(ch^48);
	ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}

int k(int wsm)
{
	tot=0;
	for(int l=0,r=0;l<=s.size()-1,r<=s.size()-1;)
	{
		if(s[l]=='(')
		{
			r=l+1;
			if(s[r]==')')tot++,ok[l]=ok[r]=1,l+=2;
		}
		else l++;
	}
	for(int l=0,r=0;l<=s.size()-1,r<=s.size()-1;)
	{
		cnt=0;
		if(ok[l])
		{
			r=l+2;
			if(ok[r])tot+=++cnt,l+=2;
		}
		else l++;
	}
	for(int l=0,r=0;l<=s.size()-1,r<=s.size()-1;)
	{
		while(!ok[l])
		{
			l++;r=l+1;
		}
		while(ok[r])
		{
			r++;
		}
		while(s[l-1]=='('&&s[r]==')')tot++,l--,r++;
	}
	return tot;
}

void search(int lpc)
{
	ans^=(lpc*k(lpc));
	if(!ms[lpc].num)
	{
		return;
	}
	foru(i,1,ms[lpc].num)s.push(ms[lpc].con),search(ms[lpc].to[i]),s.pop();
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);

	cin>>n;
	foru(i,1,n)ms.con[i]=read()+'(';
	foru(i,2,n)g=read(),ms[g].to[++num]=i;
	search(1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
