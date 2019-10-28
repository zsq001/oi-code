#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],countt[1010],jd;
int main () {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]%3==0&&a[j]!=0) {
			j--,n--,countt[i]++;
			}
		}
		if(n>=4){
			for(int j=1;j<=n;j++){
			if(jd==1) jd=0;
			for(int k=j+1;k<=n;k++){
				if(jd==1) break;
				for(int l=k+1;l<=n;l++){
					if(jd==1) break;
					for(int y=l+1;y<=n;y++){
						if(jd==1) break;	
						if((a[j]+a[k])%3==0&&a[j]+a[k]!=0){
						a[j]=0;
						a[k]=0;
						countt[i]++;
						jd=1;
						break;
						}
					if((a[j]+a[k]+a[l])%3==0&&a[j]+a[k]+a[l]!=0){
						a[j]=0;
						a[k]=0;
						a[l]=0;
						countt[i]++;
						jd=1;
						break;
						}
					if((a[j]+a[k]+a[l]+a[y])%3==0&&a[j]+a[k]+a[l]+a[y]!=0){
						a[j]=0;
						a[k]=0;
						a[l]=0;
						a[y]=0;
						countt[i]++;
						jd=1;
						break;
						}
					}
					
				}
				
			}
		}
		}
		if(n==3){
			for(int j=1;j<=n;j++){
			if(jd==1) jd=0;
			for(int k=j+1;k<=n;k++){
				if(jd==1) break;
				for(int l=k+1;l<=n;l++){
					if(jd==1) break;
					
						
						if((a[j]+a[k])%3==0&&a[j]+a[k]!=0){
						a[j]=0;
						a[k]=0;
						countt[i]++;
						jd=1;
						break;
						}
					if((a[j]+a[k]+a[l])%3==0&&a[j]+a[k]+a[l]!=0){
						a[j]=0;
						a[k]=0;
						a[l]=0;
						countt[i]++;
						jd=1;
						break;
						}
					
					
					
				}
				
			}
		}
		}
		if(n==2){
			for(int j=1;j<=n;j++){
			
			for(int k=j+1;k<=n;k++){
				
				
						if((a[j]+a[k])%3==0&&a[j]+a[k]!=0){
						a[j]=0;
						a[k]=0;
						countt[i]++;
						
						break;
						}
					
						}
					
					
				
				
			
		}
		}
	}
	for(int i=1;i<=T;i++) cout<<countt[i]<<endl;
	return 0;
}
