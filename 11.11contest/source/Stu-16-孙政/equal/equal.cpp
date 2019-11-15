#include<bits/stdc++.h>
using namespace std;

int N,M;
int city[100001]={0};

int jisuan(int x,int y){
	if(y==x)
		return N-1;
	else 
		return ((y-x)/2)+1;
}

void event(bool xuqiu,int x,int y){
	if(xuqiu){
		if(city[y]==x)
			cout<<'0'<<endl;
		else
			cout<<jisuan(x,y)<<endl;
	}else{
		city[y]=x;
	}
	return ;
}

int main(){
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	cin>>N;
	int o=N-1;
	while(o--){
		int F,T;
		cin>>F>>T;
		event(false,F,T);
	}
	cin>>M;
	while(M--){
		int A,B;
		cin>>A>>B;
		event(true,A,B);
	}
	return 0;
}
