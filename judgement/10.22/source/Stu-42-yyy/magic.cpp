#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int M=1e9+7;
int n,sum;
int qpow(int a,int b){
	long long r=1,bs=a;
	while(b){
		if(b&1)r=r*bs%M;
		bs=bs*bs%M;
		b>>=1;
	}
	return (int)r;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	sum=(qpow(3,n+1)-3)/2+1;
	printf("%d\n",sum);
	return 0;
}
