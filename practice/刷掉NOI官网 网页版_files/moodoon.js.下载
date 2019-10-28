// JavaScript Document

if (typeof String.prototype.startsWith != 'function') {
  String.prototype.startsWith = function (prefix){
    return this.slice(0, prefix.length) === prefix;
  };
}
if (typeof String.prototype.endsWith != 'function') {
  String.prototype.endsWith = function(suffix) {
    return this.indexOf(suffix, this.length - suffix.length) !== -1;
  };
}

function div(a, b) { return a/b; }

function renrenlogin() {
	window.location.href="https://graph.renren.com/oauth/authorize?client_id=177766&response_type=code&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FRenrenLogin.do&display=page";
}
function weibologin() {
	window.location.href="https://api.weibo.com/2/oauth2/authorize?client_id=1707773381&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FWeiboLogin.do&response_type=code";
}
function qqlogin() {
	window.location.href="https://graph.qq.com/oauth2.0/authorize?response_type=code&client_id=100243191&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FQQLogin.do";
}

function toCompileName(sn)
{
	if (sn == "VC") return "Microsoft Visual C";
	if (sn == "VCPP") return "Microsoft Visual C++";
	if (sn == "BC") return "Borland C";
	if (sn == "BCPP") return "Borland C++";
	if (sn == "JAVA") return "Java";
	if (sn == "DC") return "Dev-CPP (C语言)";
	if (sn == "DCPP") return "Dev-CPP (C++语言)";
	return "";
}
function tryLogin(_vlogin, _vidnumber)
{
	$.post("/user.Login.dt", {username:_vlogin, idnumber:_vidnumber}, function(obj) {
		if (obj.ret=='OK')
			location.reload();
		else
			alert(obj["info"]);
	}, "json");
	return false;
}
function isRequireLang(tp)
{
	var tmp = (""+tp).toLowerCase();
	if (!tp) tmp = "";
	return !(tmp=="" || tmp=="-" || tmp=="result");
}

function two(x){return (x>=10?"":"0")+x;}
function leftTimeStr(svnow)
{
	svnow = Math.floor(svnow);
	var old = svnow;
	pn = "";
	if (svnow>=3600)
	{
		var hours = Math.floor(svnow / 3600);
		pn += hours + "小时";
		svnow = svnow - hours * 3600;
	}
	if (old>=60)
	{
		var minutes = Math.floor(svnow / 60);
		if (pn!="" && minutes<10)
			pn += "0";
		pn += minutes + "分";
		svnow = svnow - minutes * 60;
	}
	var seconds = Math.floor(svnow);
	if (pn!="" && seconds<10)
		pn += "0";
	pn += seconds + "秒";
	return pn;
}
function setScheduleLeft(cleft)
{
	if (cleft<0)
	{
		currentInfo.schedulewait = null;
		return ;
	}
	var timepassed = Math.floor((new Date().getTime()-currentInfo.timec)/1000);
	var timewait = timepassed + cleft;
	if (!currentInfo.schedulewait || Math.abs(timewait-currentInfo.schedulewait)>3)
		currentInfo.schedulewait = timewait;
}
function onticktime()
{
	var svst = parseInt(currentInfo["time"]);
	var now=new Date();var ns=now.getHours()*3600+now.getMinutes()*60+now.getSeconds();
	var timepassed = Math.floor((new Date().getTime()-currentInfo.timec)/1000);
	var svnow=svst+timepassed;
	var curtime = two(Math.floor(svnow/3600)%24)+":"+two(Math.floor(svnow/60)%60)+":"+two(svnow%60);
	$('#info4').text(curtime);
}

function gotoUrl(url)
{
	location.href = url;
}
function checkUState()
{
	var stat = currentInfo["ustatus"];
	var curl = location.pathname;
}
function downloadByHandle(handle)
{
	$("#dframe").attr("src","/web.RequireTempFile.do?handle=" + handle);
}
function _getUrlParam(name)
{
	var urlR=location.href;
	var urlL = urlR.toLowerCase();
	var ret = "";
	var p = urlL.lastIndexOf(name.toLowerCase() + "=");
	if (p>=0)
	{
		var _va = urlR.substring(p+name.length+1);
		var _p1 = _va.indexOf("?");
		if (_p1>=0) _va = _va.substring(0, _p1);
		_p1 = _va.indexOf("&");
		if (_p1>=0) _va = _va.substring(0, _p1);
		_p1 = _va.indexOf("#");
		if (_p1>=0) _va = _va.substring(0, _p1);
		ret = decodeURI(_va);
	}
	return ret;
}
function _getUrlIntParam(name)
{
	return parseInt(_getUrlParam(name));
}
getUrlIntParam = _getUrlIntParam;
getUrlParam = _getUrlParam;







// ================
// Prototype
// ================
(function ($) {
		$.getUrlParam = function (name) {
				var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)");
				var r = window.location.search.substr(1).match(reg);
				if (r != null) return decodeURI(r[2]);
				var r = window.location.hash.substr(1).match(reg);
				if (r != null) return decodeURI(r[2]); return null;
		}
})(jQuery);

// ================
// Global
// ================
function getLoginLink()
{
	var redir = $.getUrlParam("redir");
	if (typeof(redir)!="string")
		redir = location.pathname + location.search + location.hash;
	return "/?redir=" + encodeURI(escape(redir));
}
function onPageReady()
{
	var cuser = getCurrentInfo();
	var userid = 0;
	if (typeof(cuser.userid)=="string")
		userid = parseInt(cuser.userid);
	if (userid>0)
		$(".tsinsen-userdis").attr("href", "###").html('<i class="fa fa-user"></i>&nbsp; ' + cuser.login + "(" + cuser.name + ")");
	else
		$(".tsinsen-userdis").addClass("tsinsen-loginlink btn btn-success").html('<i class="fa fa-sign-in bicon"></i>用户登录');
	$(".tsinsen-loginlink").attr("href", getLoginLink());
	$(".tsinsen-logoutlink").attr("href", "###").click(function() {
		$.post("/user.Logout.dt", {}, function() { location.reload(); }, "json");
	});
	$(".tsnisen-usercenter").attr("href", "/usercenter.page");
	
	if (cuser.admindisplay == "block")
	{
		$(".showifadmin").show();
	}
}
function gotoLoginPage()
{
	location.replace(getLoginLink());
}

function _getLocalStorage()
{
	if (typeof localStorage == "object")
		return localStorage;
	if (typeof globalStorage == "object")
		return globalStorage[location.host];
	return _CookieStore;
}
function _getSessionStorage()
{
	if (typeof sessionStorage == "object")
		return sessionStorage;
	return _CookieSessionStore;
}
function _storageSetData(key, value)
{
	_getLocalStorage().setItem(key, value);
};
setData = _storageSetData;
function _storageGetData(key)
{
	return _getLocalStorage().getItem(key);
};
getData = _storageGetData;
function _storageSetSessionData(key, value)
{
	_getSessionStorage().setItem(""+key, ""+value);
};
setSessionData = _storageSetSessionData;
function _storageGetSessionData(key)
{
	return _getSessionStorage().getItem(key);
};
getSessionData = _storageGetSessionData;


function setPaging(tar, curPage, pageCnt, onPageChange)
{
	var pageStr = "";
	function addPage(page, display)
	{
		if (typeof(display)!='string')
			display = page;
		if (page==curPage)
			pageStr += '<li><a class="disabled current" page="' + page + '"><b>' + display + '</b></a></li>';
		else
			pageStr += '<li><a href="###" page="' + page + '">' + display + '</a></li>';
	}
	if (curPage>1)
	{
		addPage(1, "首页");
		addPage(curPage-1, "上一页");
	}
	for (var i = curPage-3; i <=curPage+3; ++i)
	{
		if (i>=1 && i<pageCnt)
			addPage(i);
	}
	if (curPage+3+2==pageCnt)
		addPage(curPage+3+1);
	else if (curPage+3+2<pageCnt)
		pageStr += "<li><a>...</a></li>";
	if (pageCnt>1)
		addPage(pageCnt);
	if (curPage < pageCnt)
		addPage(curPage+1, "下一页");
	if (curPage < pageCnt)
		addPage(pageCnt, "尾页");
	tar.html(pageStr).find("a").click(function() {
		onPageChange(parseInt($(this).attr("page")));
		return false;
	});
}


function randStr8() {
	var pattern = "abcdefghijklmnopqrstuvwxyz";
	var ret = "";
	for (var i = 0; i < 8; ++i)
		ret += pattern.charAt(Math.floor(Math.random()*(pattern.length-0.01)));
	return ret;
}

function countDown(tar, time, over) {
	if (typeof(time)!="number")
		time = parseInt(time);
	var tarInter = setInterval(function() {
		var now=new Date();var ns=now.getHours()*3600+now.getMinutes()*60+now.getSeconds();
		var timepassed = Math.floor((new Date().getTime()-currentInfo.timec)/1000);
		var tleft=time-timepassed;
		if (tleft<=0)
		{
			clearInterval(tarInter);
			if (typeof(over)=="function")
				over();
		}
		var htmlTime = '';
		htmlTime = two(tleft%60) + '秒';
		tleft = Math.floor(tleft/60);
		if (tleft > 0)
		{
			htmlTime = two(tleft%60) + '分' + htmlTime;
			tleft = Math.floor(tleft/60);
			if (tleft > 0)
			{
				htmlTime = (tleft%24) + '小时' + htmlTime;
				tleft = Math.floor(tleft/24);
				if (tleft > 0)
					htmlTime = tleft + '天' + htmlTime;
			}
		}
		tar.html(htmlTime);
	}, 1000);
}

function restoreRemoveButtonHelp(btns) {
	btns.parent().addClass("nohelp");
}

function hideRemoveButton(btns) {
	btns.parent().hide();
}

function showRemoveButton(btns) {
	btns.parent().show();
}

function initRemoveButton(btns, onRemove, numTicks)
{
	if (btns.size()>1)
	{
		btns.each(function() {
			initRemoveButton($(this), onRemove, numTicks);
		});
		return ;
	}
	var timeInterval = null;
	var timePast = 0;
	
	if (typeof(numTicks)!="number")
		numTicks = 25;
	
	btns.wrap("<div class='removeable-btn nohelp'></div>");
	
	var tarPar = btns.parent();
	
	tarPar.css("display", "inline-block").css("position", "relative").append('<div class="progress" style="display:none; position:absolute; width:100%; "><div class="progress-bar progress-bar-danger" role="progressbar" style="width: 0%"><span>0%</span></div></div>');

	btns.append("<span class='help'><br /><small>按住" + 
		(numTicks / 10) + 
		"秒</small></span>");

	function showPercent()
	{
		var percent = timePast * 100 / numTicks;
		if (percent >= 100)
			percent = 100;
		tarPar.find(".progress-bar").css("width", percent+"%").find('span').html(percent.toFixed(1)+"%");
	}
	function removeTicks()
	{
		++timePast;
		showPercent();
	}
	function startRemove()
	{
		timePast = 0;
		showPercent();
		if (timeInterval)
		{
			clearInterval(timeInterval);
			timeInterval = null;
		}
		tarPar.find(".progress").show();
		timeInterval = setInterval(removeTicks, 100);
	}
	function clearRemove()
	{
		timePast = 0;
		tarPar.find(".progress").hide();
		if (timeInterval)
		{
			clearInterval(timeInterval);
			timeInterval = null;
			tarPar.removeClass("nohelp");
		}
		showPercent();
	}
	function endRemove()
	{
		if (timePast >= numTicks)
		{
			if (typeof(onRemove)=="function")
				onRemove.apply(btns);
		}
		clearRemove();
	}
	function interruptRemove()
	{
		clearRemove();
	}
	btns.mousedown(startRemove).mouseup(endRemove).mouseleave(interruptRemove).mouseenter(interruptRemove);
}


function prepareLostFunctions() {
	if (!String.prototype.trim) {
	  String.prototype.trim = function () {
	    return this.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
	  };
	}
}
