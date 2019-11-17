#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 50
int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int n,m,c[maxn];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++){
		c[i]=in();
	}
	c[n+1]=m;
	sort(c+1,c+1+n+1);
	int ans=0;
	while(1){
		int cnt=0;
		if(c[2]==0) break;
		ans+=c[2];
		int c2=c[2];
		for(int i=2;i<=n+1;i++){
			c[i]-=c2;
			if(c[i]<=0) cnt++;
			if(cnt>1){
				break;
			}
		}
		if(cnt>1) break;
		sort(c+1,c+1+n+1);
	}
	printf("%d",ans);
	return 0;
}
