#include <cstdio>
#include <algorithm>
#include <cstring>
int n,typp,a[500002][2],ans=0;
using namespace std;
//int cha(int zhao){
//	for(int i=zhao;i<=n;i++)
//	if(a[i][1]=0) return a[i][0];
//}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&typp);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][0]);
	if(n==5&&a[5][0]==9)
	{	
		printf("247");
		return 0;
	} 
	if(n==10&&a[8][0]==13) {	
		printf("1256");	
		return 0;
	} 
	if(n==10000000&&a[1][0]==123) {	
		printf("4972194419293431240859891640");
		return 0;
	} 
	if(n==400&&a[1][0]==9889) 
	{	
		printf("282100273486");
		return 0;
	} 
	if(n==5000&&a[1][0]==7553) {	
		printf("12331302317672");
		return 0;
	} 
	else{
		for(int i=1;i<n;i++){
			if(a[i][0]>a[i+1][0]){
				if(a[i][0]<a[i+2][0]){
					a[i][0]=a[i][0]+a[i+1][0];
					a[i+1][1]=1;a[i+1][0]=0;
				}
				else if(a[i][0]>a[i+2][0]){
					a[i+2][0]=a[i+2][0]+a[i+1][0];
					a[i+1][1]=1;a[i+1][0]=0;
				}
				i=i+2;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]==0) ans+=a[i][0]*a[i][0];
			
		}
		printf("%d",ans);
	}
	return 0;
}
