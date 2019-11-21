#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long int n,m,a=1;
	cin>>n>>m;
	m++;
	for(int i=0;i<n;i++){
		a*=2;
	}
	if(m>a/2){
		cout<<1;
		}
		else{
			cout<<0;
		}
	for(int i=0;i<n-1;i++){
		if(m<=a/4){
			cout<<0;
		}else if(m<=a*3/4){
			cout<<1;
			if(m>a/2){
				m-=a/2;
			}
		}else{
			cout<<0;
			m-=a/2;
		}
		a/=2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
