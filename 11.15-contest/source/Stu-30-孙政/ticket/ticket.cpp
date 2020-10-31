#include<bits/stdc++.h>
using namespace std;
char zimu[30],arr[20];
bool flag[30];
int L,C;
void dfs(int pos){
	if(pos==L){
		for(int i=0;i<L;i++)
			cout<<arr[i]<<' ';
		cout<<endl;
		return;
	}
	flag[pos]=true;
	arr[pos]=zimu[pos];
	if(!flag[pos+1])
	 dfs(pos+1);
	flag[pos]=false;
}

int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);

	scanf("%d %d",&L,&C);
	for(int i=0;i<C;i++){
		char ni;
		cin>>ni;
		zimu[i]=ni;
	}
	
	for(int i=0;i<C;i++){
		for(int j=1;j<C;j++){
			if(zimu[i]>zimu[j]){
			zimu[29]=zimu[i];
			zimu[i]=zimu[j];
			zimu[j]=zimu[29];	
			}
		}
	}
	dfs(0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
