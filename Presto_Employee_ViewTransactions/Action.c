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

	lr_start_transaction("Presto_Employee_05_ViewTransactions_Link");

	web_url("View Transactions", 
		"URL=http://35.162.119.3/Presto/emp/empview.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/welcome.jsp", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Employee_05_ViewTransactions_Link",LR_AUTO);
	
		lr_think_time(2);
		
	lr_start_transaction("Presto_Employee_06_ViewTransactions");
	
			web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=All Transactions Details of Account",
		LAST);
		
	web_submit_data("viewcls", 
		"Action=http://35.162.119.3/Presto/emp/viewcls", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/emp/empview.jsp", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=views.clid", "Value=123456", ENDITEM, 
		"Name=submit", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("Presto_Employee_06_ViewTransactions",LR_AUTO);

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