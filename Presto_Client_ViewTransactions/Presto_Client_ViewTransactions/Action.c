Action()
{

		lr_start_transaction("Presto_Client_01_HomePage");
		
	/*	
	 	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome to Presto Banking Application",
		LAST);
		*/

 web_url("Presto", 
		"URL=http://{URL}/Presto/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("favicon.ico", 
		"URL=http://{URL}/Presto/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/x-icon", 
		"Referer=", 
		"Snapshot=t7.inf", 
		LAST);
	lr_end_transaction("Presto_Client_01_HomePage",LR_AUTO);
	
		lr_think_time(2);
	lr_start_transaction("Presto_Client_02_Click_LoginPortal");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=If you are a User then Select",
		LAST);

	web_url("Login Portal", 
		"URL=http://{URL}/Presto/login-portal.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Client_02_Click_LoginPortal",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Presto_Client_03_SelectUser");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Online Login For",
		LAST);

	web_url("login.jsp", 
		"URL=http://{URL}/Presto/user/login.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/login-portal.jsp", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Client_03_SelectUser",LR_AUTO);
	
	lr_think_time(2);
	
	lr_start_transaction("Presto_Client_04_Login");

	web_submit_data("clientlogin", 
		"Action=http://{URL}/Presto/user/clientlogin", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/user/login.jsp", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userName", "Value={user}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=bank_id", "Value={bankid}", ENDITEM, 
		LAST);

	lr_end_transaction("Presto_Client_04_Login",LR_AUTO);

		lr_think_time(2);
	
	lr_start_transaction("Presto_Client_05_ViewTransactions_Client");

	web_reg_find("Text=All Transactions Details of Account: {bankid}", 
		LAST);

	lr_think_time(2);

	web_url("View Transactions", 
		"URL=http://{URL}/Presto/user/viewcl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/user/welcome.jsp", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Client_05_ViewTransactions_Client",LR_AUTO);

		lr_think_time(2);
	
	lr_start_transaction("Presto_Client_06_Logout");

	web_url("Logout", 
		"URL=http://{URL}/Presto/logout.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}/Presto/user/viewcl", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("Presto_Client_06_Logout",LR_AUTO);

	return 0;
}