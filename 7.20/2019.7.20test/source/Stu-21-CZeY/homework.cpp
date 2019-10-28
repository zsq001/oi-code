#include<cstdio>
int k1,k2;
long long num,mun;
void bfs(int n1,int n2);
void dfs(int n1,int n2)
{
	if(n1==0 && n2==0)
	{
		num++;
		num%=100000000;
		return ;
	}
	for(int i=1;i<=k1;i++)
	{
		if(n1-i >= 0)
		{
			bfs(n1-i,n2);
		}
		else{
			break;
		}
	}
}

void bfs(int n1,int n2)
{
	if(n1==0 && n2==0)
	{
		mun++;
		mun%=100000000;
		return ;
	}
	for(int i=1;i<=k2;i++)
	{
		if(n2-i >= 0)
		{
			dfs(n1,n2-i);
		}
		else{
			break;
		}
	}
}


int main()
{
	int n1,n2;
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	dfs(n1,n2);
	bfs(n1,n2);
	printf("%d",num+mun);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
