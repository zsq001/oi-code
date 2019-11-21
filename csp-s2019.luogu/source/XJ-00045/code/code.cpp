#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
int n,i,l=1,m=0;
long long int k;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<n;i++){
		l=l*2;
	}
	for(i=0;i<n;i++){
		if(k>=l&&m==0){
			cout<<"1";
			m=1;
		}else if(k<l&&m==1){
			cout<<"1";
			m=0;
		}else{
			cout<<"0";
		}if(k>l){
			k=k-l;
		}l=l/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
