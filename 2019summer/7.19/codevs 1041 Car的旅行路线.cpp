#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
double ans,T[110],f[110][9][110][9],px[110][110],py[110][110],b1,b2,b3;
int n,s,t,A,B,x1,y11,x2,y2,x3,y3,x4,y4,i,j,k,l,u,v;
int p(int x)
{
	return x*x;
}
inline void init()
{
	ans=1<<30;
	memset(f,0,sizeof(f));
}
int main()
{
	cin>>n;
	while(n--){
		init();
		cin>>s>>t>>A>>B;
		for(i=1;i<=s;++i){
			cin>>x1>>y11>>x2>>y2>>x3>>y3>>T[i];
			b1=sqrt(p(x2-x1)+p(y2-y11)),b2=sqrt(p(x3-x2)+p(y3-y2)),b3=sqrt(p(x3-x1)+p(y3-y11));
			if(b1>=b2&&b1>=b3) x4=x1+x2-x3,y4=y11+y2-y3;
			else if(b2>=b1&&b2>=b3) x4=x2+x3-x1,y4=y2+y3-y11;
			else x4=x1+x3-x2,y4=y11+y3-y2;
			px[i][1]=x1,py[i][1]=y11,px[i][2]=x2,py[i][2]=y2,px[i][3]=x3,py[i][3]=y3,px[i][4]=x4,py[i][4]=y4;
		}
		for(i=1;i<=s;++i)
			for(j=1;j<=4;++j)
				for(k=1;k<=s;++k){
					if(i==k) continue;
					for(l=1;l<=4;++l)
						f[i][j][k][l]=sqrt(p(px[i][j]-px[k][l])+p(py[i][j]-py[k][l]))*t;
				}
		for(i=1;i<=s;++i)
			for(j=1;j<=4;++j)
				for(k=1;k<=4;++k)
					f[i][j][i][k]=sqrt(p(px[i][j]-px[i][k])+p(py[i][j]-py[i][k]))*T[i];
		for(i=1;i<=s;++i)
			for(j=1;j<=4;++j)
				for(k=1;k<=s;++k)
					for(l=1;l<=4;++l)
						for(u=1;u<=s;++u)
							for(v=1;v<=4;++v) f[k][l][u][v]=min(f[k][l][u][v],f[k][l][i][j]+f[i][j][u][v]);
		for(i=1;i<=4;++i)
			for(j=1;j<=4;++j)
				ans=min(ans,f[A][i][B][j]);
		printf("%.1lf\n",ans);
	}
	return 0;
}
