#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

int l,n;
struct edge{
	char ch,s;
	int yuan;
}e[27];

bool cmp(edge a,edge b){
	return a.ch<b.ch;
}

int main(){
//	freopen("ticket.in","r",stdin);
//	freopen("ticket.out","w",stdout);
	cin>>l>>n;
	for(int i=1;i<=n;++i) e[i].yuan=0;
	for(int i=1;i<=n;++i) cin>>e[i].ch;
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(e[i].ch=='a'||e[i].ch=='e'||e[i].ch=='i'||e[i].ch=='o'||e[i].ch=='u'){
			e[i].yuan=1;
		}
		else e[i].yuan=0;
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			
			e[i].s=e[i].ch;
		}
	}
	for(int i=1;i<=n;++i){
//		cout<<"ch = "<<e[i].ch<<" ";
//		cout<<"yuan = "<<e[i].yuan;
		cout<<"s = "<<e[i].s;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

/* 
4 6
a t c i s w

a c i s t w
*/
