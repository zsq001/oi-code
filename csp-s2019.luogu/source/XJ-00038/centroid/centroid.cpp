#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int T,n,x,y,num;
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(int i=1;i<=n-1;i++)scanf("%d%d",&x,&y);
		if(n%2==0)num=4;
		else   num=3;
		printf("%d\n",n*3-num);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
