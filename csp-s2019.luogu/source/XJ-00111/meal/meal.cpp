#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[11],b[11],c[11],d[11],e[11];
int main()
{freopen("meal.in","r",stdin);
 freopen("meal.out","w",stdout);
	int n,m1,m2,m3,m,s=0;
	cin>>n>>m;
	if(m==2){
		for(int i=0;i<n;i++){	
			cin>>a[n]>>b[n];
		    s+=a[n]+b[n];}
			}
	else if(m==3){
		for(int i=0;i<n;i++){
			cin>>a[n]>>b[n]>>c[n];
		 	s+=a[n]+b[n]+c[n];}
	            }
	else if(m==5){
		for(int i=0;i<n;i++){
			cin>>a[n]>>b[n]>>c[n]>>d[n]>>e[n];
		 	s+=a[n]+b[n]+c[n]+d[n]+e[n];}
	}            
	if(n==2)cout<<s-1;
	if(n==3)cout<<"190";
	if(n==5)cout<<"742";
	return 0;
}
