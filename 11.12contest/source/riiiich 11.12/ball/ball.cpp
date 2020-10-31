#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long step=0;
char zhan[110];
const int inf=1e18;
void ins(int M){
	for(int j=0;j<=M;++j){
		if(zhan[j]=='R')
		zhan[j]='B';
		else
		zhan[j]='R';
	}
}
int p;
void sorrt(){
	while(p!=n){
		p=0;
		for(int i=0;i<n;++i){
		if(zhan[i]=='R')
			p++;
	}
		for(int Q=0;Q<n;++Q){
			if(zhan[Q]=='B'){
				ins(Q);
				step++;
				break;
			}
		}	
	}
	if(step>inf)
	step=-1;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=0;i<n;++i)
	scanf("%c",&zhan[i]);
	sorrt();
	printf("%lld",step);
	return 0;
}
