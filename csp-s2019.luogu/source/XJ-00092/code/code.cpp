#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
char f[70];

void zhq(int x,int y){
	if(x==0&&y==0)return ;;
	int mid,r;
	r=pow(2,x)-1;
	mid=pow(2,x-1);
	if(y>=mid){
		f[x]='1';
		zhq(x-1,r-y);
	}
	if(y<mid){
		f[x]='0';
		zhq(x-1,r-y);
	}
}

int main(){
	int n;
	long long k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
    zhq(n,k);
    for(int i=n;i>=1;i--){
    	printf("%c",f[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
