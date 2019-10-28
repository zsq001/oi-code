#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a,b,x,y,k,p;
ll n,m;
ll f[3][4];
ll q[3][4];
ll gcd(int l,int r)
{
	if(!r)
	{
		return l;
	}
	return gcd(r,l%r);
}
int main()
{
	int t;
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		if(a==0&&b==0)
		{
			printf("N\n");
			continue;
		}
		if(a==b)
		{
			if((x!=-y)&&(x!=y)&&(-x!=y))
			{
				printf("N\n");
				continue;
			}
			else printf("Y\n");
			continue;
		}
		if(((x==a)&&(y==b))||((x==b)&&(y==-a))||((x==-b)&&(y==-a))||((x==-b)&&(y==a))||((x==a)&&(y==-b))||((x==-a)&&(y==b))||((x==b)&&(y==a))||((x==-a)&&(y==-b)))
		{
			printf("Y\n");
			continue;
		}
		int lcmx=(a*b)/gcd(a,b);
		int lcmy=lcmx;
		f[1][1]=a;
		f[1][2]=b;
		f[1][3]=x;
		f[2][1]=b;
		f[2][2]=a;
		f[2][3]=y;
		q[1][1]=a;
		q[1][2]=b;
		q[1][3]=x;
		q[2][1]=b;
		q[2][2]=a;
		q[2][3]=y;
		for(int i=1;i<=3;i++)
		{
			if(lcmx!=0)
			{
				if(f[1][1]!=0)
				q[1][i]*=lcmx/f[1][1];
				else
				q[1][i]*=lcmy/f[1][2];
			}
			
		}
		for(int i=1;i<=3;i++)
		{
			if(lcmx!=0)
			{
				if(f[2][1]!=0)
				q[2][i]*=lcmx/f[2][1];
				else 
				q[2][i]*=lcmy/f[2][2];
			}
		}
		if(q[1][2]==q[2][2])
		{
			q[1][1]-=q[2][1];
			q[1][3]-=q[2][3];
			if(q[1][3]%q[1][1]!=0)
			{
				printf("N\n");
				continue;
			}
			n=q[1][3]/q[1][1];
			if((f[1][3]-f[1][1]*n)%f[1][2]!=0)
			{
				printf("N\n");
				continue;
			}
			m=(f[1][3]-f[1][1]*n)/f[1][2];
			if((n>-1&&n<1)||(m>-1&&m<1))
			{
				printf("N\n");
				continue;
			}
			printf("Y\n");
		}
		else if(f[1][1]!=0&&f[2][1]!=0)
		{
			q[1][2]-=q[2][2];
			q[1][3]-=q[2][3];
			if(q[1][3]%q[1][2]!=0)
			{
				printf("N\n");
				continue;
			}
			n=q[1][3]/q[1][2];
			if((f[1][3]-f[1][2]*n)%f[1][1]!=0)
			{
				printf("N\n");
				continue;
			}
			m=(f[1][3]-f[1][2]*n)/f[1][1];
			if((n>-1&&n<1)||(m>-1&&m<1))
			{
				printf("N\n");
				continue;
			}
			if(((n>=0)&&(n<1))||((m>=0)&&(m<1))||((n>-1)&&(n<=0))||((m>-1)&&(m<=0)))
			{
				printf("N\n");
				continue;
			}
			printf("Y\n");
		}
		else if(f[1][1]==0&&f[2][1]!=0)
		{
			if(q[1][3]%q[1][2]!=0)
			{
				printf("N\n");
				continue;
			}
			n=q[1][3]/q[1][2];
			if((f[2][3]-f[2][2]*n)%f[2][1]!=0)
			{
				printf("N\n");
				continue;
			}
			m=(f[2][3]-f[2][2]*n)/f[2][1];
			if((n>-1&&n<1)||(m>-1&&m<1))
			{
				printf("N\n");
				continue;
			}
			if(((n>=0)&&(n<1))||((m>=0)&&(m<1))||((n>-1)&&(n<=0))||((m>-1)&&(m<=0)))
			{
				printf("N\n");
				continue;
			}
			printf("Y\n");
		}
		else if(f[1][1]!=0&&f[2][1]==0)
		{
			if(q[2][3]%q[2][2]!=0)
			{
				printf("N\n");
				continue;
			}
			n=q[2][3]/q[2][2];
			if((f[1][3]-f[1][2]*n)%f[1][1]!=0)
			{
				printf("N\n");
				continue;
			}
			m=(f[1][3]-f[1][2]*n)/f[1][1];
			if((n>-1&&n<1)||(m>-1&&m<1))
			{
				printf("N\n");
				continue;
			}
			if(((n>=0)&&(n<1))||((m>=0)&&(m<1))||((n>-1)&&(n<=0))||((m>-1)&&(m<=0)))
			{
				printf("N\n");
				continue;
			}
			printf("Y\n");
		}
	}
	return 0;
}
