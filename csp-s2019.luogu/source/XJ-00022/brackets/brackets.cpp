#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int m;
char ks[500010];
vector<int>v[500010];
int jui[500010];
int chain(int x,int dep){
	jui[dep]=(int)ks[x];
	int last=0;
	for(int i=0;i<v[x].size();i++){
		last+=chain(v[x][i],dep+1);
	}
	int tot=0,ans=0,rt=0;
	for(int i=0;i<dep;i++){
		tot=0;ans=0;
		for(int j=i;j<=dep;j++){
			if(jui[j]==(int)'(')tot++;
			else tot--;
			if(tot<0)break;
			if(tot==0)ans++;
		}
		rt+=ans;
	}
	jui[dep]=0;
	if(rt!=0)
	return rt xor x+last;
	else return last;
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>m;
	cin>>ks;
	for(int i=m;i>0;i--){
		ks[i]=ks[i-1];
	}
	for(int i=2;i<m+1;i++){
		int x;cin>>x;
		v[x].push_back(i);
	}
	cout<<chain(1,0);
}
