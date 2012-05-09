(function($) {
	$(document).ready(function(){
		/* タブ関係 */
			//init(詳細入力領域を閉じる)
			$("#employFormInnerAdd").css("display","none");
			//
			$("#buttom_more").click(function () {
				$("#employFormInnerAdd").slideToggle();
			});
		
		/* 能力要件タブ関係 */
			//初期状態にリセット
			$(".tabcontent").css("display","none");
			$("#tabcontent01").css("display","block");
			
			if (true) {
				//タブにカーソルを合わせた時の動作
				$("li#tab01").hover(
					function () {
						$(".menutabitem").css("background-position","left top");
						$(this).css("background-position","left bottom");
						$(".tabcontent").css("display","none");
						$("#tabcontent01").css("display","block");
					},
					function () {
					}
				);
				$("li#tab02").hover(
					function () {
						$(".menutabitem").css("background-position","left top");
						$(this).css("background-position","left bottom");
						$(".tabcontent").css("display","none");
						$("#tabcontent02").css("display","block");
					},
					function () {
					}
				);
				$("li#tab03").hover(
					function () {
						$(".menutabitem").css("background-position","left top");
						$(this).css("background-position","left bottom");
						$(".tabcontent").css("display","none");
						$("#tabcontent03").css("display","block");
					},
					function () {
					}
				);
				$("li#tab04").hover(
					function () {
						$(".menutabitem").css("background-position","left top");
						$(this).css("background-position","left bottom");
						$(".tabcontent").css("display","none");
						$("#tabcontent04").css("display","block");
					},
					function () {
					}
				);
				$("li#tab05").hover(
					function () {
						$(".menutabitem").css("background-position","left top");
						$(this).css("background-position","left bottom");
						$(".tabcontent").css("display","none");
						$("#tabcontent05").css("display","block");
					},
					function () {
					}
				);
			}
		/* ページトップリンクの動作関係 */
			$(function(){
				$("a#toTop").click(function(){
					$('html,body').animate({ scrollTop: $($(this).attr("href")).offset().top }, 'slow','swing');
					return false;
				})
			});
		
	});
})(jQuery);