#include<bits/stdc++.h>
using namespace std;
int balabala[100];
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int T,int N,lucky_n=0;
	scanf("%d",&T);
	while(T--){
		lucky_n=0;
		scanf("%d",&N);
		memset(balabala,0,sizeof(balabala));
		for(int i=1;i<N;i++){
			int A,B;
			cin>>A>>B;
			balabala[A]++;
			balabala[B]++;
		}
		for(int i=1;i<N;i++){
			lucky_n+=balabala[i];
		}
		cout<<lucky_n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
