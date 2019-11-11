#include<bits/stdc++.h>
using namespace std;
bool black_tea[10000000]={0};
int m,czy;
void event(int a){
	int number;
	int last_i;
	switch(a){
		case 1: 
			cin>>number;
			black_tea[number]=true;
			if(czy)black_tea[number]^=black_tea[last_i];
			last_i=number;
			break;
		
		case 3:
			for(int i=0;i<m;i++){
				if(!(black_tea[i])){
					black_tea[i]=true;
					break;
				}

			}
			break;
		case 2:
			cin>>number;
			if(black_tea[number])
				black_tea[number]=false;
			if(czy)black_tea[number]^=black_tea[last_i];
			last_i=number;
			break;
		case 4:
			for(int i=0;i<m;i++){
				if(!(black_tea[i])){
					cout<<i<<endl;
					break;
				}
			}
			break;
		default:
		 break;
	}
		
}
int main(){
//	scanf("%d %d",&m,&czy);

	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	cin>>m>>czy;
	int o=m;
	while(o--){
		int a,number=0;
		cin>>a;
		event(a);
	}
	
	return 0;
}
