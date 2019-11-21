#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	long int n,k,s=0,p=0;
	int a[2]={0,1};
	cin>>n>>k;
	s=pow(2,n);
	p=pow(2,n-1);
	int b[s];
	if(k>p)
	for(int i=0;i<s;i++){
		b[s/2+1]=0;
		b[s/2]=1;
		b[s/2-1]=1;
		b[s/2-2]=0;
		cout<<"1"<<b[k];
		break;
	}
	if(k<=p)
	for(int i=s;i>0;i--){
		b[s/2+2]=10;
		b[s/2+3]=10+1;
		b[s/2+4]=100+1;
		b[s/2+5]=0+100;
		cout<<"0"<<b[k];
		break;
	}
	return 0;
}
