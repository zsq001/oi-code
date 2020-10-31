#include<bits/stdc++.h>
using namespace std;
char ge[52]={0};//Ö÷ÒªµÄ×Ö·û´®
int N;
long long jishu=0,linjie=1000000000000000000;
char change(char i){
	return (i=='R')?'B':'R';
}
void caozuo(){
	int i=0,j=0;
	bool flag=false;
	for(i;i<N;i++){
		if(ge[i]=='B'){
			flag=true;
			for(j;j<=i;j++){
				ge[j]=change(ge[j]);
			}
			jishu++;
			break;
		}
	}
	if(flag)
		caozuo();
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>N;
	int i=0;
	for(i;i<N;i++){
		cin>>ge[i];
	}
	caozuo();
	
	if(jishu>=linjie)
		cout<<"-1";
	else 
		cout<<jishu;
	return 0;
}
