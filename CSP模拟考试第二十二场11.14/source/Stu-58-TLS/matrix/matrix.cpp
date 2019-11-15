#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n,m,q,x,y,z;
int mp[maxn][maxn];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	memset(mp,0,sizeof(mp));
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){//第y行全放z 
			for(int i=1;i<=m;++i){
				mp[y][i]=z;
			}
		}
		else{//第y列全放z 
			for(int i=1;i<=n;++i){
				mp[i][y]=z;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",mp[i][j]);
		}printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
3 3 3
1 1 3
2 2 1
1 2 2
*/
