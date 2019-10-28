#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string str0,str;
int p[401000];
int n[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
struct STR{
	int l,r;
}Q[2001000];
void manacher(){
	int mx=0,id=0;
	for(int i=1;i<=str.length();++i){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while(str[i-p[i]]==str[i+p[i]])p[i]++;
		if(i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
	int cnt=0,ans=0;
	for(int i=1;i<=str.length();i++)--p[i];
	for(int i=1;i<=str.length();i++)
		while(p[i]>0)Q[++cnt]=(STR){i-p[i]+1,i+p[i]-1},----p[i];	
		
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			if(Q[i].r<Q[j].l)++ans;
	printf("%d",ans);
	return ;
}
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>str0;
	str+="$#";
	for(int i=0;i<str0.length();++i){
		str+=str0[i];
		str+="#";
	}
	manacher();	
	return 0;
}
