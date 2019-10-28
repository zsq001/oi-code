#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int w[65],f[40005],blg[65],att[65][3],val[65],n,m;
void read(int &x){
	int t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='0') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
int main(){
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++){
		read(w[i]),read(val[i]),read(blg[i]);
		val[i]*=w[i];
		if(blg[i]!=0){
			if(att[blg[i]][1]!=0) att[blg[i]][2]=i;
			else att[blg[i]][1]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(blg[i]!=0) continue;
		for(int j=n;j>=0;j--){
			if(j>=w[i]) f[j]=max(f[j],f[j-w[i]]+val[i]);
			if(j>=w[i]+w[att[i][1]]) f[j]=max(f[j],f[j-w[i]-w[att[i][1]]]+val[i]+val[att[i][1]]);
			if(j>=w[i]+w[att[i][2]]) f[j]=max(f[j],f[j-w[i]-w[att[i][2]]]+val[i]+val[att[i][2]]); 
			if(j>=w[i]+w[att[i][1]]+w[att[i][2]]) f[j]=max(f[j],f[j-w[i]-w[att[i][1]]-w[att[i][2]]]+val[i]+val[att[i][1]]+val[att[i][2]]) ; 
		}
	}
	printf("%d",f[n]);
	return 0;
}
