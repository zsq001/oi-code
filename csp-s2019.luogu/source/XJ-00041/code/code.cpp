#include <cstdio>
#include <cstring>

#define ll long long int

using namespace std;

bool num[65]={}, sign=false;
int k[20]={}, n, p[20]={1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void get()
{
	int i=1;
	char a[25];
	gets(a);
	for(i;i<=20;i++)
	{
		if(a[i-1]-'\0')
			k[i]=a[i-1]-'0';
		else
			break;
	}
	i-=2;
	k[0]=i;
	for(int j=1;j<=k[0];j++)
		k[j]=k[j+1];
	k[i+1]=0;
	k[k[0]]+=1;
	if(k[k[0]]>9)
	{
		for(int j=k[0];j>0;j--)
			k[j+1]=k[j];
		k[1]=0;
		k[0]++;
		for(int j=k[0];j>0;j--)
		{
			k[j-1]+=k[j]/10;
			k[j]%=10;
		}
	}
	return;
}

void div()
{
	for(int i=1;i<p[0];i++)
	{
		p[i+1]+=p[i]%2*10;
		p[i]/=2;
	}
	p[p[0]]/=2;
	if(!p[1])
	{
		for(int j=1;j<p[0];j++)
			p[j]=p[j+1];
		p[p[0]]=0;
		p[0]--;
	}
	return;
}

void mul()
{
	for(int i=p[0];i>1;i--)
	{
		p[i]*=2;
		p[i-1]+=p[i]/10;
		p[i]%=10;
	}
	p[1]*=2;
	if(p[1]>9)
	{
		for(int j=p[0];j>0;j--)
			p[j+1]=p[j];
		p[1]=p[2]/10;
		p[2]-=10;
		p[0]++;
	}
	return;
}

void mnu()
{
	int i=k[0], j=p[0];
	while(i&&j)
	{
		k[i]-=p[j];
		if(k[i]<0)
		{
			k[i]+=10;
			k[i-1]-=1;
		}
		i--;
		j--;
	}
	for(;;)
	{
		if(!k[1])
		{
			for(int j=1;j<k[0];j++)
				k[j]=k[j+1];
			k[0]--;
		}
		else
			break;
	}
}

bool com()
{
	if(k[0]>p[0])
	{
		//sign=!sign;
		return true;
	}
	else 
	{
		if(k[0]<p[0])
			return false;
		else
		{
			for(int i=1;i<=p[0];i++)
			{
				if(k[i]>p[i])
				{
					//sign=!sign;
					return true;
				}
				else
				{
					if(k[i]<=p[i])
						return false;
					else
						continue; 
				}
			}
		}
	}
	
}

void put(int i)
{
	div();
	bool che=com();
	if(sign)
	{
		if(che)
		{
			num[i]=false;
			mnu();
			//sign=!sign;
		}
		else
			num[i]=true;
			sign=!sign;
	}
	else
	{
		if(che)
		{
			num[i]=true;
			mnu();
			sign=!sign;
		}
		else
			num[i]=false;
	}
}

void print()
{
	for(int i=1;i<=n;i++)
	{
		if(num[i])
			printf("1");
		else
			printf("0");
	}
	return;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	get();
	for(int i=n;i>0;i--)
		mul();
	for(int i=1;i<=n;i++)
		put(i);
	print();
	return 0;
}
