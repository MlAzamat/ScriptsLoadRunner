getCTNInfoList()
{
	if (pool_get_hash(lr_eval_string("{ban}{ctn}")) == 0) {

		web_reg_save_param("response", "LB=", "RB=", LAST);
		//web_add_cookie("token={systoken}; domain={endpoint}" );
		web_reg_find("Text=<statusDate>", LAST);
		web_add_header("X-API-Sec-Token", "3JfL2pAVEKy60dd3LpXSTdp8XHWv3pG=");  //�������� ��� 45 ������

    	lr_start_transaction("B2B_api_SubscriberService_getCTNInfoList");
		web_custom_request("getCTNInfoList",
		"URL=http://{endpoint}/api/SubscriberService",
		//--"URL=http://usssweb-pl03.vimpelcom.ru:81/api/SubscriberService",
		"Method=POST", 
		"EncType=text/xml"
		"TargetFrame="
		"Resource=0", 
		"Referer=", 
		//"Body=<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?><soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:uss-wsapi:Subscriber\"><soapenv:Header/><soapenv:Body><urn:getCTNInfoList><token>{systoken}</token><hash>{hmacSha1}</hash><login></login><ban>{ban}</ban><ctn></ctn></urn:getCTNInfoList></soapenv:Body></soapenv:Envelope>", 
		"Body=<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?><soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:uss-wsapi:Subscriber\"><soapenv:Header/><soapenv:Body><urn:getCTNInfoList><token>180C4B754700AF2C02C5CF94CD0A7117</token><hash></hash><login>�����</login><ban>320890213</ban><ctn>{rel45_tmp}</ctn></urn:getCTNInfoList></soapenv:Body></soapenv:Envelope>", 
		LAST ); 

		if (lr_get_transaction_status ("B2B_api_SubscriberService_getCTNInfoList") == LR_FAIL) {
		error_message_to_log("API_b2b_SubscriberService", 
							 "B2B_api_SubscriberService_getCTNInfoList", 
							 lr_eval_string("{login}"), 
							 lr_eval_string(""), 
							 lr_eval_string("{systoken}"), 
							 lr_eval_string("{response}"), 
							 "",
							 "");
			lr_end_transaction("B2B_api_SubscriberService_getCTNInfoList",LR_FAIL);
		} else {
			lr_end_transaction("B2B_api_SubscriberService_getCTNInfoList",LR_AUTO);
		}
	}
	return 0;
}
