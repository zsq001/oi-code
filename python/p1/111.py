# -*- coding:utf-8 -*-
import binascii
from data import p1,q1,hint,flag

e1 = 3
n1 = 22792498229070562307071790237054969069063199012703636977056417569343054099075184240064763163941594271855958973638212045066775476328786960852275829140026402989684888532712594304893226128853491130654445527334464945488214809291604550382437479535358332815302757776792265657229531708660139318117137497935619658331628962202543372286871033167193667854674269850788252021336414414802920160199812716717722506898587880785772171835106686255241572437950611607238928582567216636465715754493344275044971735761724060793073299003578529241738479820900774998011114048056314601285886777768825323827823821663875520009930335670419926394433
c1 = 699445420425001459004808533754674197028566806243316581462772431323254845598569234613681989996046618662748940175137796065566742779311164981670674621049871832814412040534983311279863320664576608112978836800617389107466042557612932519

assert(c1 == pow(p1, e1, n1))
e2 = 65537
n2 = 103461035900816914121390101299049044413950405173712170434161686539878160984549
hint = int(binascii.hexlify(hint),16)
c2 = 57504040201015853613976102769804209300823587699891602889542316183294605443643

assert(c2 == pow(hint, e2, n2))
e3 = 14065324093316017945695720258347429532521523200228598193322667338820770590989154977786981894794588594064536009186732255775035804405327706425255296803855527639374329558376563095664859692148197185703687276097309462020144376262777557533944519562049109221719648126706993033163993490190085491702629251352329396471456129542825658446009162968346786594848548139595669836329358788165100849817671092568134531593182392252696719165573226130084180843486935720502707239300540428534291779101061922644007823991998086019198292035392258539304441052201138357754863223836486846439513422901513872417295274198920142360883876210212927825007
n3 = 18462906143035540993814517057095163128283817787230664517838986634801013392767711846485937113330072380038567780269061919808605648774959966319179757205173372523095161810322702620470126948608656351385935375720727519176775110406692586449768317335765421930399299578230419560189633716571287406027463911286833332787737419540756653612611709926058384814812935770145166745335145087323852211057246522872067333040272572190577262813212787729743380140592301701193918348912668992966189995193003441075512789075254845693251194059243188025613215624222354768281910170062917473229700929505219308776883069798326608764552258161920559190481
c3 = 5549471621054606387376189648262004799500268173142044655739847262489726086415789303832887196173979938938810748911202682478461116255949148319334823431098734732762517928502010817943033753862943263846604275260853125076392847429238283208501417737383284037247448803849860561678579889086865839396570642670691404480257521910815104202092861260631338166797818628339690756671365753551819100933215063782156410018726606510181713124990335434298733724418714392234966366369968736810822111051583406815845103529492030182160782212176373515903463332063237694480040104956642104025058964393516692140981219422802521970047552684093064548664

assert(c3 == pow(q1, e3, n3))
flag=int(binascii.hexlify(flag),16)
e4 = 65537
p = p1
q = q1

final_c = 802407683549035987845420883290161894834125419353306617325792242273445520171950387404842635802247484861606990315267165070298352301939784659973036613063129550577746135172659687103341466225376204749580745927897911623380501563025418202

assert(final_c == pow(flag, e4, p*q))