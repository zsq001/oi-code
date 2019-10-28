#include <cstdio>
#include <algorithm>
using namespace std;

#define LE(x) ((x)<<1)
#define RT(x) (((x)<<1) | 1)
#define DAD(x) ((x)>>1)

struct Heap
{
	int s[250005];
	int tot;
	
	void ins(int x)
	{
		int t;
		s[++tot]=x;
		x=tot;
		
		while(x != 1)
		{
			if(s[x] > s[DAD(x)])
				t=s[x],s[x]=s[DAD(x)],s[DAD(x)]=t,x=DAD(x);
			else break;
		}
	}
	
	int top()
	{
		return s[1];
	}
	
	void pop()
	{
		s[1]=s[tot];
		s[tot--]=0;
		
		int x=1,t,tar=s[LE(x)]>s[RT(x)] ? LE(x):RT(x);
		
		while(s[tar] > s[x])
		{
			t=s[x],s[x]=s[tar],s[x=tar]=t;
			tar=s[LE(x)]>s[RT(x)] ? LE(x):RT(x);
		}
	}
}; 

Heap h;
int ans[100005];

int main(void)
{
	int n,x;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&x),h.ins(x);
	
	for(int i=0;i<n;i++)
		ans[n-i]=h.top(),h.pop();
	
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	
	return 0;
}
