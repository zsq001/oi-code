#include<bits/stdc++.h>
using namespace std;
int T,n,ans,p[15],up[4]={0,5,3,2};
void init(){
	ans=n;
	memset(p,0,sizeof(p));
}
int fshun(int num,int &len){
	int nowjust=0;
	int st=len=0;
	for(int i=3;i<=13;++i){
		int l=0,j=i,just=0;
		while(p[j]>=num){
			if(p[j]==num) just++;
			l++,j++;
		}
		if((l>len||just>nowjust)&&l>=up[num]){
			len=l;
			st=i;
			nowjust=just;
		}
	}
	return st;
}
void dfs(int remain,int now){
	if(now>ans) return;
	int t1=0,t2=0,t3=0,t4=0,tmp=0;
	for(int i=1;i<=14;++i){
		if(!p[i]) continue;
		if(p[i]==1) t1++;
		else if(p[i]==2) t2++;
		else if(p[i]==3) t3++;
		else t4++;
	}
	while(t4&&t2>=2) tmp++,t4--,t2-=2;
	while(t4&&t1>=2) tmp++,t4--,t1-=2;
	while(t4&&t2>=1) tmp++,t4--,t2--;
	while(t3&&t2>=1) tmp++,t3--,t2--;
	while(t3&&t1>=1) tmp++,t3--,t1--;
	ans=min(ans,now+tmp+t1+t2+t3+t4);
	if(remain<5) return;
	int st=0,len=0;
	for(int num=3;num>=1;--num){
		if(st=fshun(num,len)){
			for(int k=up[num];k<=len;++k){
				for(int i=st;i+k-1<=st+len-1;++i){
					for(int j=i;j<=i+k-1;++j) p[j]-=num;
					dfs(remain-k*num,now+1); 
					for(int j=i;j<=i+k-1;++j) p[j]+=num;
				}
			}
		}
	}
}
int main()
{
	int x,y;
	cin>>T>>n;
	while(T--){
		init();
		for(int i=1;i<=n;++i){
			cin>>x>>y;
			if(x==1) x=14;
			if(!x) x=1;
			p[x]++;
		}
		dfs(n,0);
		cout<<ans<<endl;
	}
	return 0;
}
