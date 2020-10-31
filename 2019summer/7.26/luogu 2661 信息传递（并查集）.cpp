#include<bits/stdc++.h>
#define maxn 200010
#define inf 1<<29
using namespace std;
typedef long long ll;
queue<int>Q; 
int n,ans,next[maxn],fa[maxn],x,cnt,v;
int get(int x){
	cnt++;
	if(fa[x]==x) return x;
	return get(fa[x]);
}
int main(){
    cin>>n;
    ans=n;
    for(int i=1;i<=n;++i){
    	cin>>next[i];
    	fa[i]=i;
    }
	for(int i=1;i<=n;++i){
		cnt=0;
		if(get(next[i])==i) ans=min(ans,cnt);
		else fa[i]=next[i];
	}
	cout<<ans<<endl;
	return 0;
}
