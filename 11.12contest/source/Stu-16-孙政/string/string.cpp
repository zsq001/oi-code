#include<bits/stdc++.h>
using namespace std;

string gegege="0";
int caozuo(string a){
	int i=0,p=0;
	if(a[a.size()]!=a[0])
	 a.erase(a.size());
	for(i;i<a.size();i++){
		gegege+=a[i];
		p++;
		if(a[i]==a[0])
		 break;
	}
	for(int j=0;j<=p;j++){
		if(gegege[j]!=a[p+j]){
			gegege.erase(j);
			i-=1;
			break;
		}

	}
	return i;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		string A;
		cin>>A;
		cout<<caozuo(A)<<endl;
	}
	return 0;
}
