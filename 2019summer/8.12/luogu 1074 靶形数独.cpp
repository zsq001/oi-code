#include<cstdio>
#include<iostream>
#include<cstring> 
#include<algorithm>
#include<cmath>
#define calg(x,y) ((x-1)/3)*3+(y-1)/3+1
using namespace std;
int cnt,ans=-1,now,vis[90],score[10][10][10],mp[10][10],MP[10][10],r[10],c[10],g[10],w[10][10]={{},{0,6,6,6,6,6,6,6,6,6},{0,6,7,7,7,7,7,7,7,6},{0,6,7,8,8,8,8,8,7,6},{0,6,7,8,9,9,9,8,7,6},{0,6,7,8,9,10,9,8,7,6},{0,6,7,8,9,9,9,8,7,6},{0,6,7,8,8,8,8,8,7,6},{0,6,7,7,7,7,7,7,7,6},{0,6,6,6,6,6,6,6,6,6}};
struct Ge{
	int x,y,ccnt;
	int list[10];
}a[90];
bool cmp(Ge X,Ge Y){
	if(X.ccnt!=Y.ccnt) return X.ccnt<Y.ccnt;
	if(X.x!=Y.x) return X.x<Y.x;
	return X.y<Y.y;
}
inline bool fill(int x,int y,int val){
	if(r[x]&(1<<val)||c[y]&(1<<val)||g[calg(x,y)]&(1<<val)) return false; 
	r[x]|=1<<val,c[y]|=1<<val,g[calg(x,y)]|=1<<val;
	now+=score[x][y][val];
	return true;
}
void dfs(int f,int sum){
	if(sum>cnt){
		ans=max(now,ans);
		return;
	}
	vis[f]=1; 
	int x=a[f].x,y=a[f].y,flg=1;
	for(int j=1;j<=a[f].ccnt;++j){
		int i=a[f].list[j],minx=10,zb=0;
		if(fill(x,y,i)){
			flg=1; 
			for(int k=1;k<=cnt;++k){
				if(vis[k]) continue; 
				int cd=a[k].ccnt,xx=a[k].x,yy=a[k].y;
				for(int l=1;l<=a[k].ccnt;++l){
					int nnum=a[k].list[l];
					if(r[xx]&(1<<nnum)||c[yy]&(1<<nnum)||g[calg(xx,yy)]&(1<<nnum)) cd--;
				}
				if(!cd){
					flg=0;
					break; 
				};
				if(cd<minx){
					minx=cd;
					zb=k;
				}
				if(cd==1) break;
			}
			if(flg) dfs(zb,sum+1);
			r[x]^=1<<i,c[y]^=1<<i,g[calg(x,y)]^=1<<i;
			now-=score[x][y][i]; 
		}
	}
	vis[f]=0; 
}
int main()
{
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
			for(int k=1;k<=9;++k)
				score[i][j][k]=w[i][j]*k;
	for(int i=9;i>0;--i)
		for(int j=9;j>0;--j){
			cin>>mp[i][j];
			fill(i,j,mp[i][j]);
		}
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j){
			if(mp[i][j]) continue;
			a[++cnt].x=i;
			a[cnt].y=j;
			for(int k=1;k<=9;++k){
				if(r[i]&(1<<k)||c[j]&(1<<k)||g[calg(i,j)]&(1<<k)) continue;
				else a[cnt].list[++a[cnt].ccnt]=k;
			}
		}
	sort(a+1,a+cnt+1,cmp);
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
