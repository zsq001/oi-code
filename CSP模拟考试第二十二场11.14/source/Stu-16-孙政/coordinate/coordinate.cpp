#include<bits/stdc++.h>
using namespace std;
int N;
int jilu[100000000]={0};
int hanshu(int n,int m){
	if(n==1){
		return 3;
	}
	if(jilu[n]!=0){
		return jilu[n];
	}
	return jilu[n]=(hanshu(n-1,m-1)+(n-m)*(2+m)*(n-(m-1)))%100000007;
}

int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&N);
	printf("%d",hanshu(N,N-1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
