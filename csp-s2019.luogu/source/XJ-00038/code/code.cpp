#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
typedef int int_;
#define int long long 
using namespace std;
int cnt=1,l,r,mid,la;

int ksm(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret*=a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

bool check(int a,int l,int r){
	mid=(l+r)/2;
	if(a < (l+r)/2){
		return false;
	} 
	else {
		return true;
	}
}

int_ main(){
	int n,k,las;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	l=0,r=ksm(2,n),mid=(l+r)/2;	
	if(check(k,l,r)){
		las=1;
		l=mid;
		printf("1");
		la=1;
	}
	else {
		las=0;
		r=mid;
		printf("0");
		la=0;
	}    
	while(n>1){
		if(check(k,l,r)){
			if(las==0){
				printf("1");
				las=1;
				la=1;
			}
			else {
				printf("0");
				la=0;
				las=1;
			}
			l=mid;
		}
		else {
			if(las==0){
				printf("0");
				las=0;
				la=0;
			}
			else {
				printf("1");
				la=1;
				las=0;
			}
			r=mid;
		}
		n--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
