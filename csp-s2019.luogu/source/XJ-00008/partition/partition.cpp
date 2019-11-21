#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
#define maxn 500010

int n,type,a[maxn],q;

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	if(type==0){
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
	}
	int i=1;
	for(int j=i+1;j<=n;++j){
		if(a[j]<a[i]) a[j]=a[i]+a[j];
		q+=a[j]*a[j];
		i=j;
	}
	cout<<q<<endl;
	fclose(stdin);
	fclose(stdout);
}

/*
10 0
5 6 7 7 4 6 2 13 19 9

5 0
5 1 7 9 9
*/
