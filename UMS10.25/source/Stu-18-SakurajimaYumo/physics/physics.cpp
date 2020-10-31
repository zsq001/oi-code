#include<bits/stdc++.h>
using namespace std;
int n;
double s1,s2,v0;
struct edge{
	double v,t;
}part[100010];
bool cmp(edge a,edge b){
	return a.v>b.v;
}
int main () {
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	part[0].v=0;
	part[0].t=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>part[i].v>>part[i].t;
	}
	for(int i=1;i<=n;i++){
		v0+=part[i-1].v*part[i-1].t;
		s1+=v0*part[i].t+0.5*part[i].v*pow(part[i].t,2);
//		cout<<"i="<<i<<endl;
//		cout<<"part[i].t="<<part[i].t<<endl;
//		cout<<"part[i].v="<<part[i].v<<endl;
//		cout<<"v0="<<v0<<endl;
//		cout<<"v0*part[i].t="<<v0*part[i].t<<endl;
//		cout<<"0.5*part[i].v*pow(part[i].t,2)="<<0.5*part[i].v*pow(part[i].t,2)<<endl;
//		cout<<v0*part[i].t+0.5*part[i].v*pow(part[i].t,2)<<endl;
	};
	sort(part+1,part+1+n,cmp);
	v0=0;
	for(int i=1;i<=n;i++){
		v0+=part[i-1].v*part[i-1].t;
		s2+=v0*part[i].t+0.5*part[i].v*pow(part[i].t,2);
	};
//	cout<<s1<<" "<<s2<<endl;
	printf("%.1lf",s2-s1);
}
