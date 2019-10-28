#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int T,n,w,ans,ret,p[15],up[4]={0,5,3,2};
void init()
{
	w=ret=0;
	ans=n;
	memset(p,0,sizeof(p));
}
bool fshun(register int &st,register int num,register int &len)
{
	st=len=0;
	register int nowgd=0;
	for(register int i=3;i<=13;++i){
		register int t=0,j=i,gd=0;
		while(p[j]>=num){
			if(p[j]==num) gd++;
			t++,j++;
		}
		if((t>len||gd>nowgd)&&t>=up[num]){
			len=t;
			st=i;
			nowgd=gd;
		}
	}
	if(st) return true;
	return false;
}
void dfs(register int rm,register int now)
{
	if(now>ans) return;
	register int t1=0,t2=0,t3=0,t4=0,tmp=0;
	for(register int i=1;i<=14;++i){
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
	if(rm<5) return;
	register int st=0,num=0,len=0;
	for(num=3;num>=1;--num){
		if(fshun(st,num,len)){
			for(register int k=up[num];k<=len;++k){
				for(register int i=st;i+k-1<=st+len-1;++i){
					for(register int j=i;j<=i+k-1;++j) p[j]-=num;
					dfs(rm-k,now+1); 
					for(register int j=i;j<=i+k-1;++j) p[j]+=num;
				}
			}
		}
	}
}
int main()
{
	register int x,y;
	scanf("%d%d",&T,&n);
	while(T--){
		init();
		for(register int i=1;i<=n;++i){
			scanf("%d%d",&x,&y);
			if(x==1) x=14;
			if(!x) x=1;
			p[x]++;
		}
		dfs(n,ret);
		printf("%d\n",ans);
	}
	return 0;
}
