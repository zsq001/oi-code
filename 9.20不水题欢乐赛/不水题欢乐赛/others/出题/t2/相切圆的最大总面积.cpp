/*
给定平面上n个点 求以这些点为圆心的互不相交的圆的最大总面积

 
//0.确定联通块？？？？？？？ 
	1.枚举 圆的顺序 设c[i]与之前的圆相切 -------------------------------------------O(n!)
		2.设圆c[0]半径为r
		3.则c[1]半径为d01-r
		4.则c[2]半径为min（d02-r，d12-r1==d12-（d01-r）==d12-d01+r）
			5.设c[j]与c[i]相切(i<j) {or c[j]~c[n-1]与c[0]~c[j-1]均不连通（进行(7)(8)后转(2)）} --------------------------------------O(n!)
			6.则c[j]半径为dij-rj==aj+（-）r //rj>=0确定r的区间 
			7.则S/PI =add（rk^2） == add(ak^2+r^2+(-)2*ak*r)==add(ak^2)+2*add(ak)*r+n*r^2
			8.求Smax 
			
	-----------------------------------O(n!^2)
	 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
int fa[100],b[100],n,c[100],fr[100];
double a[100],s[100],minr[100],maxr[100],xx[100],yy[100],S,rr[100];
void sol(int x){
	//printf("sol[%d,%d](%.2lf,%.2lf)",x,fa[x],minr[fa[x]],maxr[fa[x]]);
	double A_2=0,A=0;
	for(int i=fa[x];i<=x;i++){
		A_2+=a[i]*a[i];
		A+=a[i]*b[i];
	}
	A*=2;
	//(x-fa[x]+1)*r^2+A*r+A_2
	double X0=-A/2/(x-fa[x]+1),r=0;
	if(X0<minr[fa[x]]){
		r=minr[fa[x]];
		s[x]=(x-fa[x]+1)*r*r+A*r+A_2;
	}
	else if(X0<maxr[fa[x]]){
		r=X0;
		s[x]=(x-fa[x]+1)*r*r+A*r+A_2;
	}
	else{
		r=maxr[fa[x]];
		s[x]=(x-fa[x]+1)*r*r+A*r+A_2;
	}
	for(int i=fa[x];i<=x;i++)rr[c[i]]=a[c[i]]+b[c[i]]*r;
	//printf("@%.2lf\n",s[x]);
	if(x==(n-1)){
		double ans=0;
		for(int i=0;i<n;i++)ans+=s[i];
		if(ans<=S)return;
		S=ans;
		
		//printf("---");
		for(int i=0;i<=x;i++){printf("(%.2lf,{%d}%d)",rr[i],fa[i],fr[i]);}
		printf("{%lf}\n",S);
	}
}
inline double d(int xxx,int yyy){
	int x=c[xxx],y=c[yyy];
	return pow((xx[x]-xx[y])*(xx[x]-xx[y])+(yy[x]-yy[y])*(yy[x]-yy[y]),0.5);
}
void calc(int j){
//	for(int i=0;i<n;i++)printf("%d--",fa[i]);
//	printf("in %d\n",c[j]);
	if(j>=n){
		sol(n-1);
		return;
	}
	//for(int j=h;j<t;j++){
		if(fa[j]!=fa[fa[j]])printf("EEE");
		for(int i=fa[j];i<j;i++){
			fr[j]=i;
		    a[j]=d(j,i)-a[i];
			b[j]=-b[i];
			//if(i==j)b[j]=1;
			fa[j+1]=fa[j];
			if(fa[j+1]!=fa[fa[j+1]])printf("EEE");
			double tpmin=minr[fa[j]],tpmax=maxr[fa[j]];
			if(b[j]==-1&&a[j]<maxr[fa[j]])maxr[fa[j]]=a[j];//r>=0
			if(b[j]==1&&a[j]<-minr[fa[j]])minr[fa[j]]=-a[j];//r>=0
			
			bool fg=1;
			for(int k=0;k<n;k++)if(k!=j){
				if(b[j]==1&&maxr[fa[j]]>d(j,k)-a[j])maxr[fa[j]]=d(j,k)-a[j];
				if(b[j]==-1&&minr[fa[j]]<a[j]-d(j,k))minr[fa[j]]=a[j]-d(j,k);
			}
			for(int k=fa[j];k<j;k++){
				if(b[j]==1&&b[k]==1)maxr[fa[j]]=std::min(maxr[fa[j]],(d(j,k)-a[j]-a[k])/2);
				else if(b[j]==-1&&b[k]==-1)minr[fa[j]]=std::max(minr[fa[j]],(a[j]+a[k]-d(j,k))/2);
				else if(d(j,k)<a[j]+a[k]){fg=0;break;}
			}
			for(int k=0;k<fa[j];k++){
				if(b[j]==1)maxr[fa[j]]=std::min(maxr[fa[j]],(d(j,k)-a[j]-rr[k]));
				else if(b[j]==-1)minr[fa[j]]=std::max(minr[fa[j]],(a[j]+rr[k]-d(j,k)));
			}
			
			if(minr[fa[j]]<0||maxr[fa[j]]<minr[fa[j]]||maxr[fa[j]]<0)fg=0;
			if(fg){
					calc(j+1);
//					if(j<n-2){
//					//	printf("ul%d\n",j+1);
//						fa[j+1]=j+1;
//						fa[j+2]=j+1;
//						a[j+1]=0;
//						b[j+1]=1;
//						sol(j);
//						calc(j+2);
//						s[j]=0;
//						fa[j+1]=fa[j];
//					//	printf("`ul%d\n",j+1);
//					}
			}

			minr[fa[j]]=tpmin,maxr[fa[j]]=tpmax;
		
			//rk+rj<d//
		}

				
		//or
		/*
		a[j]=0;
		int tfa=fa[j];
		fa[j]=j;
		fa[j+1]=j;
		sol(j-1);
		calc(j+1);
		s[j-1]=0;
		fa[j]=tfa;*/
	//	printf("out %d\n",c[j]);
//	}
}
int main(){
	scanf("%d",&n);
	c[n]=-1;
	for(int i=0;i<n;i++)scanf("%lf %lf",&xx[i],&yy[i]),c[i]=i;
	do{
		//printf("^^^^^^^^^^%d\n",c[0]);
		for(int i=0;i<n;i++)a[i]=0,maxr[i]=1<<28,minr[i]=0,fa[i]=10,rr[i]=0,s[i]=0;
		b[0]=1;
		fa[1]=fa[0]=0;
		calc(1);
	}while(std::next_permutation(c,c+n));
	printf("%lf",S);
}
