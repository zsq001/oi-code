#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#define inf 1<<29
#define maxn 310
#define eps 1e-6
using namespace std;
map<string,int>smp;
struct Lover{
	double x,y;
	string name;
}a[40],b[40];
double K;
int n,mp[40][40],slack[40],visa[40],visb[40],exa[40],exb[40],match[40];
void change(string &s)
{
	int len=s.size();
	for(int i=0;i<len;++i) if(s[i]<='Z') s[i]+=32;
}
double cal(Lover x,Lover y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
bool check(int x,int y)
{
	double dis=cal(a[x],b[y]);
	if(dis-K>eps) return false;
	for(int i=1;i<=n;++i){
		if(i==x) continue;
		if(cal(a[x],a[i])+cal(a[i],b[y])-dis<eps) return false;
	}
	for(int i=1;i<=n;++i){
		if(i==y) continue;
		if(cal(a[x],b[i])+cal(b[i],b[y])-dis<eps) return false;
	}
	return true;
}
bool xyl(int x)
{
	visa[x]=1;
	for(int i=1;i<=n;++i){
		if(visb[i]) continue;
		int gap=exa[x]+exb[i]-mp[x][i];
		if(!gap){
			visb[i]=1;
			if((match[i]==-1)||xyl(match[i])){
				match[i]=x;
				return true;
			}
		}
		else slack[i]=min(slack[i],gap);
	}
	return false;
}
int KM()
{
	memset(match,-1,sizeof(match));
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) exa[i]=max(exa[i],mp[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) slack[j]=inf;
		while(1){
			memset(visa,0,sizeof(visa));
			memset(visb,0,sizeof(visb));
			if(xyl(i)) break;
			int d=inf;
			for(int j=1;j<=n;++j) if(!visb[j]) d=min(d,slack[j]);
			for(int j=1;j<=n;++j){
				if(visa[j]) exa[j]-=d;
				if(visb[j]) exb[j]+=d;
				else slack[j]-=d;
			}
		}
	}
	int ans(0);
	for(int i=1;i<=n;++i) ans+=mp[match[i]][i];
	return ans; 
}
int main()
{
	int w;
	string s1,s2;
	cin>>K>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i].x>>b[i].y>>s1;
		change(s1);
		smp[s1]=i+n;
		b[i].name=s1;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>s1;
		change(s1);
		smp[s1]=i;
		a[i].name=s1;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(check(i,j)) mp[i][j]=1;else mp[i][j]=-inf;
	while(cin>>s1){
		if(s1=="End") break;
		cin>>s2>>w;
		change(s1),change(s2);
		int id1=smp[s1],id2=smp[s2];
		if(id1>id2) swap(id1,id2);
		if(id2<=n) continue;
		if(id1>n) continue;
		if(check(id1,id2-n)) mp[id1][id2-n]=max(w,1);
	}
	cout<<KM()<<endl;
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) printf("%d ",mp[i][j]);
		puts("");
	}
	for(int i=1;i<=n;++i) printf("%d\n",match[i]);*/
	return 0;
}
