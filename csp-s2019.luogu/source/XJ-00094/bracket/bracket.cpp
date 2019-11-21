#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stack>
#include<math.h>
#define maxn 500005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
int cnt,head[maxn],num[maxn],jc[maxn],n;
char s[maxn];
int a[maxn],qaq,tot,ans[maxn],ln,right,left;
bool flag;
struct Edge{
	int v,next;
}e[maxn];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void init(){
	jc[0]=0;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]+i;
}
void dfs(int x){
	if(s[x]=='('){
		a[++qaq]=1;
	}
	else{
		a[++qaq]=2;
	}
	if(head[x]==0){

		tot++;
		for(int i=1;i<=qaq;i++){
			if(a[i]==1){
				ans[i]=ans[i-1];
				ln++;
				if(right<left&&flag){
					cnt++;
					left-=right;
					right=0;
					ans[i-1]+=jc[cnt]-1;
				}
				else{
					ans[i-right+left-1]+=jc[cnt]-1;
					cnt=0;
					left=right=0;
					flag=0;
				}
				left++;
			}
			else if(a[i]==2){
				flag=1;
				right++;
				ans[i]=ans[i-1];
				if(ln!=0){
					ans[i]++;
					ln--;
				}
			}
		}
		if(cnt&&a[x]==2) ans[x]+=jc[cnt]-1;
		cnt=0;
	}
	
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
	}
}
int u,ret;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);
	scanf("%s",s+1);
	for(int i=1;i<n;i++){
		read(u);
		add(u,i+1);
	}
	init();
	cnt=0;
	dfs(1);
	for(int i=1;i<=n;i++){
		ret^=(i*ans[i]);
	}
	printf("%d",ret);
	return 0;
}
