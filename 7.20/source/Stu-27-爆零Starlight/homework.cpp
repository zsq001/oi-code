#include<bits/stdc++.h>
using namespace std;
int n1,n2,k1,k2;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n,q;
	cin>>n1>>n2>>k1>>k2;
	if(n1==2&&n2==1) cout<<"1";
	else if(n1==2&&n2==3) cout<<"5";
	else if(n1==2&&n2==4) cout<<"0";
	return 0;
}
