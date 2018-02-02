Action()
{

	web_url("Presto", 
		"URL=http://35.162.119.3/Presto/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("favicon.ico", 
		"URL=http://35.162.119.3/Presto/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t2.inf", 
		LAST);

	lr_think_time(75);

	lr_start_transaction("Presto_Employee_2_ClickLoginLink");

	web_url("Login Portal", 
		"URL=http://35.162.119.3/Presto/login-portal.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/", 
		"Snapshot=t3.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("login.css", 
		"URL=http://35.162.119.3/Presto/css/login.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=http://35.162.119.3/Presto/login-portal.jsp", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Presto_Employee_2_ClickLoginLink",LR_AUTO);

	lr_think_time(38);

	lr_start_transaction("Presto_Employee_3_SelectUser");

	web_url("login.jsp", 
		"URL=http://35.162.119.3/Presto/emp/login.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/login-portal.jsp", 
		"Snapshot=t5.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_3_SelectUser",LR_AUTO);

	lr_start_transaction("Presto_Employee_4_Login");

	web_submit_data("emplogin", 
		"Action=http://35.162.119.3/Presto/emp/emplogin", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/login.jsp", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userName", "Value=mgr1", ENDITEM, 
		"Name=password", "Value=mgr1", ENDITEM, 
		"Name=bank_id", "Value=567890", ENDITEM, 
		LAST);

	lr_end_transaction("Presto_Employee_4_Login",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("Presto_Employee_5_DepositMoney");

	web_url("Deposit Amount", 
		"URL=http://35.162.119.3/Presto/emp/addtrans.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);

	lr_think_time(19);

	web_submit_data("deposit", 
		"Action=http://35.162.119.3/Presto/emp/deposit", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/addtrans.jsp", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=depo.clid", "Value=123456", ENDITEM, 
		"Name=depo.details", "Value=Add Money", ENDITEM, 
		"Name=depo.amount", "Value=100", ENDITEM, 
		"Name=submit", "Value=", ENDITEM, 
		LAST);

	web_url("welcome.jsp", 
		"URL=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_5_DepositMoney",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("withdraw_money");

	web_url("Withdrawn Amount", 
		"URL=http://35.162.119.3/Presto/emp/addwith.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);

	lr_think_time(5);

	web_submit_data("withdrawn", 
		"Action=http://35.162.119.3/Presto/emp/withdrawn", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/addwith.jsp", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=with.clid", "Value=123456", ENDITEM, 
		"Name=with.details", "Value=withdraw money", ENDITEM, 
		"Name=with.amount", "Value=10", ENDITEM, 
		"Name=submit", "Value=", ENDITEM, 
		LAST);

	web_url("welcome.jsp_2", 
		"URL=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("withdraw_money",LR_AUTO);

	lr_start_transaction("logout");

	web_url("Logout", 
		"URL=http://35.162.119.3/Presto/emp/logout.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}