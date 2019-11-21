#include<cstdio>
#include<algorithm>
#include<cstring>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

int orz,n;
int a[2010],ans[2010][2010];

struct nb{
	int to[500],tox,br;
}r[2010];

void dfs(int h){
	foru(i,1,r[h].tox)
	{
		if(a[r[h].to[i]]>=)
	}
	if(a[1]!=1)
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	orz=read();
	while(orz--)
	{
		n=read();
		foru(i,1,n)
		{
			int mdh=read();
		    a[mdh]=i;
		}
		foru(i,1,n)
		{
			int mdh1=read(),mdh2=read();
		    r[mdh1].tox++;
		    r[mdh1].to[r[mdh1].tox]=mdh2;
		    r[mdh2].tox++;
		    r[mdh2].to[r[mdh2].tox]=mdh1;
		}
		dfs(1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
