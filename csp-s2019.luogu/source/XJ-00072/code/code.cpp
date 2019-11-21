#include<bits/stdc++.h>
using namespace std;
long long n,k;

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	k++;
	long long temp=1;for(int i = 1;i <= n; i++)temp<<=1;
	while(temp!=2){
		if(k>(temp>>1)){
			printf("1");
			k = (temp)-k+1;
			temp>>=1;
		}
		else{
			printf("0");
			temp>>=1;
		}
	}
	if(k==1)printf("0");
	else printf("1");
}
