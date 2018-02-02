Action()
{

	web_url("Presto", 
		"URL=http://35.162.119.3/Presto/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("favicon.ico", 
		"URL=http://35.162.119.3/Presto/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t7.inf", 
		LAST);

	lr_start_transaction("02_Click_LoginPortal");

	web_url("Login Portal", 
		"URL=http://35.162.119.3/Presto/login-portal.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("02_Click_LoginPortal",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("3_SelectUser");

	web_url("login.jsp", 
		"URL=http://35.162.119.3/Presto/user/login.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/login-portal.jsp", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("3_SelectUser",LR_AUTO);

	lr_start_transaction("4_Login");

	web_submit_data("clientlogin", 
		"Action=http://35.162.119.3/Presto/user/clientlogin", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/user/login.jsp", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userName", "Value=client1", ENDITEM, 
		"Name=password", "Value=client", ENDITEM, 
		"Name=bank_id", "Value=123456", ENDITEM, 
		LAST);

	lr_end_transaction("4_Login",LR_AUTO);

	lr_start_transaction("5_ViewTransactions_Client");

	web_reg_find("Text=All Transactions Details of Account: 123456", 
		LAST);

	lr_think_time(27);

	web_url("View Transactions", 
		"URL=http://35.162.119.3/Presto/user/viewcl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/user/welcome.jsp", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("5_ViewTransactions_Client",LR_AUTO);

	lr_start_transaction("6_Logout");

	web_url("Logout", 
		"URL=http://35.162.119.3/Presto/logout.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://35.162.119.3/Presto/user/viewcl", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("6_Logout",LR_AUTO);

	return 0;
}