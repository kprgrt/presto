Action()
{

	/*
		 web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome to Presto Banking Application",
		LAST);
		*/
	
   lr_start_transaction("Presto_Employee_01_HomePage");
   
	web_url("Presto", 
		"URL=http://{URL}/Presto/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("favicon.ico", 
		"URL=http://{URL}/Presto/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t2.inf", 
		LAST);
		
   lr_end_transaction("Presto_Employee_01_HomePage",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Presto_Employee_02_ClickLoginLink");

	web_url("Login Portal", 
		"URL=http://{URL}/Presto/login-portal.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/", 
		"Snapshot=t3.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("login.css", 
		"URL=http://{URL}/Presto/css/login.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=http://{URL}/Presto/login-portal.jsp", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Presto_Employee_02_ClickLoginLink",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Presto_Employee_03_SelectUser");

	web_url("login.jsp", 
		"URL=http://{URL}/Presto/emp/login.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/login-portal.jsp", 
		"Snapshot=t5.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_03_SelectUser",LR_AUTO);

	lr_start_transaction("Presto_Employee_04_Login");

	
		 web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome,mgr1",
		LAST);
		
	web_submit_data("emplogin", 
		"Action=http://{URL}/Presto/emp/emplogin", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/emp/login.jsp", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userName", "Value={user}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=bank_id", "Value={bankid}", ENDITEM, 
		LAST);

	lr_end_transaction("Presto_Employee_04_Login",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Presto_Employee_05_WithdrawMoney_Link");

	//Withdraw Amount From Client Account
		 web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Withdraw Amount From Client Account",
		LAST);
	
	web_url("Withdrawn Amount", 
		"URL=http://{URL}/Presto/emp/addwith.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/emp/welcome.jsp", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);
	
	lr_end_transaction("Presto_Employee_05_WithdrawMoney_Link",LR_AUTO);

	lr_think_time(2);
	
	lr_start_transaction("Presto_Employee_06_WithdrawMoney");

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Withdrwan Successfully",
		LAST);
	

	web_submit_data("withdrawn", 
		"Action=http://{URL}/Presto/emp/withdrawn", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/emp/addwith.jsp", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=with.clid", "Value={clientid}", ENDITEM, 
		"Name=with.details", "Value=withdraw money", ENDITEM, 
		"Name=with.amount", "Value={withdraw_amount}", ENDITEM, 
		"Name=submit", "Value=", ENDITEM, 
		LAST);

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Your Last Login was at",
		LAST);
	
	web_url("welcome.jsp_2", 
		"URL=http://{URL}/Presto/emp/welcome.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_06_WithdrawMoney",LR_AUTO);

	lr_think_time(2);
	
	lr_start_transaction("Presto_Employee_07_logout");

	web_url("Logout", 
		"URL=http://{URL}/Presto/emp/logout.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/emp/welcome.jsp", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_07_logout",LR_AUTO);

	return 0;
}