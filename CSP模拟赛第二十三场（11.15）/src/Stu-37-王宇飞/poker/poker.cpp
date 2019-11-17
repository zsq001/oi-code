#include<bits/stdc++.h>
using namespace std;
int use,n,m,num[60],poker[60][1000100],cnt,ccnt,maxnum,minnum=0x7fffffff,zbmin,zbmax,ans;
bool cheak(){
	for(int i=1;i<=n;i++){
		if(poker[1][i]==0) ccnt++;
		
	}
	if(ccnt>=2) return false;
	else{
		ccnt=0;
		return true;
	}
}
int main (){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			poker[j][i]=1;
		}
	}
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=n;j++){
//			cout<<poker[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(cheak()&&m!=0){
		minnum=0x7fffffff;
		maxnum=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			minnum=min(minnum,num[i]);
			if(num[i]==minnum) zbmin=i;
		}//find the shortest
		for(int i=1;i<=n;i++){
			maxnum=max(maxnum,num[i]);
			if(num[i]==maxnum) zbmax=i;
		}//the longest
		if(m>0){
			--m;
			poker[1][zbmin]=2;
			poker[num[zbmin]+1][zbmin]=1;
			use=1;
		}//use poker to fix the shortest
		for(int i=1;i<=n;i++){
			if(poker[1][i]){
				cnt++;
			}
			if(cnt==n){
				ans++;
				for(int i=2;i<=maxnum+1;i++){
					for(int j=1;j<=n;j++){
						poker[i-1][j]=poker[i][j];
					}
				}
				for(int k=1;k<=n;k++) {
					if(k!=zbmin) num[k]--;
					if(k==zbmin&&use==0) num[k]--;
				}
				use=0;
			}
	}
//		for(int i=1;i<=maxnum;i++){
//				for(int j=1;j<=n;j++){
//				cout<<poker[i][j]<<" ";
//				}
//				cout<<endl;
//				}
//				cout<<"_____________________"<<endl;
	}
	cout<<ans;
	return 0;	
}
