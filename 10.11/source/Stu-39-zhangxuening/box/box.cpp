#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int v;
//map <int,int> f;
int find(int x){
	int sq=sqrt(x);
	for(int i=sq;i;i--) if(!(x%i)) return x/i+i;
}
//void init(){
//	for(int i=1;1ll*i*i*i<=1ll*v;i++)  f[i*i*i]=i;
//}

int main(){
	scanf("%d",&v);
	int sq=(sqrt(v)+0.5),ans=2147483640;
//	init();
	for(int i=1;i<=sq;i++){
		if(!(v%i)) {
			ans=min(ans,i*find(v/i)+v/i);
			printf("i=%d,find(v/i)=%d,v/i=%d,ans=%d\n",i,find(v/i),v/i,ans);
		}
	}
	printf("%lld",1ll*ans*2);
}
