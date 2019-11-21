#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int a[100];
	long long n;
	int type,i;
	cin>>n>>type;
	for(i=1;i<=5;i++){
		cin>>a[i];		}
	sort(a+1,a+n+1);
	long long ppp;
	for(i=1;i<=5;i++){
		ppp=a[i]*a[i]+ppp;		}
		cout<<ppp;
		fclose(stdin);
		fclose(stdout);
		return 0;
}
