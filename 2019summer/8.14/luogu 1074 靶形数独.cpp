#include<bits/stdc++.h>
using namespace std;
const int inf=1<<29;
struct Cell{
	int x,y,tot,list[10];
}a[90];
int now,ans=-1,cnt,b[10],c[10],d[10],vis[90],mp[10][10],e[10][10]={{},{0,1,1,1,2,2,2,3,3,3},{0,1,1,1,2,2,2,3,3,3},{0,1,1,1,2,2,2,3,3,3},{0,4,4,4,5,5,5,6,6,6},{0,4,4,4,5,5,5,6,6,6},{0,4,4,4,5,5,5,6,6,6},{0,7,7,7,8,8,8,9,9,9},{0,7,7,7,8,8,8,9,9,9},{0,7,7,7,8,8,8,9,9,9}};
int w[10][10]={{},{0,6,6,6,6,6,6,6,6,6},{0,6,7,7,7,7,7,7,7,6},{0,6,7,8,8,8,8,8,7,6},{0,6,7,8,9,9,9,8,7,6},{0,6,7,8,9,10,9,8,7,6},{0,6,7,8,9,9,9,8,7,6},{0,6,7,8,8,8,8,8,7,6},{0,6,7,7,7,7,7,7,7,6},{0,6,6,6,6,6,6,6,6,6}};
int F(int x,int k){return x&(1<<k);}
bool exist(int i,int j,int k){return F(b[i],k)||F(c[j],k)||F(d[e[i][j]],k);}
bool fl(int i,int j,int k){
	if(exist(i,j,k)) return false;
	b[i]|=1<<k,c[j]|=1<<k,d[e[i][j]]|=1<<k;
	return true;
}
bool cmp(Cell X,Cell Y){
	if(X.tot!=Y.tot) return X.tot<Y.tot;
	if(X.x!=Y.x) return X.x>Y.x;
	return X.y>Y.y;
}
void dfs(int f,int sum){
	if(sum>cnt){
		ans=max(ans,now);
		return;
	}
	vis[f]=1;
	int x=a[f].x,y=a[f].y,flag=1;
	for(int i=1;i<=a[f].tot;++i){
		int k=a[f].list[i],minx=10,id=0;
		if(fl(x,y,k)){
			flag=1;
			now+=w[x][y]*k;
			for(int j=1;j<=cnt;++j){
				if(vis[j]) continue;
				int cd=a[j].tot,X=a[j].x,Y=a[j].y;
				for(int l=1;l<=a[j].tot;++l){
					int num=a[j].list[l];
					if(exist(X,Y,num)) cd--;
				}
				if(!cd){
					flag=0;
					break;
				}
				if(cd<minx){
					minx=cd;
					id=j;
				}
				if(cd==1) break;
			}
			if(flag) dfs(id,sum+1);
			now-=w[x][y]*k;
			b[x]^=1<<k,c[y]^=1<<k,d[e[x][y]]^=1<<k;
		}
	}
	vis[f]=0;
}
int main()
{
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j){
			int x;
			cin>>x;
			if(x) fl(i,j,x);
			mp[i][j]=x;
			now+=w[i][j]*x;
		}
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j){
			if(mp[i][j]) continue;
			a[++cnt].x=i;
			a[cnt].y=j;
			for(int k=1;k<=9;++k)
				if(!exist(i,j,k))
					a[cnt].list[++a[cnt].tot]=k;
		}
	sort(a+1,a+cnt+1,cmp);
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
