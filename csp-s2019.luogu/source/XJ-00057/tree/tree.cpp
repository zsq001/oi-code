#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int count[2005];
int a[2005];
int n;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		vector<int>s[2005];
		memset(count,0,sizeof(count));
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>count[i];//≥ı º±‡∫≈
		a[count[i]]=i;
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		s[x].push_back(y);
		s[y].push_back(x);
	}
	for(int i=n;i>=1;i--){ 
		if(a[i]<a[i-1]){
			int sp=a[i];
			a[i]=a[i-1];
			a[i-1]=sp; 
		}
	}
	for(int i=n;i>=1;i--)
		cout<<a[i]<<" ";
	cout<<endl;
	}
return 0;
}
