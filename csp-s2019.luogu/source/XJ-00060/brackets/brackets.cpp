#include<bits/stdc++.h>
using namespace std;
string H2;
int N2,FE[500005];
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&N2);
	cin>>(H2);
	for(int i=1;i<n;i++){
		scanf("%d ",FE[i]);
	}
	int O2=0,ki=0;
	for(int i=1;i<=n;i++){
		if(H2[i-1]=='('&&H2[i]==')'){
			ki++;
			i++;
		}
		O2=O2^(i*ki);
	}
	printf("%d",O2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
