#include<cstdio>
int map[65];
int mapp[1000010];
long long num;
long long ksm(long long n,long long m){
	long long ans=1;
	while(m){
		if(m&1){
			ans=ans*n;
		}
		n=n*n;
		m>>=1;
	}
	return ans;
}

void cha(long long x){
	int tot=64;
	while(x!=0){
		map[tot]=x%2;
		x=x/2;
		tot--;
	}
}

void cha2(long long x){
	int tot=64;
	map[0]=1;
	while(x!=0){
		map[tot]=x%2;
		x=x/2;
		tot--;
	}
}

int abs(int x){
	if(x<0)return -x;
	return x;
}

int ws(int x,int i){
	x=x+ksm(2,i);
	return x;
}

int main()
{
	int bu;
	int n,k,nn;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	mapp[0]=0,mapp[1]=1;
	for(int i=2;i<=n;i++){
		int l=0;
		num=ksm(2,i);
		int mun=ksm(2,i-1);
		for(int j=num-1;j>=mun;j--){
			mapp[j]=ws(mapp[l],i-1);
			l++;
		}
	}
	num=ksm(2,n-1);
	if(k < num){
		cha(mapp[k]);
		for(int i=64-n+1;i<=64;i++){
			printf("%d",map[i]);
		}
		return 0;
	}
	else {
		long long x;
		x=k-num-1;
		x=abs(x);
		num=num+x+1;
		cha2(mapp[num]);
		for(int i=64-n+1;i<=64;i++){
			printf("%d",map[i]);
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}
