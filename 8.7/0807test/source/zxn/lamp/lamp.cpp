#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[100005][20];
int cnt(int a){
	int ret=0,qwq;
	while(a){
		qwq=a&(-a);
		ret++;
		a-=qwq;
	}
	return ret;
}
int a[100005];
int main(){
	int n,k;
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
		for(int j=1;j<=k;j++){
			a[i]|=(c[i][j]-'0')<<(k-j);
		}
	}
	int fan,b=0;
	int to=(1<<k)-1;
	for(int i=0;i<=to;i++){
		int s=17;
		for(int j=1;j<=n;j++){
			s=min(s,cnt(i^a[j]));
		}
		b=max(b,s);
	}
	printf("%d",b);
	return 0;
}
