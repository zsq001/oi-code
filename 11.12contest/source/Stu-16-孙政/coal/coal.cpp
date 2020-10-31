#include<bits/stdc++.h>
using namespace std;
int n,k,c,w;
bool place[10001]={0};
double now_ooo[10001][10001]={0};
int aaa[101]={0};
double caozuo(double now_coin,int now_place,int now_m){
	if(now_place==n)
		return 0;
	if(now_ooo[now_place][now_m]!=0)
		return now_ooo[now_place][now_m];
	if(place[now_place]){
		if(now_m<=k&&now_coin>=(aaa[now_place]*now_m)){
			return now_ooo[now_place][now_m]=caozuo(now_coin-(aaa[now_place]*now_m),now_place+1,now_m+c);
		}else
			return now_ooo[now_place][now_m]=caozuo(now_coin,now_place+1,now_m);
	}else{
		if(now_m>=k){
			return now_ooo[now_place][now_m]=caozuo(now_coin+(aaa[now_place]*now_m),now_place+1,now_m-k);
		}else
			return now_ooo[now_place][now_m]=caozuo(now_coin,now_place+1,now_m);
	}
}

int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d %d %d %d",&n,&k,&c,&w);
	int o=0;
	while(o<n){
		int type,ai;
		scanf("%d %d",&type,&ai);
		aaa[o]=ai;
		if(type=='2')
		place[o]=true;
		o++;
	}
	double coin_result=caozuo(0,0,w);
	printf("%.2f", &coin_result);
	return 0;
}
