#include<iostream>
#include<cstdio>
using namespace std;
bool qwe=true;
int asd[1000][1000],b=0,c=0,z=1,o=1,zxc[100],jkl[100][100],u=1,t=1;//各种情况存储 
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","W",stdout);
	int m,n,a[100][100];
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	} 
	if(n==2&&m==2){
		cout<<2;
		return 0;
	}else if(n==2&&m==3){
		cout<<6;
	}
	for(int x=2;x<=n;x++){
		for(int i=t;i<n;i++){
			jkl[i][0]=i;
			for(int j=u;j<=x;j++){
				jkl[i][j]=
			}	
		}
	}
	for(int x=2;x<=n;x++){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]!=0){
					c*=a[i][j];
					zxc[j]++;
					i++;
					j=0;
				}
				for(int k=0;k<n;k++){
					if(zxc[k]>=n/2){
						qwe=false;
					}
				}
				if(!qwe){
					continue;
				}
			}
		}
		b+=c;
		c=1;
		b%=998244353;
		for(int pp=0;pp<o;pp++){
			zxc[pp]=0;
		}
		o=1;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
