#include<bits/stdc++.h>
using namespace std;
bool u_ji[200];
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int n,m;
	float jishu=0,jidian=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(!u_ji[i]){
			jidian+=2;
			jishu+=w;
		}
		u_ji[i]==true;
	}
	printf("%.3f",(jishu/jidian));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
