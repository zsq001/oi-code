#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
long long n,k,pw[100];
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<100;i++)pw[i]=pw[i-1]*2;
	scanf("%lld %lld",&n,&k);
	long long num=pw[n];
	long long flag=0;
	for(long long i=n;i;i--){
		num-=pw[i-1];
		if(flag?(k>=num):(k<num)){
			printf("0");
		}
		else {
			printf("1");
			flag=flag^1;
		}
		if(k>=num)k-=num;	
	}
	return 0;
}
