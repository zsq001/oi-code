#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,a,b;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>a;
	while(a--){
		cin>>m;
		for(int i=0;i<m;i++)cin>>b;
		for(int i=0;i<m-1;i++)cin>>b;
		for(int i=0;i<m-1;i++)cin>>b;
		for(int i=0;i<m;i++)cout<<i+1<<' ';
		cout<<endl;
	}
}
