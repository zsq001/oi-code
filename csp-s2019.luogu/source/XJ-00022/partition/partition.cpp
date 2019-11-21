#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
using namespace std;
int m,a;
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		a+=x;
	}
	cout<<a*a;
}
