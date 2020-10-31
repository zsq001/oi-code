#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define dfsnext(x,y,v) y==2?dfs(x-1,1,v):dfs(x,y+1,v)
using namespace std;
int a[30],b[30],c[30],used[30],v[30],n,mx;
char ch[30];
void change(int t[])
{
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i) t[i]=ch[i]-'A';
}
void dfs(int x,int y,int val)
{
	int t1=v[a[x]],t2=v[b[x]],t3=v[c[x]];
	for(int i=1;i<=x;++i){
		int tt1=v[a[i]],tt2=v[b[i]],tt3=v[c[i]];
		if(tt1==-1||tt2==-1||tt3==-1) continue;
		if(((tt3-tt2-tt1)%n+n)%n>mx) return;
	}
	if(!x){
		for(int i=0;i<n;++i) printf("%d ",v[i]);
		exit(0);
	}
	if(y==1){
		if(v[a[x]]!=-1) dfsnext(x,y,val);
		else for(int i=n-1;i>=0;--i)
				if(!used[i]){
					used[i]=1;
					v[a[x]]=i;
					dfsnext(x,y,val);
					v[a[x]]=-1;
					used[i]=0;
				}
	}
	else{
		if(v[b[x]]!=-1){
			int sum=t1+t2+val,ssum=sum-sum/n*n;
			if(ssum==t3) dfsnext(x,y,sum/n);
			else if(t3==-1){
				used[ssum]=1;
				v[c[x]]=ssum;
				dfsnext(x,y,sum/n);
				v[c[x]]=-1;
				used[ssum]=0;
			}
		}
		else
			for(int i=n-1;i>=0;--i)
				if(!used[i]){
					int sum=t1+i+val,ssum=sum-sum/n*n;
					if(ssum!=t3&&t3!=-1) continue;
					if(t3==-1){
						if(used[ssum]) continue;
						used[ssum]=1;
						v[c[x]]=ssum;
					}
					used[i]=1;
					v[b[x]]=i;
					dfsnext(x,y,sum/n);
					v[b[x]]=-1;
					used[i]=0;
					if(t3==-1){
						used[ssum]=0;
						v[c[x]]=-1;
					}
				}
	}
}
int main()
{
	scanf("%d",&n);
	mx=2*(n-1)/n;//进位值修正
	change(a);
	change(b);
	change(c);
	for(int i=0;i<=n;++i) v[i]=-1;
	dfs(n,1,0);
	return 0;
}
