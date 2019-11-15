#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 100005
#define ll long long

int read(){
	int ret=0;char ch=getchar();bool ff=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') ff=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}
bool f[maxn];
int main(){
	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	int m=read(),czy=read();
	queue <int> Q;
	while(m--){
		czy=read();
		if(czy==1){
			f[read()]=1;
		}
		if(czy==2){
			int aa=read();
			f[aa]=0;
			Q.push(aa);
		}
		if(czy==3){
			f[Q.front()]=1;
			Q.pop();
		}
		if(czy==4){
			int i;
			for(i=0;i<=maxn;i++){
				if(!f[i]) break;
			}
			printf("%d\n",i);
		}
	}
}
