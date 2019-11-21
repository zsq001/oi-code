#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int d,b,e,s=0;
	char c;
	cin>>d;
	int a[d];
	for(int i=0;i<d;i++){
		cin>>c;
		if(c==')')s++;
		else e=0;
	}
	for(int i=0;i<d-1;i++){
		cin>>b;
	}
	a[d]=0;
	for(int i=0;i<d;i++){	
		a[d]++;	
	}
	s=(a[d]*e)xor(a[d]*e)xor(a[d]*(s/s))xor(a[d]*e)xor(a[d]*(s/s));	
	cout<<s;
	return 0;
}
