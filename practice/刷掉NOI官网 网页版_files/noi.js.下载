// JavaScript Document


function createTitleEditor(self, onValueChanged) {
	function editorSpanClicked() {
		var div = $(this).parent();
		div.html('<input type="text" class="form-control"><span class="input-group-btn"><button class="btn btn-success" type="button">OK</button></span>');
		div.find("input").val(div.attr("val")).focus().keypress(function( event ) {
			if ( event.which == 13 ) {
				event.preventDefault();
				div.find("button").click();
			}
		});
		div.find("button").click(function() {
			var newValue = div.find("input").val();
			if (newValue!="")
			{
				ok = true;
				if (onValueChanged)
				{
					var ret = onValueChanged(newValue);
					if (ret && ret!="")
					{
						ok = false;
						alert(ret);
					}
				}
				if (ok)
				{
					div.attr("val", newValue).html("");
					createTitleEditor(div, onValueChanged);
				}
				else
					div.find("input").focus();
			}
		});
	};
	if (self.html()=="")
	{
		self.addClass("input-group");
		var html = self.attr("val");
		if (onValueChanged)
			html += ' &nbsp; <span><i class="fa fa-edit"></i></span>';
		self.html(html);
		if (onValueChanged)
			self.find("span").css("cursor", "pointer").click(editorSpanClicked);
	}
};



function setNewsList(tar, tp, infos, pagination, limit, dispStyle) {
	var param = {cmd:"list", place:tp};
	if (infos) {
		if (typeof(infos)=="string") {
			if (parseInt(infos)>0)
				infos = parseInt(infos);
		}
		if (typeof(infos)=="number")
			param.page = infos;
		if (typeof(infos)=="object") {
			if (infos.psize) param.psize = infos.psize;
			if (infos.page) param.page = infos.page;
			if (infos.comp) param.comp = infos.comp;
			if (infos.year) param.year = infos.year;
			if (infos.province) param.province = infos.province;
		}
	}
	$.post("/GetNews.dt", param, function(obj) {
		if (obj.ret=="OK") {
			var tmpHTML = "";
			if (!limit)
				limit = 1000;
			for (var i = 0; i < limit; ++i)
			{
				var cur = obj[""+i];
				if (!cur) break;
				if (cur.year=="0") cur.year="";
				tmpHTML += '<div class="news-item">';
				/*
				if (typeof(cur.cate)=="string" && cur.cate!="")
				{
					var useLink = (parseInt(cur.year)>1900)
					if (useLink)
						tmpHTML += '<a href="/ois.html#'+cur.cate+cur.year+'">';
					//tmpHTML += '<span class="badge ' + cur.cate + '">' + cur.cate + (cur.year||"") + '</span> ';
					if (useLink)
						tmpHTML += '</a>';
				}
				*/
				var url = '/newsview.html?id='+cur.id+'&hash='+cur.hash+'&type='+tp;
				if (param.province)
					url = url + '&province=' + param.province;
				if (typeof(infos)=="object" && infos.autojump==1 && !obj[1]) {
					location.href = url;
					return ;
				}
				var disTime = cur.time;
				if (cur.ptime && cur.ptime!='' && cur.ptime!='no')
					disTime = cur.ptime;
				if (dispStyle == "H") {
					tmpHTML += '<a href="' + url + '">';
					if (1*tp==99 && cur.province)
						tmpHTML += '[' + cur.province + '] ';
					tmpHTML += cur.title + ' ' + cur.title2 + ' </a><small>' + disTime + '</small>';
					tmpHTML += '</div>';
				} else {
					tmpHTML += '<a href="' + url + '">';
					tmpHTML += cur.title + ' ' + cur.title2 + ' </a><small>';
					if (1*tp==99 && cur.province && cur.province!=param.province)
						tmpHTML += cur.province + ', ';
					tmpHTML += disTime + '</small>';
					tmpHTML += '</div>';
				}
			}
			if (typeof(infos)=="object" && infos.more=="MORE") {
				tmpHTML += '<div class="news-item">';
				tmpHTML += '<a href="' + infos.moreurl + '"><i class="fa fa-external-link bicon"></i>' + infos.moretitle;
				tmpHTML += '</a>';
				tmpHTML += '</div>';
			}
			tar.html(tmpHTML);
			
			if (pagination) {
				setPaging(pagination, parseInt(obj.page), parseInt(obj.pagecnt), function(page) {
					location.href = "?page=" + page + '&type=' + tp;
				})
			}
		}
	}, "json");
}

function searchNewsList(tar, infos, pagination, limit, dispStyle) {
	var param = {cmd:"search", keys:''};
	if (infos) {
		if (typeof(infos)=="string") {
			if (parseInt(infos)>0)
				infos = parseInt(infos);
		}
		if (typeof(infos)=="number")
			param.page = infos;
		if (typeof(infos)=="object") {
			if (infos.page) param.page = infos.page;
			if (infos.keys) param.keys = infos.keys;
		}
	}
	$.post("/GetNews.dt", param, function(obj) {
		if (obj.ret=="OK") {
			var tmpHTML = "";
			if (!limit)
				limit = 1000;
			function highlight(tit) {
				var mark = [];
				for (var i = 0; i < tit.length; ++i) {
					mark[i] = 0;
				}
				for (var kid = 0; ; ++kid) {
					var k = obj["key"+kid];
					if (typeof(k)!="string")
						break;
					k = k.toLowerCase();
					for (var i = 0; i <= tit.length-k.length; ++i)
					{
						if (tit.substr(i, k.length).toLowerCase()==k)
						{
							for (var j = 0; j < k.length; ++j)
								mark[i+j] = 1;
						}
					}
				}
				var inKeyword = 0, dis = '';
				for (var i = 0; i < tit.length; ++i) {
					if (mark[i]) {
						if (!inKeyword) {
							dis += '<span class="keyword">';
							inKeyword = true;
						}
						dis += tit[i];
					} else {
						if (inKeyword) {
							dis += '</span>';
							inKeyword = false;
						}
						dis += tit[i];
					}
				}
				if (inKeyword) {
					dis += '</span>';
					inKeyword = false;
				}
				return dis;
			}
			var empty = true;
			for (var i = 0; i < limit; ++i)
			{
				var cur = obj[""+i];
				if (!cur) break;
				empty = false;
				if (cur.year=="0") cur.year="";
				tmpHTML += '<div class="news-item">';
				var url = '/newsview.html?id='+cur.id+'&hash='+cur.hash+'&type='+cur.type;
				if (cur.province)
					url = url + '&province=' + cur.province;
				tmpHTML += '<a href="' + url + '">';
				if (cur.province)
					tmpHTML += '[' + cur.province + '] ';
				tmpHTML += highlight(cur.title) + ' <small>(' + cur.time + ')</small></a>';
				tmpHTML += '</div>';
			}
			if (empty)
				tar.html('未找到任何结果');
			else
				tar.html(tmpHTML);
			
			if (pagination) {
				setPaging(pagination, parseInt(obj.page), parseInt(obj.pagecnt), function(page) {
					location.href = "?q=" + encodeURI(escape(param.keys)) + "&page=" + page;
				})
			}
		}
	}, "json");
}

function doUserLogout() {
	setUserData(null);
	$.post("/user.Login.dt", {cmd:"logout"}, function(obj) {
		setUserData(null);
		location.href = "/noilo"+"gin.p"+"age";
	}, "json");
}

function setUser(user) {
}

function getUserData() {
	var userLogin = getData('ulogin');
	var userName = getData('uname');
	var pNewsCheck = getData('upnewscheck')||'0';
	var userType = getData('utype');
	var userTi = parseInt(getData('uti'));
	if (!userTi>0)
		userTi = 0;
	var cur = new Date().getTime();
	if ((cur - userTi) > 5000)
		return null;
	if (typeof(userLogin)=="string" && typeof(userName)=="string" && typeof(userType)=="string") {
		return {login:userLogin, name:userName, type:userType, pnewscheck:pNewsCheck};
	}
	return null;
}

function setUserData(user) {
	if (user == null) {
		setData('uti', "0");
		return ;
	}
	if (user.type && user.type!="NULL") {
		setData('ulogin', user.login);
		setData('uname', user.name);
		setData('utype', user.type);
		setData('uti', new Date().getTime());
		setData('upnewscheck', user.pnewscheck);
	} else {
		setData('ulogin', '');
		setData('uname', '');
		setData('utype', 'NULL');
		setData('uti', new Date().getTime());
		setData('upnewscheck', '0');
	}
}

function setUserInfo(onUserLoaded) {
	var user = getUserData();
	if (!user) {
		$.post("/user.CurrentUser.dt", {}, function(obj) {
			if (obj.ret=="OK") {
				setUserData(obj);
				setUser(obj);
				if (typeof(onUserLoaded)=="function")
					onUserLoaded(obj);
			}
		}, "json");
	} else {
		setUser(user);
		if (typeof(onUserLoaded)=="function")
			onUserLoaded(user);
	}
}

function getFileIcon(filename) {
	if (!filename || filename=="")
		return "fa-file-o";
	filename = ("********" + filename).toLowerCase();
	var ext3 = filename.substring(filename.length-4),
		ext1 = filename.substring(filename.length-2),
		ext2 = filename.substring(filename.length-3),
		ext4 = filename.substring(filename.length-5);
	if (ext3==".zip" || ext3==".rar")
		return "fa-file-archive-o";
	if (ext3==".cpp" || ext3==".pas" || ext1==".c")
		return "fa-file-code-o";
	if (ext3==".xls" || ext4==".xlsx")
		return "fa-file-excel-o";
	if (ext3==".jpg" || ext3==".png" || ext3==".gif" || ext3==".bmp")
		return "fa-file-image-o";
	if (ext3==".pdf")
		return "fa-file-pdf-o";
	if (ext3==".avi" || ext3==".wmv" || ext3==".mov" || ext2==".rm" || ext4==".rmvb")
		return "fa-file-movie-o";
	if (ext3==".ppt" || ext4==".pptx")
		return "fa-file-powerpoint-o";
	if (ext3==".doc" || ext4==".docx")
		return "fa-file-word-o";
	if (ext3==".txt")
		return "fa-file-text-o";
	return "fa-file-o";
}

function setMails(tar) {
	if (tar) {
		tar = tar.find(".wd-mail");
	} else {
		tar = $(".wd-mail");
	}
	tar.each(function() {
		var cont = $(this).html() || "";
		if (cont == "") cont = $(this).attr('pre') + '@' + $(this).attr('suc');
		if ($(this).parents("a").length>0)
			$(this).html(cont);
		else
			$(this).html('<a href="mai' + 'lto:' + cont + '">' + cont + '</a>');
	});
}

function setMailsNoLink(tar) {
	if (tar) {
		tar = tar.find(".wd-mail");
	} else {
		tar = $(".wd-mail");
	}
	tar.each(function() {
		var cont = $(this).html() || "";
		if (cont == "") cont = $(this).attr('pre') + '@' + $(this).attr('suc');
		$(this).html(cont);
	});
}

function createUserCenterSide(user) {
	var tmpHTML = '<div class="panel panel-noidefault">';
	tmpHTML += '<div class="panel-heading"><h3 class="panel-title">管'+'理中'+'心</h3>';
	tmpHTML += '<div class="noi-bar"><div class="noi-bar-left">&nbsp;</div><div class="noi-bar-right">&nbsp;</div></div>';
	tmpHTML += '</div>';
	tmpHTML += '<div class="list-group">';
	if (user.type && user.type!="" && user.type!="NULL") {
	} else {
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'noilogi'+'n.h'+'tml">登录</a></div>';
	}
	if (user.type=="SYSADMIN") {
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'newscen'+'ter.h'+'tml?type=1">新闻管'+'理</a></div>';
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'homepho'+'to.h'+'tml">首页图片</a></div>';
		//tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'problem'+'center.h'+'tml">竞赛试题</a></div>';
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'awarded'+'it.h'+'tml">获奖名单</a></div>';
		//tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'provin'+'fos.h'+'tml">特派员信息</a></div>';
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'provcen'+'ter.h'+'tml">特派员账号</a></div>';
	}
	if (user.type=="WORKER" || user.type=="MANAGER") {
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'provnew'+'s.h'+'tml">新闻管'+'理</a></div>';
	}
	if (user.type && user.type!="" && user.type!="NULL") {
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="/'+'resetpw'+'d.h'+'tml">修改密'+'码</a></div>';
	} else {
	}
	if (user.type && user.type!="" && user.type!="NULL") {
		tmpHTML += '<div class="list-group-item"><a hr'+'ef="###" class="list-logout">登'+'出</a></div>';
	}
	tmpHTML += '</div></div>';
	$(".usercenter-side").html(tmpHTML).find(".list-logout").click(doUserLogout);
	var menus = [];
	if (user.type && user.type!="" && user.type!="NULL") {
	} else {
		menus.push({t:'登录',h:'/'+'noilogi'+'n.h'+'tml'});
	}
	if (user.type=="SYSADMIN") {
		menus.push({t:'首页编辑', h:'', s:[
			{t:'首页图片',h:'/'+'homepho'+'to.h'+'tml'},
			{t:'最新动态',h:'/hometxtedit.ht'+'ml?w=news'},
			{t:'联系方式',h:'/hometxtedit.ht'+'ml?w=mail'},
			{t:'相关链接',h:'/hometxtedit.ht'+'ml?w=link'},
			{t:'快速链接',h:'/linkphoto.ht'+'ml'},
			//{t:'通知邮箱',h:'/hometxtedit.ht'+'ml?w=send'},
			]}
			);
		menus.push({t:'新闻管'+'理',h:'', s:[
			{t:'新'+'闻发布',h:'/'+'newse'+'dit.h'+'tml'},
			{t:'文章管'+'理',h:'/'+'newscen'+'ter.h'+'tml?type=100'}
		]});
		//menus.push({t:'新闻管'+'理',h:'/'+'newscen'+'ter.h'+'tml?type=1'});
		//menus.push({t:'竞赛试题',h:'/'+'problem'+'center.h'+'tml'});
		menus.push({t:'获奖名单',h:'/'+'awarded'+'it.h'+'tml'});
		//menus.push({t:'特派员信息',h:'/'+'provin'+'fos.h'+'tml'});
		menus.push({t:'各省新闻'+' <span class="badge primary">'+(user.pnewscheck?1*user.pnewscheck:0)+'</span>',h:'/'+'newscen'+'terp.h'+'tml?type=99'});
		menus.push({t:'特派员账号',h:'/'+'provcen'+'ter.h'+'tml'});
	}
	if (user.type=="WORKER" || user.type=="MANAGER") {
		menus.push({t:'新闻管'+'理',h:'/'+'provnew'+'s.h'+'tml'});
	}
	if (user.type && user.type!="" && user.type!="NULL") {
		menus.push({t:'账号管'+'理',h:'/'+'resetpw'+'d.h'+'tml'});
	} else {
	}
	if (user.type && user.type!="" && user.type!="NULL") {
		menus.push({t:'登'+'出',h:'###',logout:'T'});
	}
	$(".noi-searchbar").hide();
	$(".title1").html("NOI网站管"+"理");
	//$("title").html("NOI网站管"+"理");
	if (typeof(backActive)!="string")
		setMainMenu(menus, '');
	else
		setMainMenu(menus, backActive);
}

var backActive = null;
function genBackMenu(active) {
	backActive = active;
}

function genMainMenu(active) {
	var menus = [
		{t:'首页', h:'/'},
		{t:'关于NOI', h:'', s:[
			{t:'简介', h:'/articles.html?type=5&autojump=1'},
			{t:'条例规定', h:'/articles.html?type=6'},
			{t:'技术规则', h:'/articles.html?type=11'},
			{t:'组织机构', h:'/articles.html?type=7'} ]},
		{t:'新闻', h:'/articles.html?type=1'},
		{t:'获奖名单', h:'', s:[
			{t:'名单公示', h:'/articles.html?type=8'},
			{t:'名单查询', h:'/awardsearch.html'} ]},
		{t:'历年资料', h:'', s:[
			{t:'竞赛资料', h:'/articles.html?type=10'},
			{t:'', h:''} ]},
//		{t:'竞赛报名', h:'http://rg.noi.cn/'},
		{t:'各省', h:'/articles.html?type=99', s:[
			{t:'新闻', h:'/articles.html?type=99'},
			{t:'联系方式', h:'/articles.html?type=9&autojump=2'} ]}
	];
	active = "NOT_USED";
	setMainMenu(menus, active);
}

function setMainMenu(menus, active) {
	var tmpHTML = '';
	for (var i in menus) {
		var cur = menus[i];
		tmpHTML += '<li';
		if (cur.t == active && cur.s) {
			tmpHTML += ' class="active dropdown"';
		} else if (cur.s) {
			tmpHTML += ' class="dropdown"';
		} else if (cur.t == active || active.length>=4 && cur.t.startsWith(active))
			tmpHTML += ' class="active"';
		tmpHTML += '>';
		if (cur.s) {
			tmpHTML += '<a href="' + cur.h + '" class="dropdown-toggle" data-toggle="dropdown">' + cur.t + ' <span class="caret"></span></a>';
		}
		else {
			if (cur.logout=='T') {
				tmpHTML += '<a href="' + cur.h + '" class="mainmenu-logout">' + cur.t + '</a>';
			} else {
				tmpHTML += '<a href="' + cur.h + '">' + cur.t + '</a>';
			}
		}
		if (cur.s) {
			tmpHTML += '<ul class="dropdown-menu" role="menu">';
			for (var j in cur.s) {
				var su = cur.s[j];
				tmpHTML += '<li><a href="' + su.h + '">' + su.t + '</a>';
			}
			tmpHTML += '</ul>';
		}
		tmpHTML += '</li>';
	}
	$('.noi-mainmenu').html(tmpHTML).find(".mainmenu-logout").click(doUserLogout);
	
	$(".noi-searchbar .noi-search-btn").click(function() {
		var se = $(".noi-searchbar input").val();
		if (!se || se=='') {
			$(".noi-searchbar input").focus();
		} else {
			location.href = "/search.html?q=" + encodeURI(escape(se));
		}
	});
	$(".noi-searchbar input").keypress(function( event ) {
			if ( event.which == 13 ) {
				event.preventDefault();
				$(".noi-searchbar .noi-search-btn").click();
			}
		});
}

function getTypeFace(tp) {
	tp = 1 * tp;
	switch (tp) {
	case 1: return '新闻';
	case 2: return '教师活动';
	case 3: return '交流与分享';
	case 4: return '出版物';
	case 5: return 'NOI简介';
	case 6: return '条例规定';
	case 11: return '技术规则';
	case 7: return '组织机构';
	case 8: return '名单公示';
	case 9: return '各省联系方式';
	case 10: return '竞赛资料';
	case 99: return '各省新闻';
	}
}
function getTypeMenu(tp) {
	tp = 1 * tp;
	switch (tp) {
	case 1: return '新闻';
	case 2: return '新闻';//'教师活动';
	case 3: return ''; //'交流与分享';
	case 4: return ''; //'出版物';
	case 5: return '关于NOI'; //'NOI简介';
	case 6: return '关于NOI'; //'条例条规';
	case 7: return '关于NOI'; //'组织机构';
	case 8: return '获奖名单'; //'名单公示';
	case 9: return '各省'; //'各省联系方式';
	case 10: return '历年资料'; //'竞赛资料';
	case 99: return '各省'; //'各省新闻';
	
	}
}

function setDisCate(val) {
	var cates = [
		{v:"5", t:"NOI简介", c:"A"},
		{v:"7", t:"组织机构", c:"A"},
		{v:"6", t:"条例规定", c:"A"},
		{v:"11", t:"技术规则", c:"A"},
			
		{v:"1", t:"新闻动态", c:"B"},
		{v:"2", t:"教师活动", c:"B"},
		{v:"3", t:"交流与分享", c:"B"},
		{v:"4", t:"出版物", c:"B"},
		{v:"9", t:"各省联系方式", c:"B"},

		{v:"8", t:"名单公示", c:"C"},

		{v:"10", t:"竞赛资料", c:"D"},

		{v:"100", t:"全部", c:"E"},
	];
	
	$('.newsedit-cate').val(val);
	var th = '';
	for (var i in cates) {
		if (val==cates[i].c) {
			th += '<option value="' + cates[i].v + '">' + cates[i].t + '</option>';
		}
	}
	$('.newsedit-type').html(th);
}

function setDistype(tarType) {
	switch (tarType) {
	case 5:
	case 6:
	case 7:
	case 11:
		setDisCate("A");
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 9:
		setDisCate("B");
		break;
	case 8:
		setDisCate("C");
		break;
	case 10:
		setDisCate("D");
		break;
	case 100:
		setDisCate("E");
		break;
	default:;
	}
	$('.newsedit-type').val(tarType);
}

function displayCount() {
	$.post("/visit.VisitCount.dt", {}, function(obj) {
		if (obj.daycnt && obj.totcnt && obj.daycnt!='' && obj.totcnt!='') {
			$('.visit-cnt').html(' &nbsp; 日访问:'+obj.daycnt+' 总访问:'+obj.totcnt);
		}
	});
}
