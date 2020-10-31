#include<bits/stdc++.h>
using namespace std;
int city[200000];
int ge[200000];
bool exist=false;
int event_1(int l,int r){
	int ans;
	if(ge[r]!=0)
		return ge[r];
	if(r==l)
	 	return (exist)?city[r]:-city[r];
	if(exist){
		ans=max(event_1(l,r-1),event_1(l,r-1)+city[r]);
		if(ans==event_1(l,r-1)+city[r])exist=false;
	}else{
		ans=max(event_1(l,r-1),event_1(l,r-1)-city[r]);
		if(ans==event_1(l,r-1)-city[r])exist=true;
	}
	return ge[r]=ans;
}
void event_2(int l,int r,int x,int y){
	city[l]=x;
	for(int i=l+1;i<=r;i++){
		city[i]=city[i-1]+y;
	}
}
int main(){
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>city[i];
	}
	while(m--){
		int a,b,c,d,r;
		cin>>r;
		if(r==1){
			exist=false;
			cin>>a>>b;
			cout<<event_1(a,b)<<endl;
		}else
		if(r==2){
			cin>>a>>b>>c>>d;
			event_2(a,b,c,d);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
