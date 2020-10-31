#include<bits/stdc++.h>
#define maxn 200010
#define inf 1<<29
using namespace std;
typedef long long ll;
queue<int>Q; 
int n,ans,next[maxn],rd[maxn],x,cnt,v,vis[maxn];
int main(){
    cin>>n;
    ans=n;
    for(int i=1;i<=n;++i){
    	cin>>next[i];
    	rd[next[i]]++;
    }
	for(int i=1;i<=n;++i)
		if(!rd[i])
			Q.push(i);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		v=next[x];
		rd[v]--;
		if(!rd[v]) Q.push(v);
	} 
	for(int i=1;i<=n;++i){
		if(rd[i]){
			cnt=1;
			v=next[i];
			while(v!=i){
				rd[v]=0;
				v=next[v];
				cnt++;
			}
			
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}

