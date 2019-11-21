#include<bits/stdc++.h>
using namespace std;
int n,C6H12O6[2000],CH4[4000];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			cin>>C6H12O6[i];
		}
		for(int i=0;i<n-1;i++){
			cin>>CH4[i]>>CH4[n+i];
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
