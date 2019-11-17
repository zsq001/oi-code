#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
//typedef int int_;
//#define int long long
#define maxn 1005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
//struct cmp{
//	bool operator()(char A,char B)const{
//		return (A-'a')<(B-'a');
//	}
//};
queue <char> q;
bool cmp(char A,char B){
	return (A-'a')<(B-'a');
}
char ch[27],s[16],tmp;
int c,l;
int tot;
bool judge(int x){
	int tmp=x,cnt=0;
	while(tmp){
		if(tmp&1) cnt++;
		tmp>>=1;
	}
	if(cnt!=l) return 0;
	cnt=0;
	for(int i=1;i<=c;i++){
		if((1<<(c-i))&x){
			s[++tot]=ch[i];
			if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u') cnt++;
		}
	}
	if(cnt<1||(cnt>(l-2))){
		while(tot) s[tot]=0,tot--;
		return 0;
	}
	return 1;
}
int cnt;
int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	read(l);
	read(c);
	for(int i=1;i<=c;i++) while(ch[i]<'a'||ch[i]>'z') ch[i]=getchar();
	sort(ch+1,ch+c+1,cmp);
	for(int i=1;i<=c;i++) if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u') q.push(ch[i]);
	for(int i=(1<<c)-1;i;i--){
		if(judge(i)){
			printf("%s\n",s+1);
			while(tot) s[tot]=0,tot--;
			cnt++;
		}
		if(cnt==25000) break;
	}
//	for(int i=1;i<=c;i++) printf("%c ",ch[i]);
	return 0;
}
