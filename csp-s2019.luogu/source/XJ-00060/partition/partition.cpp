#include<bits/stdc++.h>
using namespace std;
int n,m;
long long lucky_n=0;
int a[400];
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			a[i]+=a[i+1];
			a[i]=0;
		}
		lucky_n+=a[i]*a[i];
	}
	printf("%lld",lucky_n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
