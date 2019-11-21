#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int n;
char k[30];
int kk[30];//nowaplace
int pos;//hand
int ans[100];
int wei=-1;//hand

int mi[30];
int mi_wei=0;//hand

void chengfang(int zs){
	memset(mi,0,sizeof(mi));
	mi[0]=1;
	mi_wei=0;
	for(int i=1;i<=zs;i++){
		//chengfa
		for(int j=0;j<=mi_wei;j++){
			mi[j]*=2;
		}
		//jingwei
		for(int j=0;j<=mi_wei;j++){
			if(mi[j]>=10){
				mi[j+1]+=1;
				mi[j]-=10;
				if(j==mi_wei)mi_wei++;
			}
		}
	}
}

bool mmp(){
	if(pos>mi_wei)return true;
	if(pos<mi_wei)return false;
	for(int i=pos;i>=0;i--){
		if(kk[i]>mi[i])return true;
		if(kk[i]<mi[i])return false;
	}
	return true;
}

void change(int zs1){
	chengfang(zs1);
	mi[0]-=1;
	for(int i=0;i<=pos;i++){
		mi[i]-=kk[i];
		//tuiwei
		if(mi[i]<0){
			mi[i+1]-=1;
			mi[i]+=10;
		}
	}
	//copy
	bool first=false;
	for(int i=mi_wei;i>=0;i--){
		if(mi[i]!=0&&first==false){
			first=true;
			pos=i;
		}
		kk[i]=mi[i];
	}
}

void solve(int depth){
	for(int i=depth;i>=1;i--){
		chengfang(i-1);
		bool p=mmp();
		if(p==true){
			wei++;
			ans[wei]=1;
			change(i);
		}
		else{
			wei++;
			ans[wei]=0;
		}
	}
	
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	
	scanf("%d%s",&n,&k);
	for(int i=0,j=strlen(k)-1;i<strlen(k);i++,j--){
		kk[j]=k[i]-'0';
	}
	pos=strlen(k)-1;
	solve(n);
	/*for(int i=0;i<strlen(k);i++){
		printf("%d",kk[i]);
	}*/
	for(int i=0;i<=wei;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
