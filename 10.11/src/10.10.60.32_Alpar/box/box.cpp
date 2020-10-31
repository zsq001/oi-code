#include<cstdio>
#include<cmath>
#include<algorithm>
#define int_ long long
using namespace std;
bool vis[100100000][3];
int_ ans=0x7fffffff,Cbrt,stk[5],top;
void Search(int_ v,int dep){
	if(dep==3){
		ans=min(((v*stk[1])<<1)+((stk[1]*stk[2])<<1)+((stk[2]*v)<<1),ans);
		return ;
	}
	int x=1;
	for(int i=1;i<=Cbrt;i++){
		if(v%i==0){
			stk[++top]=i;
			Search(v/i,dep+1);
			stk[top--]=0;	
		}
	}
}
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int_ V;
	scanf("%I64d",&V);
	Cbrt=pow(V,1.0/2)+1;
	Search(V,1);
	printf("%I64d",ans);
	
}
