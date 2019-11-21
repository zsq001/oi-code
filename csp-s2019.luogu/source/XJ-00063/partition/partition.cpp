#include<stdio.h>
int mod=1073741824;
long long a,b,c,ans=0;
long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n=read(),type=read();
	if(type==0){
		a=read();b=read();ans+=a*a+b*b;
		for(int i=3;i<=n;i++){
			c=read();ans+=c*c;
			if(a>b)
				if(a<c){ans+=2*a*b;b+=a;}
				else{
					ans+=2*c*b;
					c+=b;a=b;b=c;
					c=read();ans+=c*c;
					i++;
				}
			a=b;b=c;
		}
		if(a>b)ans+=2*a*b;
		printf("%lld",ans);
	}
	else{
		int x=read(),y=read(),z=read(),b1=read(),b2=read(),m=read();
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
