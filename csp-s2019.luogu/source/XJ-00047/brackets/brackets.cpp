#include<stdio.h>
#include<string.h>
using namespace std;

int a[10050],vis[10050];	
int s[1010][1010];
int k[10050];
long long ans;

int jia(int x)
{
	int an=0;
	for(int i=1;i<=x;i++)
		an+=i;
	return an;
}

int sou(int l,int r)
{
	if(l>=r)return 0;
	if(s[l][r])return s[l][r];
	int bian=0,sum=0,tot=0;
	for(int i=l;i<=r;i++)
	{
		if(vis[i]==0)
		{
			return s[l][r]=sou(l,i-1)+sou(i+1,r);
		}
		if(vis[i]==vis[l])bian++;
	}
	if(bian==2)return s[l][r]=1+sou(l+1,r-1);
	int left=l;
	for(int i=l+1;i<=r;i++)
	{
		if(vis[i]==vis[left]&&i!=left)
		{
			tot++;
			sum+=sou(left,i)-1;
			left=i+1;
		}
	}
	return s[l][r]=jia(tot)+sum;
}

int main()
{
	int n;
	char c;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if(c=='(')a[i]=1;
		else if(c==')')a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(vis[j])continue;
				if(vis[j]==0&&a[j]==1){for(int kk=j;kk<=i;kk++)vis[kk]++;break;}
			}
		}
		if(a[i]==1)k[i]=k[i-1];
		else k[i]=sou(1,i);
		ans=ans^(i*k[i]);
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
