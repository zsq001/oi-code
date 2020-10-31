#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long ans=0,now_max=-1,now_min=500000001;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++){
		long long ci;
		scanf("%lld",&ci);
		now_max=(now_max<ci)?ci:now_max;
		now_min=(now_min>ci)?ci:now_min;
	}
	ans=now_max+now_min;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
