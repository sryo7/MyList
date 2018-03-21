



<!DOCTYPE html>
<html lang="ja-JP" >

<head>

	
	<script>
window.ts_endpoint_url = "https:\/\/slack.com\/beacon\/timing";

(function(e) {
	var n=Date.now?Date.now():+new Date,r=e.performance||{},t=[],a={},i=function(e,n){for(var r=0,a=t.length,i=[];a>r;r++)t[r][e]==n&&i.push(t[r]);return i},o=function(e,n){for(var r,a=t.length;a--;)r=t[a],r.entryType!=e||void 0!==n&&r.name!=n||t.splice(a,1)};r.now||(r.now=r.webkitNow||r.mozNow||r.msNow||function(){return(Date.now?Date.now():+new Date)-n}),r.mark||(r.mark=r.webkitMark||function(e){var n={name:e,entryType:"mark",startTime:r.now(),duration:0};t.push(n),a[e]=n}),r.measure||(r.measure=r.webkitMeasure||function(e,n,r){n=a[n].startTime,r=a[r].startTime,t.push({name:e,entryType:"measure",startTime:n,duration:r-n})}),r.getEntriesByType||(r.getEntriesByType=r.webkitGetEntriesByType||function(e){return i("entryType",e)}),r.getEntriesByName||(r.getEntriesByName=r.webkitGetEntriesByName||function(e){return i("name",e)}),r.clearMarks||(r.clearMarks=r.webkitClearMarks||function(e){o("mark",e)}),r.clearMeasures||(r.clearMeasures=r.webkitClearMeasures||function(e){o("measure",e)}),e.performance=r,"function"==typeof define&&(define.amd||define.ajs)&&define("performance",[],function(){return r}) // eslint-disable-line
})(window);

</script>
<script>


;(function() {



window.TSMark = function(mark_label) {
	if (!window.performance || !window.performance.mark) return;
	performance.mark(mark_label);
};
window.TSMark('start_load');


window.TSMeasureAndBeacon = function(measure_label, start_mark_label) {
	if (start_mark_label === 'start_nav' && window.performance && window.performance.timing) {
		window.TSBeacon(measure_label, (new Date()).getTime() - performance.timing.navigationStart);
		return;
	}
	if (!window.performance || !window.performance.mark || !window.performance.measure) return;
	performance.mark(start_mark_label + '_end');
	try {
		performance.measure(measure_label, start_mark_label, start_mark_label + '_end');
		window.TSBeacon(measure_label, performance.getEntriesByName(measure_label)[0].duration);
	} catch (e) {
		
	}
};


if ('sendBeacon' in navigator) {
	window.TSBeacon = function(label, value) {
		var endpoint_url = window.ts_endpoint_url || 'https://slack.com/beacon/timing';
		navigator.sendBeacon(endpoint_url + '?data=' + encodeURIComponent(label + ':' + value), '');
	};
} else {
	window.TSBeacon = function(label, value) {
		var endpoint_url = window.ts_endpoint_url || 'https://slack.com/beacon/timing';
		(new Image()).src = endpoint_url + '?data=' + encodeURIComponent(label + ':' + value);
	};
}
})();
</script>
 

<script>
window.TSMark('step_load');
</script>	<noscript><meta http-equiv="refresh" content="0; URL=/files/U4RTD3TLP/F9RUNPRHU/README_md.md?nojsmode=1" /></noscript>
<script type="text/javascript">
if(self!==top)window.document.write("\u003Cstyle>body * {display:none !important;}\u003C\/style>\u003Ca href=\"#\" onclick="+
"\"top.location.href=window.location.href\" style=\"display:block !important;padding:10px\">Go to Slack.com\u003C\/a>");

(function() {
	var timer;
	if (self !== top) {
		timer = window.setInterval(function() {
			if (window.$) {
				try {
					$('#page').remove();
					$('#client-ui').remove();
					window.TS = null;
					window.clearInterval(timer);
				} catch(e) {}
			}
		}, 200);
	}
}());

</script>

<script>

(function() {


	window.callSlackAPIUnauthed = function(method, args, callback) {
		var timestamp = Date.now() / 1000;  
		var version = (window.TS && TS.boot_data && TS.boot_data.version_uid) ? TS.boot_data.version_uid.substring(0, 8) : 'noversion';
		var url = '/api/' + method + '?_x_id=' + version + '-' + timestamp;

		var req = new XMLHttpRequest();

		req.onreadystatechange = function() {
			if (req.readyState == 4) {
				req.onreadystatechange = null;
				var obj;

				if (req.status == 200 || req.status == 429) {
					try {
						obj = JSON.parse(req.responseText);
					} catch (err) {
						TS.warn(8675309, 'unable to do anything with api rsp');
					}
				}

				obj = obj || {
					ok: false,
				};

				callback(obj.ok, obj, args);
			}
		};

		var async = true;
		req.open('POST', url, async);

		var form_data = new FormData();
		var has_data = false;
		Object.keys(args).forEach(function(k) {
			if (k[0] === '_') return;
			form_data.append(k, args[k]);
			has_data = true;
		});

		if (has_data) {
			req.send(form_data);
		} else {
			req.send();
		}
	};
})();
</script>

	<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/webpack.manifest.ja-JP.3de09f5235af2caf7469.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

			
	
		<script>
			if (window.location.host == 'slack.com' && window.location.search.indexOf('story') < 0) {
				document.cookie = '__cvo_skip_doc=' + escape(document.URL) + '|' + escape(document.referrer) + ';path=/';
			}
		</script>
	

		<script type="text/javascript">
		
		try {
			if(window.location.hash && !window.location.hash.match(/^(#?[a-zA-Z0-9_]*)$/)) {
				window.location.hash = '';
			}
		} catch(e) {}
		
	</script>

	<script type="text/javascript">
				
			window.optimizely = [];
			window.dataLayer = [];
			window.ga = false;
		
	
				(function(e,c,b,f,d,g,a){e.SlackBeaconObject=d;
		e[d]=e[d]||function(){(e[d].q=e[d].q||[]).push([1*new Date(),arguments])};
		e[d].l=1*new Date();g=c.createElement(b);a=c.getElementsByTagName(b)[0];
		g.async=1;g.src=f;a.parentNode.insertBefore(g,a)
		})(window,document,"script","https://a.slack-edge.com/bv1-1/slack_beacon.ja-JP.c71822faa137a0269726.min.js","sb");
		sb('set', 'token', '3307f436963e02d4f9eb85ce5159744c');

					sb('set', 'user_id', "U96LUJC06");
							sb('set', 'user_' + "batch", "?");
							sb('set', 'user_' + "created", "2018-02-08");
						sb('set', 'name_tag', "morishimalab" + '/' + "s.ryonchil3215");
				sb('track', 'pageview');

		
		function track(a) {
			if(window.ga) ga('send','event','web', a);
			if(window.sb) sb('track', a);
		}
		

	</script>

	

	<meta name="referrer" content="no-referrer">
		<meta name="superfish" content="nofish">

	<script type="text/javascript">



var TS_last_log_date = null;
var TSMakeLogDate = function() {
	var date = new Date();

	var y = date.getFullYear();
	var mo = date.getMonth()+1;
	var d = date.getDate();

	var time = {
	  h: date.getHours(),
	  mi: date.getMinutes(),
	  s: date.getSeconds(),
	  ms: date.getMilliseconds()
	};

	Object.keys(time).map(function(moment, index) {
		if (moment == 'ms') {
			if (time[moment] < 10) {
				time[moment] = time[moment]+'00';
			} else if (time[moment] < 100) {
				time[moment] = time[moment]+'0';
			}
		} else if (time[moment] < 10) {
			time[moment] = '0' + time[moment];
		}
	});

	var str = y + '/' + mo + '/' + d + ' ' + time.h + ':' + time.mi + ':' + time.s + '.' + time.ms;
	if (TS_last_log_date) {
		var diff = date-TS_last_log_date;
		//str+= ' ('+diff+'ms)';
	}
	TS_last_log_date = date;
	return str+' ';
}

var parseDeepLinkRequest = function(code) {
	var m = code.match(/"id":"([CDG][A-Z0-9]{8})"/);
	var id = m ? m[1] : null;

	m = code.match(/"team":"(T[A-Z0-9]{8})"/);
	var team = m ? m[1] : null;

	m = code.match(/"message":"([0-9]+\.[0-9]+)"/);
	var message = m ? m[1] : null;

	return { id: id, team: team, message: message };
}

if ('rendererEvalAsync' in window) {
	var origRendererEvalAsync = window.rendererEvalAsync;
	window.rendererEvalAsync = function(blob) {
		try {
			var data = JSON.parse(decodeURIComponent(atob(blob)));
			if (data.code.match(/handleDeepLink/)) {
				var request = parseDeepLinkRequest(data.code);
				if (!request.id || !request.team || !request.message) return;

				request.cmd = 'channel';
				TSSSB.handleDeepLinkWithArgs(JSON.stringify(request));
				return;
			} else {
				origRendererEvalAsync(blob);
			}
		} catch (e) {
		}
	}
}
</script>



<script type="text/javascript">

	var TSSSB = {
		call: function() {
			return false;
		}
	};

</script>
<script>TSSSB.env = (function() {


	var v = {
		win_ssb_version: null,
		win_ssb_version_minor: null,
		mac_ssb_version: null,
		mac_ssb_version_minor: null,
		mac_ssb_build: null,
		lin_ssb_version: null,
		lin_ssb_version_minor: null,
		desktop_app_version: null,
	};

	var is_win = (navigator.appVersion.indexOf('Windows') !== -1);
	var is_lin = (navigator.appVersion.indexOf('Linux') !== -1);
	var is_mac = !!(navigator.userAgent.match(/(OS X)/g));

	if (navigator.userAgent.match(/(Slack_SSB)/g) || navigator.userAgent.match(/(Slack_WINSSB)/g)) {
		
		var parts = navigator.userAgent.split('/');
		var version_str = parts[parts.length - 1];
		var version_float = parseFloat(version_str);
		var version_parts = version_str.split('.');
		var version_minor = (version_parts.length == 3) ? parseInt(version_parts[2], 10) : 0;

		if (navigator.userAgent.match(/(AtomShell)/g)) {
			
			if (is_lin) {
				v.lin_ssb_version = version_float;
				v.lin_ssb_version_minor = version_minor;
			} else if (is_win) {
				v.win_ssb_version = version_float;
				v.win_ssb_version_minor = version_minor;
			} else if (is_mac) {
				v.mac_ssb_version = version_float;
				v.mac_ssb_version_minor = version_minor;
			}

			if (version_parts.length >= 3) {
				v.desktop_app_version = {
					major: parseInt(version_parts[0], 10),
					minor: parseInt(version_parts[1], 10),
					patch: parseInt(version_parts[2], 10),
				};
			}
		}
	}

	return v;
})();
</script>


	<script type="text/javascript">
		
		window.addEventListener('load', function() {
			var was_TS = window.TS;
			delete window.TS;
			if (was_TS) window.TS = was_TS;
		});
	</script>
	        <title>README.md | Morishima Lab Slack</title>
    <meta name="author" content="Slack">
        

	
		
	
	
		
					
	
						
	
	

	
	
	
	
	
	
	
		<!-- output_css "sk_adapter" -->
    <link href="https://a.slack-edge.com/7057c/style/rollup-slack_kit_legacy_adapters.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

			<!-- output_css "core" -->
    <link href="https://a.slack-edge.com/fe6e1/style/rollup-plastic.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

		<!-- output_css "before_file_pages" -->
    <link href="https://a.slack-edge.com/74a30/style/libs/codemirror.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">
    <link href="https://a.slack-edge.com/f2910/style/codemirror_overrides.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

	<!-- output_css "file_pages" -->
    <link href="https://a.slack-edge.com/1387d/style/rollup-file_pages.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

	
			<!-- output_css "slack_kit_helpers" -->
    <link href="https://a.slack-edge.com/58329/style/rollup-slack_kit_helpers.css" rel="stylesheet" type="text/css" id="slack_kit_helpers_stylesheet"  crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

	<!-- output_css "regular" -->
    <link href="https://a.slack-edge.com/95d09/style/print.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">
    <link href="https://a.slack-edge.com/5e83b/style/libs/lato-2-compressed.css" rel="stylesheet" type="text/css" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)">

	

	
	
		<meta name="robots" content="noindex, nofollow" />
	

	
<link id="favicon" rel="shortcut icon" href="https://a.slack-edge.com/436da/marketing/img/meta/favicon-32.png" sizes="16x16 32x32 48x48" type="image/png" />

<link rel="icon" href="https://a.slack-edge.com/436da/marketing/img/meta/app-256.png" sizes="256x256" type="image/png" />

<link rel="apple-touch-icon-precomposed" sizes="152x152" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-152.png" />
<link rel="apple-touch-icon-precomposed" sizes="144x144" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-144.png" />
<link rel="apple-touch-icon-precomposed" sizes="120x120" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-120.png" />
<link rel="apple-touch-icon-precomposed" sizes="114x114" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-114.png" />
<link rel="apple-touch-icon-precomposed" sizes="72x72" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-72.png" />
<link rel="apple-touch-icon-precomposed" href="https://a.slack-edge.com/436da/marketing/img/meta/ios-57.png" />

<meta name="msapplication-TileColor" content="#FFFFFF" />
<meta name="msapplication-TileImage" content="https://a.slack-edge.com/436da/marketing/img/meta/app-144.png" />
	
</head>

<body class="				">

		  			<script>
		
			var w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
			if (w > 1440) document.querySelector('body').classList.add('widescreen');
		
		</script>
	
  	
	
	

			

<nav id="site_nav" class="no_transition">

	<div id="site_nav_contents">

		<div id="user_menu">
			<div id="user_menu_contents">
				<div id="user_menu_avatar">
										<span class="member_image thumb_48" style="background-image: url('https://secure.gravatar.com/avatar/665b539af6e6d984271e004a5800c439.jpg?s=192&d=https%3A%2F%2Fa.slack-edge.com%2F7fa9%2Fimg%2Favatars%2Fava_0009-192.png')" data-thumb-size="48" data-member-id="U96LUJC06"></span>
					<span class="member_image thumb_36" style="background-image: url('https://secure.gravatar.com/avatar/665b539af6e6d984271e004a5800c439.jpg?s=72&d=https%3A%2F%2Fa.slack-edge.com%2F66f9%2Fimg%2Favatars%2Fava_0009-72.png')" data-thumb-size="36" data-member-id="U96LUJC06"></span>
				</div>
				<h3>サインイン中のユーザー名</h3>
				<span id="user_menu_name">Ryo</span>
			</div>
		</div>

		<div class="nav_contents">

			<ul class="primary_nav">
									<li><a href="/messages" data-qa="app"><i class="ts_icon ts_icon_angle_arrow_up_left"></i>Slack に戻る</a></li>
								<li><a href="/home" data-qa="home"><i class="ts_icon ts_icon_home"></i>Home</a></li>
				<li><a href="/account" data-qa="account_profile"><i class="ts_icon ts_icon_user"></i>アカウントとプロフィール</a></li>
				<li><a href="/apps/manage" data-qa="configure_apps" target="_blank"><i class="ts_icon ts_icon_plug"></i>App 設定</a></li>
									<li><a href="/files" data-qa="files"><i class="ts_icon ts_icon_all_files clear_blue"></i>ファイル</a></li>
				
														<li><a href="/stats" data-qa="statistics"><i class="ts_icon ts_icon_dashboard"></i>アナリティクス</a></li>
													<li><a href="/customize" data-qa="customize"><i class="ts_icon ts_icon_magic"></i>カスタマイズ</a></li>
													<li><a href="/account/workspace-settings" data-qa="team_settings"><i class="ts_icon ts_icon_cog_o"></i>ワークスペースの設定</a></li>
							</ul>

			
		</div>

		<div id="footer">

			<ul id="footer_nav">
				<li><a href="/is" data-qa="tour">ツアー</a></li>
				<li><a href="/downloads" data-qa="download_apps">アプリのダウンロード</a></li>
				<li><a href="/brand-guidelines" data-qa="brand_guidelines">ブランドガイドライン</a></li>
				<li><a href="/help" data-qa="help">ヘルプ</a></li>
				<li><a href="https://api.slack.com" target="_blank" data-qa="api">API<i class="ts_icon ts_icon_external_link small_left_margin ts_icon_inherit"></i></a></li>
								<li><a href="/pricing?ui_step=96&ui_element=5" data-qa="pricing" data-clog-event="GROWTH_PRICING" data-clog-ui-element="pricing_link" data-clog-ui-action="click" data-clog-ui-step="admin_footer">料金プラン</a></li>
				<li><a href="/help/requests/new" data-qa="contact">連絡先</a></li>
				<li><a href="/terms-of-service" data-qa="policies">ポリシー</a></li>
				<li><a href="https://slackhq.com/" target="_blank" data-qa="our_blog">Slack 公式ブログ</a></li>
				<li><a href="https://slack.com/signout/17534698516?crumb=s-1521621718-1d02d07cf66af5323b24eefebc853f54b6b991ab3e0b16b9f5ebe57aab8af8d4-%E2%98%83" data-qa="sign_out">サインアウト<i class="ts_icon ts_icon_sign_out small_left_margin ts_icon_inherit"></i></a></li>
			</ul>

			<p id="footer_signature">Slack が <i class="ts_icon ts_icon_heart"></i> で作成</p>

		</div>

	</div>
</nav>	
			
<header>
			<a id="menu_toggle" class="no_transition" data-qa="menu_toggle_hamburger">
			<span class="menu_icon"></span>
			<span class="menu_label">Menu</span>
			<span class="vert_divider"></span>
		</a>
		<h1 id="header_team_name" class="inline_block no_transition" data-qa="header_team_name">
			<a href="/home">
				<i class="ts_icon ts_icon_home"></i>
				Morishima Lab
			</a>
		</h1>
		<div class="header_nav">
			<div class="header_btns float_right">
				<a href="" onclick="return false;" id="plans_switcher" data-qa="plans_switcher">
					<i class="ts_icon ts_icon_rocket ts_icon_inherit"></i>
					<span class="block label">料金プラン</span>
				</a>

				<ul id="header_plans_nav" data-qa="plans_switcher_menu">
					<li class="plans_switcher_item "><a data-clog-event="UPGRDEXP_PLANS_IN_TEAM_NAV" data-clog-ui-element="learn_more_standard" data-clog-ui-action="click" data-clog-ui-step="TEAM_NAV_PLANS_MENU"href="https://slack.com/pricing/standard?ui_element=53&ui_step=222">
												<span class="switcher_label">スタンダード</span>
					</a></li>
					<li class="plans_switcher_item "><a data-clog-event="UPGRDEXP_PLANS_IN_TEAM_NAV" data-clog-ui-element="learn_more_plus" data-clog-ui-action="click" data-clog-ui-step="TEAM_NAV_PLANS_MENU"href="https://slack.com/pricing/plus?ui_element=54&ui_step=222">
												<span class="switcher_label">プラス</span>
					</a></li>
					<li class="plans_switcher_item "><a data-clog-event="UPGRDEXP_PLANS_IN_TEAM_NAV" data-clog-ui-element="learn_more_enterprise" data-clog-ui-action="click" data-clog-ui-step="TEAM_NAV_PLANS_MENU"href="https://slack.com/plans/enterprise-grid?ui_element=55&ui_step=222">
												<span class="switcher_label">エンタープライズ</span>
					</a></li>
					<li class="plans_switcher_item "><a data-clog-event="UPGRDEXP_PLANS_IN_TEAM_NAV" data-clog-ui-element="pricing_link" data-clog-ui-action="click" data-clog-ui-step="TEAM_NAV_PLANS_MENU"href="https://slack.com/pricing/slack-for-teams?ui_element=5&ui_step=222">
												<span class="switcher_label">プランの比較</span>
					</a></li>
				</ul>

				<a href="" onclick="return false;" id="team_switcher" data-qa="team_switcher">
					<i class="ts_icon ts_icon_th_large ts_icon_inherit"></i>
					<span class="block label">ワークスペース</span>
				</a>
				<a href="/help" id="help_link" data-qa="help_link">
					<i class="ts_icon ts_icon_life_ring ts_icon_inherit"></i>
					<span class="block label">ヘルプ</span>
				</a>
															<a href="/messages" data-qa="launch">
							<img src="https://a.slack-edge.com/66f9/img/icons/ios-64.png" srcset="https://a.slack-edge.com/66f9/img/icons/ios-32.png 1x, https://a.slack-edge.com/66f9/img/icons/ios-64.png 2x" title="Slack" alt="Launch Slack"/>
							<span class="block label">起動する</span>
						</a>
												</div>
							<ul id="header_team_nav" data-qa="team_switcher_menu">
																		
<li class="active">
	<a href="https://morishimalab.slack.com/home" target="https://morishimalab.slack.com/">
					<i class="ts_icon small ts_icon_check_circle_o active_icon s"></i>
							<i class="team_icon small default">ML</i>
				<span class="switcher_label team_name">Morishima Lab</span>
	</a>
</li>																<li id="add_team_option"><a href="https://slack.com/signin" target="_blank"><i class="ts_icon ts_icon_plus team_icon small"></i> <span class="switcher_label">他のワークスペースにサインインする…</span></a></li>
				</ul>
					</div>
	
	
	
</header>	
	<div id="page" >

		<div id="page_contents" data-qa="page_contents" class="">

<p class="print_only">
	<strong>
	
	2018年3月16日金曜日 の 21:40に kayukawa によって作成されました
	</strong><br />
	<span class="subtle_silver break_word">https://morishimalab.slack.com/files/U4RTD3TLP/F9RUNPRHU/README_md.md</span>
</p>

<div class="file_header_container no_print"></div>

<div class="alert_container">
		

<div class="file_public_link_shared alert" style="display: none;">
		
	<i class="ts_icon ts_icon_link"></i> 共有リンク： <a class="file_public_link" href="https://slack-files.com/T0HFQLJF6-F9RUNPRHU-2db0e92631" target="new">https://slack-files.com/T0HFQLJF6-F9RUNPRHU-2db0e92631</a>
</div></div>

<div id="file_page" class="card top_padding">

	<p class="small subtle_silver no_print meta">
		
		2KB マークダウン記法 (raw) スニペットは <span class="date">2018年3月16日</span> に作成されました。
				このファイルはプライベートです。		<span class="file_share_list"></span>
	</p>

	<a id="file_action_cog" class="action_cog action_cog_snippet float_right no_print">
		<span>アクション </span><i class="ts_icon ts_icon_cog"></i>
	</a>
	<a id="snippet_expand_toggle" class="float_right no_print">
		<i class="ts_icon ts_icon_expand "></i>
		<i class="ts_icon ts_icon_compress hidden"></i>
	</a>

	<div class="large_bottom_margin clearfix">
		<pre id="file_contents"># List
### MyList.h &amp; .cpp
リストの構造を勉強するために自作した双方向リスト

### Example
```c++
int main(int argc, const char * argv[]) {
    MyList myList;             // MyList
    myList.pushBackNode(0);    // [0]
    myList.pushBackNode(5);    // [0, 5]
    myList.replaceNode(4, 1);  // [4, 5]
    myList.insertNode(2, 1);   // [2, 4, 5]
    myList.insertNode(3, 2);   // [2, 3, 4, 5]
    myList.insertNode(7, 5);   // [2, 3, 4, 5, 7]
    myList.insertNode(8, -1);  // [2, 3, 4, 5, 7, 8]
    myList.insertNode(6, -3);  // [2, 3, 4, 5, 6, 7, 8]
    myList.insertNode(1, -8);  // [1, 2, 3, 4, 5, 6, 7, 8]
    myList.popBackNode();      // [1, 2, 3, 4, 5, 6, 7]
    myList.deleteNode(2);      // [1, 3, 4, 5, 6, 7]
    myList.deleteNode(6);      // [1, 3, 4, 5, 6]
    myList.deleteNode(-1);     // [1, 3, 4, 5]
    myList.deleteNode(-2);     // [1, 3, 5]
    myList.deleteNode(-3);     // [3, 5]
    myList.display();          // &quot;3, 5&quot;と表示される
    return 0;
}
```
### メンバ関数
引数の`index`は負の値を入れると、**後ろから数えて`index`番目**となる  

#### `.pushbackNode(int newData)`
- リストの末尾に要素`newData`を追加

#### `.replaceNode(int newData, int index)`
- `index`番目の要素を`newData`に置き換える

#### `.insertNode(int newData, int index)`
- リストの`index`番目に`newData`を挿入

#### `.popBackNode()`
- リストの末尾の要素を削除

#### `.deleteNode(int index)`
- `index`番目の要素を削除

#### `.getData(int index)`
- `index`番目の要素を返す

#### `.getLenght()`
- 要素数を返す

#### `.display()`
- リストの要素を全て表示


</pre>

		<p class="file_page_meta no_print" style="line-height: 1.5rem;">
			<label class="checkbox normal mini float_right no_top_padding no_min_width">
				<input type="checkbox" id="file_preview_wrap_cb"> 長い行を折り返す			</label>
		</p>

	</div>

			<div id="comments_holder" class="clearfix clear_both">
	<div class="col span_1_of_6"></div>
	<div class="col span_4_of_6 no_right_padding">
		<div id="file_page_comments">
					</div>	
		

	<p class="p-external_file_author_notice hidden">
		
			<strong class="dull_grey">コメントを表示できません</strong><br />
			このファイルは別のワークスペースのファイルです。
			</p>

	<form action="https://morishimalab.slack.com/files/U4RTD3TLP/F9RUNPRHU/README_md.md"
			id="file_comment_form"
							class="comment_form clearfix"
						method="post">
					<a href="/team/U96LUJC06" class="member_preview_link" data-member-id="U96LUJC06" >
				<span class="member_image thumb_36" style="background-image: url('https://secure.gravatar.com/avatar/665b539af6e6d984271e004a5800c439.jpg?s=72&d=https%3A%2F%2Fa.slack-edge.com%2F66f9%2Fimg%2Favatars%2Fava_0009-72.png')" data-thumb-size="36" data-member-id="U96LUJC06"></span>
			</a>
				<input type="hidden" name="addcomment" value="1" />
		<input type="hidden" name="crumb" value="s-1521621718-b4003ac1a2f36256c984b0d46687eaba792b74221f494fb630d44c0f6a428c9f-☃" />

		<div id="file_comment" class="small texty_comment_input comment_input small_bottom_margin" name="comment" wrap="virtual" ></div>
		<div class="file_comment_submit_container display_flex justify_content_between">
			<button type="submit" class="file_comment_submit_btn btn align_self_start   ladda-button" data-style="expand-right"><span class="ladda-label">コメントを追加する</span></button>
			<span class="input_note indifferent_grey file_comment_tip">shift+enter で改行</span>		</div>
	</form>

<form
		id="file_edit_comment_form"
					class="edit_comment_form clearfix hidden"
				method="post">
		<div id="file_edit_comment" class="small texty_comment_input comment_input small_bottom_margin" name="comment" wrap="virtual"></div>
	<input type="submit" class="save btn float_right " value="保存" />
	<button class="cancel btn btn_outline float_right small_right_margin ">キャンセル</button>
</form>	
	</div>
	<div class="col span_1_of_6"></div>
</div>	
</div>


	
		
	</div>
	<div id="overlay"></div>
</div>







<script type="text/javascript">

	/**
	 * A placeholder function that the build script uses to
	 * replace file paths with their CDN versions.
	 *
	 * @param {String} file_path - File path
	 * @returns {String}
	 */
	function vvv(file_path) {

		var vvv_warning = 'You cannot use vvv on dynamic values. Please make sure you only pass in static file paths.';
		if (TS && TS.warn) {
			TS.warn(vvv_warning);
		} else {
			console.warn(vvv_warning);
		}

		return file_path;
	}

	var cdn_url = "https:\/\/a.slack-edge.com";
	var vvv_abs_url = "https:\/\/slack.com\/";
	var inc_js_setup_data = {
			emoji_sheets: {
			apple: 'https://a.slack-edge.com/c00d19/img/emoji_2017_12_06/sheet_apple_64_indexed_256.png',
			google: 'https://a.slack-edge.com/c00d19/img/emoji_2017_12_06/sheet_google_64_indexed_256.png',
		},
		emoji5: true,
		};
</script>
	<script type="text/javascript">
<!--
	// common boot_data
	var boot_data = {
		start_ms: Date.now(),
		app: "web",
		user_id: 'U96LUJC06',
		team_id: 'T0HFQLJF6',
		visitor_uid: ".1ogr6nz34yqs4kw0soggggo0k",
		no_login: false,
		version_ts: "1521608838",
		version_uid: "9fb27c557389983b20670d553627bcb34e33b07e",
		cache_version: "v16-giraffe",
		cache_ts_version: "v2-bunny",
		redir_domain: "slack-redir.net",
		signin_url: 'https://slack.com/signin',
		abs_root_url: "https:\/\/slack.com\/",
		api_url: '/api/',
		team_url: "https:\/\/morishimalab.slack.com\/",
		image_proxy_url: "https:\/\/slack-imgs.com\/",
		beacon_timing_url: "https:\/\/slack.com\/beacon\/timing",
		beacon_error_url: "https:\/\/slack.com\/beacon\/error",
		clog_url: "clog\/track\/",
		api_token: "xoxs-17534698516-312708624006-329650241952-33fb7cc167",
		ls_disabled: false,
		hc_tracking_qs: "sid=zd-uf-t0hfqljf6-u96lujc06",

		vvv_paths: {
			
		lz_string: "https:\/\/a.slack-edge.com\/bv1-1\/lz-string-1.4.4.worker.ja-JP.8de1b00d670ff3dc706a0.js",
		codemirror: "https:\/\/a.slack-edge.com\/bv1-1\/codemirror.min.ja-JP.9fadfede9234a14d7ff7.min.js",
	codemirror_addon_simple: "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_simple.ja-JP.e75f1c32be6b0dbe5c60.min.js",
	codemirror_load: "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_load.ja-JP.80564916da27ccb044ce.min.js",

	// Silly long list of every possible file that Codemirror might load
	codemirror_files: {
		'apl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_apl.ja-JP.5dd6cfbb6c74011d9a1b.min.js",
		'asciiarmor': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_asciiarmor.ja-JP.a41b23cbc3d1d65b4c6e.min.js",
		'asn.1': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_asn.1.ja-JP.0f5fa928b66549e12424.min.js",
		'asterisk': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_asterisk.ja-JP.991cdc1f26f92b2868eb.min.js",
		'brainfuck': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_brainfuck.ja-JP.c22e45ee304b90f19cc1.min.js",
		'clike': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_clike.ja-JP.42e3c930a34d405b0c6d.min.js",
		'clojure': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_clojure.ja-JP.eb56fae392aaa75f6c5b.min.js",
		'cmake': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_cmake.ja-JP.f7406c4f0d7aa7b508cc.min.js",
		'cobol': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_cobol.ja-JP.43dd8f375a39744589d7.min.js",
		'coffeescript': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_coffeescript.ja-JP.07f3a11d90dec5a4388c.min.js",
		'commonlisp': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_commonlisp.ja-JP.3b6b756b26138f7104a1.min.js",
		'css': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_css.ja-JP.0f3e3262d0a44d6924b5.min.js",
		'crystal': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_crystal.ja-JP.c5094ca77d539fd253fd.min.js",
		'cypher': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_cypher.ja-JP.0e95d7c27a3366ebaa8b.min.js",
		'd': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_d.ja-JP.f8bbb8b4edc8b64ac4ba.min.js",
		'dart': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_dart.ja-JP.88316b5b6b8d5cb30d9a.min.js",
		'diff': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_diff.ja-JP.6f09e4632015c913a963.min.js",
		'django': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_django.ja-JP.8e0803562d3bc1e5fea8.min.js",
		'dockerfile': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_dockerfile.ja-JP.752c97a8687fde334a2d.min.js",
		'dtd': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_dtd.ja-JP.38b8adab6eb54ea9a7f5.min.js",
		'dylan': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_dylan.ja-JP.436c5ecc7f3a204033c4.min.js",
		'ebnf': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ebnf.ja-JP.decc7657e95082a77b77.min.js",
		'ecl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ecl.ja-JP.977f7346be54a06f7a3f.min.js",
		'eiffel': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_eiffel.ja-JP.08178d3cf582c2b84bee.min.js",
		'elm': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_elm.ja-JP.7d3f717a452ccbf6ecc6.min.js",
		'erlang': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_erlang.ja-JP.baf48194e7e92d736a4c.min.js",
		'factor': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_factor.ja-JP.12bcd00afc14bbcb771a.min.js",
		'forth': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_forth.ja-JP.c5047a146d2ca569938f.min.js",
		'fortran': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_fortran.ja-JP.3fcc6e0ce8dbf33a81ff.min.js",
		'gas': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_gas.ja-JP.acf97bb65256477ff466.min.js",
		'gfm': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_gfm.ja-JP.b4f2c09f3817997defbd.min.js",
		'gherkin': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_gherkin.ja-JP.1d1ae826d7dce68e85c3.min.js",
		'go': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_go.ja-JP.ccd5bdac1dd07f3ecb55.min.js",
		'groovy': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_groovy.ja-JP.ce718994a9bcb55215d0.min.js",
		'haml': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_haml.ja-JP.0b139283a88f61ea3ba4.min.js",
		'handlebars': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_handlebars.ja-JP.ecdcca7c65be407f1353.min.js",
		'haskell': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_haskell.ja-JP.59c5cbc9a58a36d0c439.min.js",
		'haxe': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_haxe.ja-JP.a0d009a7edba7ea09ef6.min.js",
		'htmlembedded': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_htmlembedded.ja-JP.4a74fd5e0a6a51d5d54d.min.js",
		'htmlmixed': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_htmlmixed.ja-JP.6ebac2ac64597bd6e1df.min.js",
		'http': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_http.ja-JP.0d245426dd99e4c59000.min.js",
		'idl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_idl.ja-JP.88db6057120bc2547dd5.min.js",
		'jade': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_jade.ja-JP.71a54458f58bc4b68e3f.min.js",
		'javascript': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_javascript.ja-JP.389df48dbd60e85bf8f5.min.js",
		'jinja2': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_jinja2.ja-JP.68136a0b6c06e457477c.min.js",
		'julia': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_julia.ja-JP.d920a08df406fa679f00.min.js",
		'livescript': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_livescript.ja-JP.7b4ff2205e7ae35f2fd1.min.js",
		'lua': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_lua.ja-JP.5430adae0fdcf5a8af88.min.js",
		'markdown': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_markdown.ja-JP.3c45012a88447b83b79e.min.js",
		'mathematica': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_mathematica.ja-JP.2b0b3d225cc75ffb42aa.min.js",
		'mirc': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_mirc.ja-JP.81e20c9caad98405cfa0.min.js",
		'mllike': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_mllike.ja-JP.7dc700f7956f5f29dcb2.min.js",
		'modelica': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_modelica.ja-JP.c3739975e792bdf33f41.min.js",
		'mscgen': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_mscgen.ja-JP.e6ff396367b573a6245d.min.js",
		'mumps': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_mumps.ja-JP.ac744d5c78a6b8ed8e25.min.js",
		'nginx': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_nginx.ja-JP.70a7e49424ac9260a1a4.min.js",
		'nsis': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_nsis.ja-JP.b1003d164d0f830c5292.min.js",
		'ntriples': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ntriples.ja-JP.234cbd9042b3e4930d80.min.js",
		'octave': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_octave.ja-JP.9c39a203b0546d69e49b.min.js",
		'oz': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_oz.ja-JP.a185987eb4aee4c4c483.min.js",
		'pascal': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_pascal.ja-JP.d7cb39f67f816ac5f70c.min.js",
		'pegjs': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_pegjs.ja-JP.d48014adc2d476f100f7.min.js",
		'perl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_perl.ja-JP.9eff7897d593fa7909b0.min.js",
		'php': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_php.ja-JP.c4d7408406988766c000.min.js",
		'pig': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_pig.ja-JP.a9a45127eb208de66bd1.min.js",
		'powershell': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_powershell.ja-JP.3655a4b91d2b793055ed.min.js",
		'properties': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_properties.ja-JP.054516bacd8f764024cb.min.js",
		'puppet': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_puppet.ja-JP.a4dc8c6a55a5aa2aecad.min.js",
		'python': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_python.ja-JP.457580c3e5d0f79c0fa4.min.js",
		'q': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_q.ja-JP.02fb8f6d22542d1080a0.min.js",
		'r': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_r.ja-JP.f796025d85390621d3de.min.js",
		'rpm': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_rpm.ja-JP.886bb519af354257b6ed.min.js",
		'rst': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_rst.ja-JP.8e142009405d604e93a3.min.js",
		'ruby': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ruby.ja-JP.89c6e9538842c321336e.min.js",
		'rust': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_rust.ja-JP.ddab0663452bdc37781f.min.js",
		'sass': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_sass.ja-JP.98b63a94fadb0cc593f8.min.js",
		'scheme': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_scheme.ja-JP.65c601f4ddec1db63b65.min.js",
		'shell': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_shell.ja-JP.69cb797a339e77f4f241.min.js",
		'sieve': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_sieve.ja-JP.afd6c2623f8dc9146fee.min.js",
		'slim': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_slim.ja-JP.09c9df29673e390c3b90.min.js",
		'smalltalk': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_smalltalk.ja-JP.b4a8a375fb8f99be24a4.min.js",
		'smarty': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_smarty.ja-JP.1b760013b42caa1bba60.min.js",
		'solr': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_solr.ja-JP.0dd0690063b1e51efaf9.min.js",
		'soy': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_soy.ja-JP.3a56391abb201bcfdf12.min.js",
		'sparql': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_sparql.ja-JP.50e6e16e3fb694565309.min.js",
		'spreadsheet': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_spreadsheet.ja-JP.c5284ef36904777caf7f.min.js",
		'sql': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_sql.ja-JP.1ea2a5212e5c0f8f88d7.min.js",
		'stex': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_stex.ja-JP.b602579ba304e02ddd46.min.js",
		'stylus': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_stylus.ja-JP.e4295e4120cf30854093.min.js",
		'swift': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_swift.ja-JP.491c50d540b24c5560bb.min.js",
		'tcl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_tcl.ja-JP.7bc06f8a1724f262a8b1.min.js",
		'textile': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_textile.ja-JP.af130e1e481e5434d650.min.js",
		'tiddlywiki': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_tiddlywiki.ja-JP.7f4ebaa39dd7d66fcec1.min.js",
		'tiki': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_tiki.ja-JP.675c6850e73cfe2a32fd.min.js",
		'toml': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_toml.ja-JP.48538e8a7bf6902fa562.min.js",
		'tornado': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_tornado.ja-JP.2be3bf5d62b95b13534d.min.js",
		'troff': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_troff.ja-JP.01cdf38b9bc5fcdeef5c.min.js",
		'ttcn': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ttcn.ja-JP.fd0fa4848b7a5546fa86.min.js",
		'ttcn:cfg': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_ttcn-cfg.ja-JP.a676f9bad7ad30bef9cc.min.js",
		'turtle': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_turtle.ja-JP.65504a43ff1943b22df9.min.js",
		'twig': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_twig.ja-JP.683ac11317e47ff28373.min.js",
		'vb': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_vb.ja-JP.ae2a03ccd48c3c31584c.min.js",
		'vbscript': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_vbscript.ja-JP.946bda5585caf1630532.min.js",
		'velocity': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_velocity.ja-JP.30224314f97f1b316553.min.js",
		'verilog': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_verilog.ja-JP.35f05f77473cdbea70a8.min.js",
		'vhdl': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_vhdl.ja-JP.a9d047e83ae9a6834772.min.js",
		'vue': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_vue.ja-JP.f68600d8ceadd124599d.min.js",
		'xml': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_xml.ja-JP.80dfc213affdeb352087.min.js",
		'xquery': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_xquery.ja-JP.4b445fdd408ae6f5e9b6.min.js",
		'yaml': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_yaml.ja-JP.b832f9781d2f905a8ce4.min.js",
		'z80': "https:\/\/a.slack-edge.com\/bv1-1\/codemirror_lang_z80.ja-JP.30cc5b4979d9cbdb1e66.min.js"
	}		},

		notification_sounds: [{"value":"b2.mp3","label":"Ding","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/b2.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/b2.ogg"},{"value":"animal_stick.mp3","label":"Boing","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/animal_stick.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/animal_stick.ogg"},{"value":"been_tree.mp3","label":"Drop","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/been_tree.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/been_tree.ogg"},{"value":"complete_quest_requirement.mp3","label":"Ta-da","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/complete_quest_requirement.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/complete_quest_requirement.ogg"},{"value":"confirm_delivery.mp3","label":"Plink","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/confirm_delivery.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/confirm_delivery.ogg"},{"value":"flitterbug.mp3","label":"Wow","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/flitterbug.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/flitterbug.ogg"},{"value":"here_you_go_lighter.mp3","label":"Here you go","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/here_you_go_lighter.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/here_you_go_lighter.ogg"},{"value":"hi_flowers_hit.mp3","label":"Hi","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/hi_flowers_hit.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/hi_flowers_hit.ogg"},{"value":"knock_brush.mp3","label":"Knock Brush","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/knock_brush.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/knock_brush.ogg"},{"value":"save_and_checkout.mp3","label":"Whoa!","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/save_and_checkout.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/save_and_checkout.ogg"},{"value":"item_pickup.mp3","label":"Yoink","url":"https:\/\/slack.global.ssl.fastly.net\/7e91\/sounds\/push\/item_pickup.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/item_pickup.ogg"},{"value":"hummus.mp3","label":"Hummus","url":"https:\/\/slack.global.ssl.fastly.net\/7fa9\/sounds\/push\/hummus.mp3","url_ogg":"https:\/\/slack.global.ssl.fastly.net\/46ebb\/sounds\/push\/hummus.ogg"},{"value":"none","label":"\u306a\u3057"}],
		alert_sounds: [{"value":"frog.mp3","label":"Frog","url":"https:\/\/slack.global.ssl.fastly.net\/a34a\/sounds\/frog.mp3"}],
		call_sounds: [{"value":"call\/alert_v2.mp3","label":"\u30a2\u30e9\u30fc\u30c8","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/alert_v2.mp3"},{"value":"call\/incoming_ring_v2.mp3","label":"\u7740\u4fe1","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/incoming_ring_v2.mp3"},{"value":"call\/outgoing_ring_v2.mp3","label":"\u767a\u4fe1","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/outgoing_ring_v2.mp3"},{"value":"call\/pop_v2.mp3","label":"\u7740\u4fe1\u30ea\u30a2\u30af\u30b7\u30e7\u30f3","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/pop_v2.mp3"},{"value":"call\/they_left_call_v2.mp3","label":"\u76f8\u624b\u304c\u901a\u8a71\u304b\u3089\u9000\u51fa\u3057\u307e\u3057\u305f","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/they_left_call_v2.mp3"},{"value":"call\/you_left_call_v2.mp3","label":"\u901a\u8a71\u304b\u3089\u9000\u51fa\u3057\u307e\u3057\u305f","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/you_left_call_v2.mp3"},{"value":"call\/they_joined_call_v2.mp3","label":"\u76f8\u624b\u304c\u901a\u8a71\u306b\u53c2\u52a0\u3057\u307e\u3057\u305f","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/they_joined_call_v2.mp3"},{"value":"call\/you_joined_call_v2.mp3","label":"\u901a\u8a71\u306b\u53c2\u52a0\u3057\u307e\u3057\u305f","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/you_joined_call_v2.mp3"},{"value":"call\/confirmation_v2.mp3","label":"\u78ba\u8a8d","url":"https:\/\/slack.global.ssl.fastly.net\/08f7\/sounds\/call\/confirmation_v2.mp3"}],
		call_sounds_version: "v2",
				default_tz: "America\/Los_Angeles",
		
		feature_tinyspeck: false,
		feature_create_team_google_auth: false,
		feature_enterprise_custom_tos: true,
		feature_webapp_always_collect_initial_time_period_stats: false,
		feature_search_skip_context: false,
		feature_buildy_css: false,
		feature_flannel_use_canary_sometimes: false,
		feature_deprecate_window_cert: true,
		feature_deprecate_window_cert_block: true,
		feature_deprecate_files: false,
		feature_deprecate_get_member_by_name: false,
		feature_usergroup_highlight_words: true,
		feature_prev_reached_end: true,
		feature_modern_upsert_file: true,
		feature_file_threads: false,
		feature_more_pins_info: false,
		feature_threads_perf: false,
		feature_message_replies_inline: false,
		feature_group_deletion: true,
		feature_subteam_members_diff: true,
		feature_a11y_keyboard_shortcuts: false,
		feature_email_ingestion: false,
		feature_api_site_tools: false,
		feature_msg_consistency: false,
		feature_sidebar_context_menu: false,
		feature_attachments_inline: false,
		feature_fix_files: true,
		feature_channel_eventlog_client: true,
		feature_paging_api: false,
		feature_custom_status_expiry: false,
		feature_m11n_custom_status_input: false,
		feature_enterprise_app_teams: true,
		feature_enterprise_frecency: false,
		feature_ent_app_management_dashboard: false,
		feature_set_away_dialog_behavior: true,
		feature_ent_app_management_restriction: false,
		feature_entitlements: true,
		feature_grid_archive_link_fixes: true,
		feature_dunning: true,
		feature_invoice_dunning: true,
		feature_safeguard_org_retention: true,
		feature_dashboard_sortable_lists: false,
		feature_refactor_admin_stats: false,
		feature_invite_only_workspaces: true,
		feature_leave_workspace_improvements: true,
		feature_enteprise_user_teams_update: false,
		feature_enterprise_org_wide_channels_section: true,
		feature_show_billing_active_for_grid: true,
		feature_find_your_workspace: false,
		feature_compliance_export_helper_copy: false,
		feature_form_text_character_count_copy: false,
		feature_sk_lato_cleanup: false,
		feature_saml_authn_key_expiry_date: true,
		feature_wta_client_support: true,
		feature_xoxa_channel_authorization: true,
		feature_wta_optional_ephemeral_message: false,
		feature_file_links_betterer: false,
		feature_enterprise_dm_deeplink: false,
		feature_session_duration_saved_message: false,
		feature_guest_api_changes: false,
		feature_sso_jit_disabling: true,
		feature_channel_alert_words: false,
		feature_connecting_shared_channels_enterprise: false,
		feature_shared_channels_enterprise: false,
		feature_snapshots_the_revenge: false,
		feature_mpim_channels: false,
		feature_esc_connected_workspaces_search: false,
		feature_deprecate_gateways: true,
		feature_conversations_list: true,
		feature_gdpr_user_join_tos: false,
		feature_modernize_admin: false,
		feature_winssb_beta_channel: false,
		feature_slack_astronaut_i18n_jpn: true,
		feature_i18n_customer_stories: false,
		feature_cust_acq_i18n_tweaks: false,
		feature_gdpr_website_update: true,
		feature_gdpr_forget_user: false,
		feature_sales_lp: true,
		feature_presence_sub: true,
		feature_whitelist_zendesk_chat_widget: false,
		feature_live_support_free_plan: false,
		feature_slackbot_goes_to_college: false,
		feature_newxp_enqueue_message: true,
		feature_teambot: false,
		feature_star_shortcut: false,
		feature_show_jumper_scores: true,
		feature_force_ls_compression: false,
		feature_name_tagging_client: true,
		feature_name_tagging_client_autocomplete: false,
		feature_name_tagging_client_topic_purpose: false,
		feature_use_imgproxy_resizing: true,
		feature_share_mention_comment_cleanup: false,
		feature_external_files: false,
		feature_electron_memory_logging: false,
		feature_channel_exports: false,
		feature_free_inactive_domains: true,
		feature_take_profile_photo: false,
		feature_arugula: false,
		feature_texty_rewrite_on_paste: false,
		feature_deprecate_screenhero: true,
		feature_calls_esc_ui: true,
		feature_toggle_id_translation: true,
		feature_modern_api_q: false,
		feature_default_shared_channels: true,
		feature_default_shared_channels_whats_new: true,
		feature_email_notifications_improvements: true,
		feature_react_lfs: false,
		feature_log_quickswitcher_queries: true,
		feature_enable_mdm: true,
		feature_message_menus: true,
		feature_new_message_click_logging: true,
		feature_announce_only_channels: false,
		feature_app_permissions_backend_enterprise: true,
		feature_token_ip_whitelist: true,
		feature_hide_join_leave: false,
		feature_rollback_to_mapping: false,
		feature_emoji5: true,
		feature_sidebar_theme_undo: false,
		feature_emoji5_dark_launch: true,
		feature_feature_emoji5: false,
		feature_allow_intra_word_formatting: true,
		feature_allow_cjk_autocomplete: true,
		feature_allow_split_word: false,
		feature_i18n_channels_validate_emoji: true,
		feature_slim_scrollbar: false,
		feature_search_query_refinements: true,
		feature_react_search: false,
		feature_sidebar_filters: false,
		feature_sli_channel_archive_suggestions: true,
		feature_unread_counts_without_history: true,
		feature_react_messages: true,
		feature_clipboard_contents: false,
		feature_redux_modals: false,
		feature_react_pin_author: true,
		feature_mrkdwn_truncation: true,
		feature_m11n_channels_join: true,
		feature_m11n_metrics_responsiveness: false,
		feature_react_member_profile_card: false,
		feature_hide_membership_counts_in_channel_browser: true,
		feature_service_import_lfs: false,
		feature_mpdm_default_fe: false,
		feature_channel_notif_dialog_update: false,
		feature_oauth_react_wta: false,
		feature_react_team_picker: false,
		feature_app_index: false,
		feature_app_profile_app_site_link: false,
		feature_custom_app_installs: false,
		feature_gdrive_do_not_install_by_default: true,
		feature_delete_moved_channels: true,
		feature_single_workspace_redirect: true,
		feature_zero_workspace_onboarding: true,
		feature_user_tos: false,
		feature_oom_mv_channels_list: false,
		feature_solr_discoverability: true,
		feature_sso_formatting_error: false,
		feature_single_user_workspace_pagination: true,
		feature_default_workspaces_to_closed: true,
		feature_ms_msg_handlers_profiling: true,
		feature_cross_workspace_quick_switcher_prototype: false,
		feature_org_quick_switcher: false,
		feature_user_prefs_merge_using_custom_callbacks: true,
		feature_ms_latest: true,
		feature_no_preload_video: true,
		feature_guests_use_entitlements: true,
		feature_emoji_picker_frecently_used: false,
		feature_app_space: true,
		feature_app_canvases: false,
		feature_canvases: false,
		feature_stop_loud_channel_mentions: false,
		feature_message_input_byte_limit: false,
		feature_beacon_js_errors: false,
		feature_dialogs_v2_mobile: false,
		feature_user_app_disable_speed_bump: false,
		feature_nudge_team_creators: false,
		feature_onedrive_picker: false,
		feature_lesson_onboarding: true,
		feature_disable_join_notifications: false,
		feature_api_admin_page_not_ent: true,
		feature_faster_channels_browser_render: true,
		feature_non_blocking_user_boot: true,
		feature_non_wasted_flannel_connection: true,
		feature_no_files_info: true,
		feature_less_pins: true,
		feature_runaway_qs: false,
		feature_dark_qs: true,
		feature_delete_team_and_apps: true,
		feature_email_forwarding: true,
		feature_pjpeg: false,
		feature_pdf_thumb: true,
		feature_apps_manage_permissions_scope_changes: true,
		feature_app_dir_only_default_true: false,
		feature_reminder_cross_workspace: false,
		feature_speedy_boot_handlebars: false,
		feature_wta_web_flannel_membership: true,
		feature_better_web_app_model: false,
		feature_channel_invite_modal_cannot_join: false,
		feature_expiring_credits: true,
		feature_email_prefs: true,
		feature_pricing_calculator: false,
		feature_sonic: false,
		feature_flannel_channels_v0: false,
		feature_flannel_always_use_canary: false,
		feature_lazy_channels: false,
		feature_webclient_load_status_site: false,
		feature_react_channel_header: false,
		feature_global_nav: false,
		feature_shortcuts_flexpane: true,
		feature_app_directory_home_page_redesign: true,
		feature_hidden_wksp_unfurls: false,
		feature_guest_wksp_unfurls: false,
		feature_add_vat_tax: true,
		feature_workspace_scim_management: false,
		feature_email_previewer: false,
		feature_redux_dev_tools: false,
		feature_unified_member: false,
		feature_turn_mpdm_notifs_on: true,
		feature_browser_dragndrop: false,
		feature_granular_shared_channel_perms: false,
		feature_org_detailed_thread_mentions: true,
		feature_force_production_channel: false,
		feature_quill_upgrade: true,
		feature_offline_hint: false,
		feature_aria_msg_summary: false,
		feature_emoji_substr_search: false,
		feature_texty_formatting_commands: false,
		feature_texty_change_queue: false,
		feature_texty_lists: false,
		feature_shortcuts_prompt: true,
		feature_accessible_dialogs: true,
		feature_app_actions: false,
		feature_app_actions_fe: false,
		feature_app_actions_fe_frecency: false,
		feature_app_actions_response_url: true,
		feature_shared_channel_free_trial_flow: true,
		feature_i18n_compliance_links: false,
		feature_calls_clipboard_broadcasting_optin: true,
		feature_autocomplete_files: true,
		feature_screen_share_needs_aero: false,
		feature_calls_disable_iss_admin: true,
		feature_sidebar_realtime_priority: false,
		feature_in_prod_trials: true,
		feature_billing_ce_request_last4: true,
		feature_sli_explore: false,
		feature_sli_trending_dashboard: false,
		feature_i18n_custom_status: false,
		feature_i18n_select_empty_state_string: false,
		feature_drift_on_plans_page: true,
		feature_cjk_highlight_words: false,
		feature_accessible_fs_dialogs: true,
		feature_channel_browser_dropdown: true,
		feature_slackday_unsent_msg_sync: false,
		feature_trap_kb_within_fs_modals: true,
		feature_date_picker: false,

	client_logs: {"0":{"numbers":[0],"user_facing":false},"2":{"numbers":[2],"user_facing":false},"4":{"numbers":[4],"user_facing":false},"5":{"numbers":[5],"user_facing":false},"23":{"numbers":[23],"user_facing":false},"sounds":{"name":"sounds","numbers":[37]},"37":{"name":"sounds","numbers":[37],"user_facing":true},"47":{"numbers":[47],"user_facing":false},"48":{"numbers":[48],"user_facing":false},"Message History":{"name":"Message History","numbers":[58]},"58":{"name":"Message History","numbers":[58],"user_facing":true},"67":{"numbers":[67],"user_facing":false},"72":{"numbers":[72],"user_facing":false},"73":{"numbers":[73],"user_facing":false},"82":{"numbers":[82],"user_facing":false},"88":{"numbers":[88],"user_facing":false},"91":{"numbers":[91],"user_facing":false},"93":{"numbers":[93],"user_facing":false},"96":{"numbers":[96],"user_facing":false},"99":{"numbers":[99],"user_facing":false},"Channel Marking (MS)":{"name":"Channel Marking (MS)","numbers":[141]},"141":{"name":"Channel Marking (MS)","numbers":[141],"user_facing":true},"Channel Marking (Client)":{"name":"Channel Marking (Client)","numbers":[142]},"142":{"name":"Channel Marking (Client)","numbers":[142],"user_facing":true},"Close Old IMs (Client)":{"name":"Close Old IMs (Client)","numbers":[221]},"221":{"name":"Close Old IMs (Client)","numbers":[221],"user_facing":true},"365":{"numbers":[365],"user_facing":false},"389":{"numbers":[389],"user_facing":false},"438":{"numbers":[438],"user_facing":false},"444":{"numbers":[444],"user_facing":false},"481":{"numbers":[481],"user_facing":false},"488":{"numbers":[488],"user_facing":false},"529":{"numbers":[529],"user_facing":false},"552":{"numbers":[552],"user_facing":false},"dashboard":{"name":"dashboard","numbers":[666]},"666":{"name":"dashboard","numbers":[666],"user_facing":false},"667":{"numbers":[667],"user_facing":false},"773":{"numbers":[773],"user_facing":false},"777":{"numbers":[777],"user_facing":false},"794":{"numbers":[794],"user_facing":false},"Client Responsiveness":{"name":"Client Responsiveness","user_facing":false,"numbers":[808]},"808":{"name":"Client Responsiveness","user_facing":false,"numbers":[808]},"Message Pane Scrolling":{"name":"Message Pane Scrolling","numbers":[888]},"888":{"name":"Message Pane Scrolling","numbers":[888],"user_facing":true},"Unread banner and divider":{"name":"Unread banner and divider","numbers":[999]},"999":{"name":"Unread banner and divider","numbers":[999],"user_facing":true},"1000":{"numbers":[1000],"user_facing":false},"Duplicate badges (desktop app icons)":{"name":"Duplicate badges (desktop app icons)","numbers":[1701]},"1701":{"name":"Duplicate badges (desktop app icons)","numbers":[1701],"user_facing":true},"Members":{"name":"Members","numbers":[1975]},"1975":{"name":"Members","numbers":[1975],"user_facing":true},"lazy loading":{"name":"lazy loading","numbers":[1989]},"1989":{"name":"lazy loading","numbers":[1989],"user_facing":true},"thin_channel_membership":{"name":"thin_channel_membership","numbers":[1990]},"1990":{"name":"thin_channel_membership","numbers":[1990],"user_facing":true},"stats":{"name":"stats","numbers":[1991]},"1991":{"name":"stats","numbers":[1991],"user_facing":true},"ms":{"name":"ms","numbers":[1996]},"1996":{"name":"ms","numbers":[1996],"user_facing":true},"shared_channels_connection":{"name":"shared_channels_connection","numbers":[1999]},"1999":{"name":"shared_channels_connection","numbers":[1999],"user_facing":false},"dnd":{"name":"dnd","numbers":[2002]},"2002":{"name":"dnd","numbers":[2002],"user_facing":true},"2003":{"numbers":[2003],"user_facing":false},"Threads":{"name":"Threads","numbers":[2004]},"2004":{"name":"Threads","numbers":[2004],"user_facing":true},"2005":{"numbers":[2005],"user_facing":false},"Reactions":{"name":"Reactions","numbers":[2006]},"2006":{"name":"Reactions","numbers":[2006],"user_facing":true},"TSSSB.focusTabAndSwitchToChannel":{"name":"TSSSB.focusTabAndSwitchToChannel","numbers":[2007]},"2007":{"name":"TSSSB.focusTabAndSwitchToChannel","numbers":[2007],"user_facing":false},"Presence Detection":{"name":"Presence Detection","numbers":[2017]},"2017":{"name":"Presence Detection","numbers":[2017],"user_facing":true},"mc_sibs":{"name":"mc_sibs","numbers":[9999]},"9999":{"name":"mc_sibs","numbers":[9999],"user_facing":false},"Member searching":{"name":"Member searching","numbers":[90211]},"90211":{"name":"Member searching","numbers":[90211],"user_facing":true},"98765":{"numbers":[98765],"user_facing":false},"8675309":{"numbers":[8675309],"user_facing":false}},


		img: {
			app_icon: 'https://a.slack-edge.com/272a/img/slack_growl_icon.png'
		},
		page_needs_custom_emoji: false,
		page_needs_enterprise: false	};

	
	
	
	
	// i18n locale map (eg: maps Slack `ja-jp` to ZD `ja`)
			boot_data.slack_to_zd_locale = {"en-us":"en-us","fr-fr":"fr-fr","de-de":"de","es-es":"es","ja-jp":"ja"};
	
	// client boot data
		
			boot_data.should_use_flannel = true;
				boot_data.page_has_incomplete_user_model = true;
		boot_data.flannel_server_pool = "random";
		
	
	
	
	
	
	// inline_emoji
	boot_data.pref_emoji_mode = "default";
	boot_data.pref_jumbomoji = 1;
	boot_data.pref_messages_theme = "default";

//-->
</script>
		





	<!-- output_js "libs" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/emoji_5.ja-JP.eea6d384405ccf863b0a.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/rollup-core_required_libs.ja-JP.4b98158f4f9ecedce8f4.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

	<!-- output_js "application" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/modern.vendor.ja-JP.45bed3f92c13898f39d8.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/application.ja-JP.1ca5743bf9574581fbfa.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

	<!-- output_js "page" -->

		<!-- output_js "core" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/rollup-core_required_ts.ja-JP.571f75bcc33996f8c740.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/TS.web.ja-JP.a82295be4792f5d5dfee.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

	<!-- output_js "core_web" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/rollup-core_web.ja-JP.fc286094cd14587b5c73.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

	<!-- output_js "secondary" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/rollup-secondary_a_required.ja-JP.e760f53416344d72981b.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/rollup-secondary_b_required.ja-JP.e0d8e31c41edf4208f88.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>

				
	
	<script type="text/javascript">TS.boot(boot_data);</script>

	<!-- output_js "regular" -->
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/TS.web.comments.ja-JP.bcceefed7dc48ba0df1d.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/TS.web.file.ja-JP.6ea1e6e0dd40a74a89e6.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/codemirror.min.ja-JP.9fadfede9234a14d7ff7.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/codemirror_simple.ja-JP.e75f1c32be6b0dbe5c60.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>
<script type="text/javascript" src="https://a.slack-edge.com/bv1-1/codemirror_load.ja-JP.80564916da27ccb044ce.min.js" crossorigin="anonymous" onload="window._cdn && _cdn.ok(this, arguments)" onerror="window._cdn && _cdn.failed(this, arguments)"></script>


			<script type="text/javascript">
	<!--
		boot_data.page_needs_custom_emoji = true;

		boot_data.file = {"id":"F9RUNPRHU","created":1521204033,"timestamp":1521204033,"name":"README_md.md","title":"README.md","mimetype":"text\/plain","filetype":"markdown","pretty_type":"\u30de\u30fc\u30af\u30c0\u30a6\u30f3\u8a18\u6cd5 (raw)","user":"U4RTD3TLP","editable":true,"size":1799,"mode":"snippet","is_external":false,"external_type":"","is_public":false,"public_url_shared":false,"display_as_bot":false,"username":"","url_private":"https:\/\/files.slack.com\/files-pri\/T0HFQLJF6-F9RUNPRHU\/README_md.md","url_private_download":"https:\/\/files.slack.com\/files-pri\/T0HFQLJF6-F9RUNPRHU\/download\/README_md.md","permalink":"https:\/\/morishimalab.slack.com\/files\/U4RTD3TLP\/F9RUNPRHU\/README_md.md","permalink_public":"https:\/\/slack-files.com\/T0HFQLJF6-F9RUNPRHU-2db0e92631","edit_link":"https:\/\/morishimalab.slack.com\/files\/U4RTD3TLP\/F9RUNPRHU\/README_md.md\/edit","preview":"# List\r\n### MyList.h & .cpp\r\n\u30ea\u30b9\u30c8\u306e\u69cb\u9020\u3092\u52c9\u5f37\u3059\u308b\u305f\u3081\u306b\u81ea\u4f5c\u3057\u305f\u53cc\u65b9\u5411\u30ea\u30b9\u30c8\r\n\r\n### Example\r","preview_highlight":"\u003Cdiv class=\"CodeMirror cm-s-default CodeMirrorServer\" oncopy=\"if(event.clipboardData){event.clipboardData.setData('text\/plain',window.getSelection().toString().replace(\/\\u200b\/g,''));event.preventDefault();event.stopPropagation();}\"\u003E\n\u003Cdiv class=\"CodeMirror-code\"\u003E\n\u003Cdiv\u003E\u003Cpre\u003E\u003Cspan class=\"cm-header cm-header-1\"\u003E# \u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-1\"\u003EList\u003C\/span\u003E\u003C\/pre\u003E\u003C\/div\u003E\n\u003Cdiv\u003E\u003Cpre\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E### \u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003EMyList.h\u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E \u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E&amp;\u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E \u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E.cpp\u003C\/span\u003E\u003C\/pre\u003E\u003C\/div\u003E\n\u003Cdiv\u003E\u003Cpre\u003E\u30ea\u30b9\u30c8\u306e\u69cb\u9020\u3092\u52c9\u5f37\u3059\u308b\u305f\u3081\u306b\u81ea\u4f5c\u3057\u305f\u53cc\u65b9\u5411\u30ea\u30b9\u30c8\u003C\/pre\u003E\u003C\/div\u003E\n\u003Cdiv\u003E\u003Cpre\u003E&#8203;\u003C\/pre\u003E\u003C\/div\u003E\n\u003Cdiv\u003E\u003Cpre\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003E### \u003C\/span\u003E\u003Cspan class=\"cm-header cm-header-3\"\u003EExample\u003C\/span\u003E\u003C\/pre\u003E\u003C\/div\u003E\n\u003C\/div\u003E\n\u003C\/div\u003E\n","lines":56,"lines_more":51,"preview_is_truncated":true,"channels":[],"groups":[],"ims":["D9593MCF3"],"comments_count":0};
		boot_data.file.comments = [];

		

		var g_editor;

		var code_wrap_long_lines = true;

		$(function(){

			var wrap_long_lines = !!code_wrap_long_lines;

			g_editor = CodeMirror(function(elt){
				var content = document.getElementById("file_contents");
				content.parentNode.replaceChild(elt, content);
			}, {
				value: $('#file_contents').text(),
				lineNumbers: true,
				matchBrackets: true,
				indentUnit: 4,
				indentWithTabs: true,
				enterMode: "keep",
				tabMode: "shift",
				viewportMargin: 10,
				readOnly: true,
				lineWrapping: wrap_long_lines
			});

			// past a certain point, CodeMirror rendering may simply stop working.
			// start having CodeMirror use its Long List View-style scolling at >= max_lines.
			var max_lines = 8192;

			var snippet_lines;

			// determine # of lines, limit height accordingly
			if (g_editor.doc && g_editor.doc.lineCount) {
				snippet_lines = parseInt(g_editor.doc.lineCount());
				var new_height;
				if (snippet_lines) {
					// we want the CodeMirror container to collapse around short snippets.
					// however, we want to let it auto-expand only up to a limit, at which point
					// we specify a fixed height so CM can display huge snippets without dying.
					// this is because CodeMirror works nicely with no height set, but doesn't
					// scale (big file performance issue), and doesn't work with min/max-height -
					// so at some point, we have to set an absolute height to kick it into its
					// smart / partial "Long List View"-style rendering mode.
					if (snippet_lines < max_lines) {
						new_height = 'auto';
					} else {
						new_height = (max_lines * 0.875) + 'rem'; // line-to-rem ratio
					}
					var line_count = Math.min(snippet_lines, max_lines);
					TS.info('Applying height of ' + new_height + ' to container for this snippet of ' + snippet_lines + (snippet_lines === 1 ? ' line' : ' lines'));
					$('#page .CodeMirror').height(new_height);
				}
			}

			$('#file_preview_wrap_cb').bind('change', function(e) {
				code_wrap_long_lines = $(this).prop('checked');
				g_editor.setOption('lineWrapping', code_wrap_long_lines);
			})

			$('#file_preview_wrap_cb').prop('checked', wrap_long_lines);

			CodeMirror.switchSlackMode(g_editor, "markdown");
		});

		
		$('#file_comment').css('overflow', 'hidden').autogrow();
	//-->
	</script>


<style>.color_9f69e7:not(.nuc) {color:#9F69E7;}.color_4bbe2e:not(.nuc) {color:#4BBE2E;}.color_e7392d:not(.nuc) {color:#E7392D;}.color_3c989f:not(.nuc) {color:#3C989F;}.color_674b1b:not(.nuc) {color:#674B1B;}.color_e96699:not(.nuc) {color:#E96699;}.color_e0a729:not(.nuc) {color:#E0A729;}.color_684b6c:not(.nuc) {color:#684B6C;}.color_5b89d5:not(.nuc) {color:#5B89D5;}.color_2b6836:not(.nuc) {color:#2B6836;}.color_99a949:not(.nuc) {color:#99A949;}.color_df3dc0:not(.nuc) {color:#DF3DC0;}.color_4cc091:not(.nuc) {color:#4CC091;}.color_9b3b45:not(.nuc) {color:#9B3B45;}.color_d58247:not(.nuc) {color:#D58247;}.color_bb86b7:not(.nuc) {color:#BB86B7;}.color_5a4592:not(.nuc) {color:#5A4592;}.color_db3150:not(.nuc) {color:#DB3150;}.color_235e5b:not(.nuc) {color:#235E5B;}.color_9e3997:not(.nuc) {color:#9E3997;}.color_53b759:not(.nuc) {color:#53B759;}.color_c386df:not(.nuc) {color:#C386DF;}.color_385a86:not(.nuc) {color:#385A86;}.color_a63024:not(.nuc) {color:#A63024;}.color_5870dd:not(.nuc) {color:#5870DD;}.color_ea2977:not(.nuc) {color:#EA2977;}.color_50a0cf:not(.nuc) {color:#50A0CF;}.color_d55aef:not(.nuc) {color:#D55AEF;}.color_d1707d:not(.nuc) {color:#D1707D;}.color_43761b:not(.nuc) {color:#43761B;}.color_e06b56:not(.nuc) {color:#E06B56;}.color_8f4a2b:not(.nuc) {color:#8F4A2B;}.color_902d59:not(.nuc) {color:#902D59;}.color_de5f24:not(.nuc) {color:#DE5F24;}.color_a2a5dc:not(.nuc) {color:#A2A5DC;}.color_827327:not(.nuc) {color:#827327;}.color_3c8c69:not(.nuc) {color:#3C8C69;}.color_8d4b84:not(.nuc) {color:#8D4B84;}.color_84b22f:not(.nuc) {color:#84B22F;}.color_4ec0d6:not(.nuc) {color:#4EC0D6;}.color_e23f99:not(.nuc) {color:#E23F99;}.color_e475df:not(.nuc) {color:#E475DF;}.color_619a4f:not(.nuc) {color:#619A4F;}.color_a72f79:not(.nuc) {color:#A72F79;}.color_7d414c:not(.nuc) {color:#7D414C;}.color_aba727:not(.nuc) {color:#ABA727;}.color_965d1b:not(.nuc) {color:#965D1B;}.color_4d5e26:not(.nuc) {color:#4D5E26;}.color_dd8527:not(.nuc) {color:#DD8527;}.color_bd9336:not(.nuc) {color:#BD9336;}.color_e85d72:not(.nuc) {color:#E85D72;}.color_dc7dbb:not(.nuc) {color:#DC7DBB;}.color_bc3663:not(.nuc) {color:#BC3663;}.color_9d8eee:not(.nuc) {color:#9D8EEE;}.color_8469bc:not(.nuc) {color:#8469BC;}.color_73769d:not(.nuc) {color:#73769D;}.color_b14cbc:not(.nuc) {color:#B14CBC;}</style>

<!-- slack-www-hhvm-01477fad6fa63ef54 / 2018-03-21 01:41:58 / v9fb27c557389983b20670d553627bcb34e33b07e / B:H -->


</body>
</html>