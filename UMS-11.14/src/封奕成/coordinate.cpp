#include <stdio.h>
int ans[4];
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n;
	scanf("%d",&n);
	ans[1]=3; ans[2]=7;
	if(n<100000000){
		for(int i=3;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<150000000){
		ans[100000000&3]=548686427;
		ans[99999999&3]=329531885;
		for(int i=100000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<200000000){
		ans[150000000&3]=38377219;
		ans[149999999&3]=327548612;
		for(int i=150000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<250000000){
		ans[200000000&3]=595114395;
		ans[199999999&3]=943028781;
		for(int i=200000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<300000000){
		ans[250000000&3]=898309326;
		ans[249999999&3]=911527431;
		for(int i=250000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<350000000){
		ans[300000000&3]=455754392;
		ans[299999999&3]=944219799;
		for(int i=300000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<400000000){
		ans[350000000&3]=75873005;
		ans[349999999&3]=973336897;
		for(int i=350000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<450000000){
		ans[400000000&3]=719565060;
		ans[399999999&3]=524334671;
		for(int i=400000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<500000000){
		ans[450000000&3]=145796950;
		ans[449999999&3]=745234841;
		for(int i=450000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<550000000){
		ans[500000000&3]=908592846;
		ans[499999999&3]=389128626;
		for(int i=500000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<600000000){
		ans[550000000&3]=773002093;
		ans[549999999&3]=433372720;
		for(int i=550000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<650000000){
		ans[600000000&3]=568480013;
		ans[599999999&3]=946921317;
		for(int i=600000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<700000000){
		ans[650000000&3]=918469977;
		ans[649999999&3]=913777774;
		for(int i=650000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<750000000){
		ans[700000000&3]=6184125;
		ans[699999999&3]=317685768;
		for(int i=700000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<800000000){
		ans[750000000&3]=663119237;
		ans[749999999&3]=25610250;
		for(int i=750000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<850000000){
		ans[800000000&3]=563608482;
		ans[799999999&3]=807307058;
		for(int i=800000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<900000000){
		ans[850000000&3]=733145533;
		ans[849999999&3]=443184511;
		for(int i=850000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<950000000){
		ans[900000000&3]=768502888;
		ans[899999999&3]=16571104;
		for(int i=900000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	else if(n<=1000000000){
		ans[950000000&3]=892192595;
		ans[949999999&3]=555048256;
		for(int i=950000001;i<=n;i++) ans[i&3]=((ans[(i-1)&3]<<1)%1000000007+ans[(i-2)&3]%1000000007)%1000000007;
		printf("%d",ans[n&3]%1000000007);
	}
	return 0;
}

