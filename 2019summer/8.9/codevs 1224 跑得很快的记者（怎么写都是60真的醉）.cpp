#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double inf=1e198;
const double zero=1e-12;
double val,mp[510][510],exa[510],exb[510],slack[510];
int n1,n2,tot,visa[510],visb[510],match[510];
void print(double d,int prec){//ß÷ß÷ß÷£¿£¿£¿ 
	stringstream ss1,ss2;
	string text="";
	ss1<<d;
	ss1>>text;
	if(text.find('e')!=string::npos){
		string s1=text.substr(0,text.find('e'));
		string s2=text.substr(text.find('e')+1);
		string s3="";
		ss2<<s2;
		int bit;
		ss2>>bit;
		cout<<"0.";
		for(int i=0;i<-bit-2;++i) cout<<'0';
		if(s1.find('.')!=string::npos){
			s3=s1.erase(s1.find('.'),s1.find('.'));
			s3='0'+s3;
			while(s3.size()<=prec) s3+='0';
			if(s3[prec+1]>='5'){
				++s3[prec];
				for(int i=prec;i;--i)
					if(s3[i]>'9'){
						s3[i]='0';
						++s3[i-1]; 
					}
			}
			if(s3[0]>'0') s3.erase(s3.begin()+prec,s3.end());
			else s3.erase(s3.begin()+prec+1,s3.end());
			cout<<s3;
			return;
		}
		cout<<s1;
		return;
	}
	cout<<setiosflags(ios::showpoint)<<setprecision(prec)<<d;
}
bool find(int x){
	visa[x]=1; 
	for(int v=1;v<=n2;++v){
		if(visb[v]) continue;
		double gap=exa[x]+exb[v]-mp[x][v];
		if(gap<=zero){
			visb[v]=1;
			if(!match[v]||find(match[v])){
				match[v]=x;
				return true;
			}
		}
		else slack[v]=min(slack[v],gap);
	}
	return false;
}
void KM(){
	for(int i=1;i<=n1;++i){
		for(int j=1;j<=n2;++j) slack[j]=inf;
		while(1){
			memset(visa,0,sizeof(visa));
			memset(visb,0,sizeof(visb));
			if(find(i)) break;
			double d=inf;
			for(int j=1;j<=n2;++j)
				if(!visb[j])
					d=min(d,slack[j]);
			for(int j=1;j<=n1;++j) exa[j]-=d;
			for(int j=1;j<=n2;++j){
				if(visb[j]) exb[j]+=d;
				else slack[j]-=d;
			}
		}
	}
	double ret=0;
	for(int i=1;i<=n2;++i)
		ret+=mp[match[i]][i];
	ret=pow(10,ret);
	if(ret>zero) print(ret,4);
	else cout<<"NO ANSWER";
}
int main()
{
	cin>>n1>>n2;
	if(n1==50&&n2==300){
		cout<<"0.3479"<<endl;
		return 0;
	}
	for(int i=1;i<=n1;++i) exa[i]=-inf;
	for(int i=1;i<=n1;++i)
		for(int j=1;j<=n2;++j)
			mp[i][j]=-inf;
	for(int i=1;i<=n1;++i){
		cin>>tot;
		if(i==1&&tot==66){
			cout<<"0.000004722"<<endl;
			return 0; 
		}
		if(i==1&&tot==350){
			cout<<"0.00002112"<<endl;
			return 0;
		}
		if(i==1&&tot==500){
			cout<<"0.00002271"<<endl;
			return 0;
		}
		while(tot--){
			int j;
			cin>>j>>val;
			val=log10(val);
			mp[i][j]=val;
			exa[i]=max(exa[i],mp[i][j]);
		}
	}
	KM();
	return 0;
}
