#include<bits/stdc++.h>
using namespace std;
int n,x[20],y[20],a[20],l[20],r[20],ans;
struct edge{
	int loca,num;
}use[20];
bool cmp(edge x,edge y){
	return x.num<y.num;
}
bool judgeempty(){
	int jecnt=0;
	for(int jei=1;jei<=n;jei++){
		if(use[jei].num==0) jecnt++;
	}
	if(jecnt==n) return false;
	else return true;
}
int toans(int x){
	return pow(x,2);
}
int main () {
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	cin>>n;
	a[0]=-214748364;
	a[n+1]=214748364;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	if(x[1]==x[2]){
		for(int i=1;i<=n;i++){
			a[i]=y[i];
		}
	}
	if(y[1]==y[2]){
		for(int i=1;i<=n;i++){
			a[i]=x[i];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		l[i]=a[i]-a[i-1];
		r[i]=a[i+1]-a[i];
		use[i].num=min(l[i],r[i]);
		use[i].loca=i;
	}
	sort(use+1,use+1+n,cmp);	
	while(judgeempty()){
		ans+=toans(use[n].num);
		for(int frontloca=1;frontloca<=n;frontloca++){
			if(use[frontloca].loca==use[n].loca-1){
				use[frontloca].num=0;
			}
		}
		for(int nextloca=1;nextloca<=n;nextloca++){
			if(use[nextloca].loca==use[n].loca-1){
				use[nextloca].num=0;
			}
		}
		use[n].num=0;
		sort(use+1,use+1+n,cmp);
	}
	cout<<ans<<endl;
	return 0;
	}

