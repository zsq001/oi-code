#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int a[500001];
int n;
char c[500001];
char zuo[500001];
int nn;
int shen[500001];
void gett(int xx,int u)
{
	if(u==0)return;
	zuo[u]=c[xx];
	gett(a[xx],--u);
}
void sh(int u,int m)
{
	if(a[u]==0)return;
	++shen[m];
	sh(a[u],m);
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	getchar();
	scanf("%s",c+1);
	shen[1]=1;
	for(int i=1;i<n;++i)
	{
		int q;
		read(q);
		a[i+1]=q;
		shen[i+1]=1;
		sh(i+1,i+1);
	}
	int ans=0;
	for(int i=2;i<=n;++i)
	{
		int b=0;
		int g=0;
		memset(zuo,0,sizeof(zuo));
		nn=i;
		int l=0;
		int h=0;
		gett(i,shen[i]);
	    for(int j=1;j<=shen[i];++j)
	    {
	    	
	       	int v=0;
	    	if(zuo[j]!=')'&&h!=0&&zuo[j+1]!=')')h=0,b=0;
	    	else if(zuo[j]==')'&&h!=0)++b,v=1;
			if(b>=1&&v==1)g+=(b-1); 
	    	if(zuo[j]=='(')++l,h=1;
	    	else if(l!=0&&zuo[j]==')'){
	    		--l;
	    		++g;
	    	}
	    }
	    ans=ans^(g*i);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
