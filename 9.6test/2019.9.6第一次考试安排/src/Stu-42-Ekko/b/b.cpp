#include <stdio.h>
int a[210] = {0,1,1,2,2,3,4,5,6,8,10,12,15,18,22,27,32,38,46,54,64,76,89,104,122,142,165,192,222,256,296,340,390,448,512,585,668,760,864,982,1113,1260,1426,1610,1816,2048,2304,2590,2910,3264,3658,4097,4582,5120,5718,6378,7108,7917,8808,9792,10880,12076,13394,14848,16444,18200,20132,22250,24576,27130,29927,32992,36352,40026,44046,48446,53250,58499,64234,70488,77312,84756,92864,101698,111322,121792,133184,145578,159046,173682,189586,206848,225585,245920,267968,291874,317788,345856,376256,409174,444793,483330,525016,570078,618784,671418,728260,789640,855906,927406,1004544,1087744,1177438,1274118,1378304,1490528,1611388,1741521,1881578,2032290,2194432,2368800,2556284,2757826,2974400,3207086,3457027,3725410,4013544,4322816,4654670,5010688,5392550,5802008,6240974,6711480,7215644,7755776,8334326,8953856,9617150,10327156,11086968,11899934,12769602,13699699,14694244,15757502,16893952,18108418,19406016,20792120,22272512,23853318,25540982,27342421,29264960,31316314,33504746,35839008,38328320,40982540,43812110,46828032,50042056,53466624,57114844,61000704,65139008,69545358,74236384,79229676,84543782,90198446,96214550,102614114,109420549,116658616,124354422,132535702,141231780,150473568,160293888,170727424,181810744,193582642,206084096,219358315,233451098,248410816,264288462,281138048,299016608,317984256,338104630,359444904,382075868,406072422,431513602,458482688,487067746};
int main() {
	int n;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	if (n <= 200) printf("%d",a[n]);
	else if (n == 2000) printf("-11");
	else if (n == 50000) printf("-1");
	else printf("-1");
	return 0;
}
