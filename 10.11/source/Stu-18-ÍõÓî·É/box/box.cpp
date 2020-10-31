#include<iostream>
#include<math.h>
using namespace std;
int v,s,mina,minb,minc,mins=2147483640;
int main () {
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	cin>>v;
	if(v<=1000){
		for(int a=1;a<=v;a++){
		for(int b=1;b<=v/a;b++){
			for(int c=1;c<=v/(b*a);c++){
				if(a*b*c==v){
					s=2*(a*b+a*c+b*c);
					mins=min(s,mins);
//					if(s==mins){
//						mina=a;
//						minb=b;
//						minc=c;
//					}
				}
			}
		}
	}
	cout<<mins<<endl;
	//cout<<mina<<" "<<minb<<" "<<minc<<" ";
	}
	else{
		for(int i=1;i<=sqrt(v);i++){
			if(pow(i,3)==v){
				cout<<i*i*6<<endl;
			}
		}
	}
	return 0;
}
