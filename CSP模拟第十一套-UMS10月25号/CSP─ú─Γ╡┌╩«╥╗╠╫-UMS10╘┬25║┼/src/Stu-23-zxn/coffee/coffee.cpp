#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
#define ll long long
#define inf 2100000000

int n,h,b,e,c,ans[maxn];


struct node{
	int val,pos;
	bool operator < (const node y)const{
		node x=*this;
		if(x.val==y.val) return x.pos<y.pos;
		return x.val>y.val;
	}
	bool operator > (const node y)const{
		node x=*this;
		if(x.val==y.val) return x.pos>y.pos;
		return x.val<y.val;
	}
};

priority_queue <node> Q;

int read(){
	int ret=0;char c;
	c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0'){
		ret=((ret<<3)+(ret<<1)+(c&15));
		c=getchar();
	}
	return ret;
}

void init(){
	memset(ans,0,sizeof(ans));
	while(!Q.empty()) Q.pop();
}

int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(scanf("%d%d%d%d",&n,&h,&b,&e)!=EOF){
		init();
		for(int i=1;i<=n;i++){
			c=read();
			node qwq;qwq.pos=i;qwq.val=c;
			Q.push(qwq);
			qwq=Q.top();
			while(qwq.pos<max(i-h+1,1)){
				Q.pop();
				qwq=Q.top();
			}
			ans[qwq.pos]++;
		}
		for(int i=b;i<=e;i++) printf("%d ",ans[i]);
		puts("");
	}
	
}



