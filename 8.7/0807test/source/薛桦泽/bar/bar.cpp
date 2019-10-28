#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct pii
{
	int first,secont,third;
};
queue<pii>q;
bool jud[1010][1010]={false},o=false;
int tot=0,tal=1,x[5]={0,1,0,-1},y[5]={0,0,1,0,-1};
int t,n;
void dfs(int i)
{
	if(q.empty()) 
	{
		o=true;
		return;
	}
	pii pp=q.front();
	while(pp.third<=i)
	{
		
		int a=pp.first;
		int b=pp.secont;
		for(int i=1;i<=4;i++)
		{
			if(!jud[a+x[i]][b+y[i]])
			{
				jud[a+x[i]][b+y[i]]=true;
				pii p;
				p.first=a+x[i];
				p.secont=b+y[i];
				p.third=i+1;
				q.push(p);
			}
			
		}
		q.pop();
		pp=q.front();
	}
}
int main()
{
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout); 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pii p;
		p.first=1;
		p.secont=1;
		p.third=0;
		q.push(p);
		jud[1][1]=true;
		for(int i=1;i<=2*n-2;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			jud[a][b]=true;
			dfs(i-1);
			if(o)
			{
				printf("NO");
				break;
			}
		}
		if(!o) printf("YES");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
