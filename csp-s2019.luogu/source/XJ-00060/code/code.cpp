#include<bits/stdc++.h>
using namespace std;
long long K2CO3,NaHCO3,H2O;
bool CO2[64];

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %lld",&NaHCO3,&K2CO3);
	memset(CO2,0,sizeof(CO2));
	H2O=(1<<NaHCO3-1);
	while(K2CO3+1!=H2O){
		int i=0;
		if(K2CO3+1<H2O){
		CO2[i]=false;
		H2O/=2;	
		}else 
		if(K2CO3+1>=H2O){
		CO2[i]=true;
		H2O+=(H2O/2);		
		}
		i++;
	}
	for(int i=0;i<NaHCO3;i++){
		printf("%d",CO2[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
