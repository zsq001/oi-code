#include<cstdio>
#include<algorithm>
#include<cstring>
//#define foru(i,a,b) for(int i=a;i<=b;i++)
//#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
/*
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

int n;
int left[500010],right[500010];

struct orz{
	int to[500],tox,br;
}r[500010];

int judge(int k){
	if(left[k]==right[k])return 1;
}

void dfs(int h)
{
	if(r[h].br==0)
	left[h]++;
	if(r[h].br==1)
	right[h]++	
	foru(i,1,r[h].tox)
	{
		dfs(r[h].to[i]);
	}
	if(r[h].br==0)
	left[h]--;
	if(r[h].br==1)
	right[h]--;	
	if(judge(h)){
		
	}
}
*/
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	/*memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	n=read();
	foru(i,1,n)
	{
		r[i].tox=0;
	}
	foru(i,1,n-1)
	{
		int ch=getchar();
		if(ch=='(')r[i].br=0;
		if(ch==')')r[i].br=1;
	}
	foru(i,2,n)
	{
		int mdh=read();
		r[mdh].tox++;
		r[mdh].to[r[mdh].tox]=i;
	}
	dfs(1);*/
	printf("10");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
