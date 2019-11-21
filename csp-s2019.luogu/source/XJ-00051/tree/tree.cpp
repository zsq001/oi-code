#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y,a[10000],T,temp[10000];
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	for(int j=0;j<T;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
		}
		for(int i=0;i<n;i++){
			temp[i]=rand();
			if(temp[i]<=n && temp[i]>=1){
				for(int j=0;j<i;j++){
					if(temp[i]==temp[j]){
						i--;
						continue;
					}
				}
			}
			else{
				i--;
				continue;
			}
		}
		for(int i=0;i<n;i++){
			cout<<temp[i]<<" ";
		}
	}
}
