#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int t,q,A,B,dp[10010][10010],list[10010];
int a1,a2,a3,a4;
queue <int > po;

bool su(int n)
{
	if(n%2==0) return false;
	for(int i=3;i<=n;i+=2)
	{
		if(n%i==0) return false;
	}
	return true;
}

void f(int t,int s)
{
	if(su(t)&&t!=A&&list[t]<0)
	{
		po.push(t);
		list[t]=list[A]+1;
		dp[A][t]=min(dp[A][t],dp[A][A]+(t-A)%s);
	}
}

int main()
{
	
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	scanf("%d%d",&t,&q);
	while(t--)
	{
		scanf("%d%d",&A,&B);
		while(po.size()) po.pop();
		po.push(A);
		int sum=0;
		memset(list,-1,sizeof(list));
		list[A]=0;
		while(!po.empty()&&list[B]<0)
		{
			A=po.front();
			po.pop();
			a4=A%10;a3=(A/10)%10;a2=(A/100)%10;a1=(A/1000);
			int t;
			for(int i=1;i<10;i++) f(A-a1*1000+i*1000,1000);
			for(int i=0;i<10;i++)
			{
				f(A-a2*100+i*100,100);
				f(A-a3*10+i*10,10);
				f(A-a4+i,1);
			}
		}
		printf("%d",list[B]);		
	}

	return 0;
}
