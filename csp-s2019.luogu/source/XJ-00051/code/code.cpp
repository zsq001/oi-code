#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long js;
void px(int n){
	int before[1000],now[1000],emmm=0,emm=0,temp=0,t;
	for(int i=0;i<js;i++){
		for(int j=i+1;j<js;j++){
			memset(before,0,sizeof(before));
			memset(now,0,sizeof(now));
			int t1=a[i];
			int t=a[j];
			if(i==js-1){
				t=a[0];
			}
			if(t1==0){
				for(int k=0;k<n;k++){
					before[k]=0;
				}
			}
			if(t==0){
				for(int k=0;k<n;k++){
					now[k]=0;
				}
			}
			emmm=0;
			while(t1!=0){
				before[emmm]=t1%10;
				t1/=10;
				emmm++;
			}
			emm=0;
			while(t!=0){
				now[emmm]=t%10;
				t/=10;
				emm++;
			}
			temp=0;
			for(int k=0;k<max(emmm,emm);k++){
				if(before[k]!=now[k]){
					temp++;
				}
			}
			if(temp==1){
				swap(a[i+1],a[j]);
				break;
			}
		}
	}
	return;
}	
void pl(){
	int k=10,t=0,i;
	for(i=1;i<js;i++){
		a[i]=a[i-1]+1;
		while((a[i]%k)*10/k>=2){
			a[i]=a[i]-(a[i]%k);
			a[i]+=k;
			k*=10;
		}
		k=10;
	}
	return;
}
int main(){
	long long n,k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	js=pow(2,n);
	a[0]=0;
	pl();
	px(n);
	int temp=a[k-1],t=0;
	while(temp!=0){
		temp/=10;
		t++;
	}
	for(int j=0;j<n-t;j++){
		cout<<"0";
	}
	cout<<a[k-1];
	return 0;
}
