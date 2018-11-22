/*
This code is for educational purposes only. Do not use it for illegal purposes.
Using MIT license. free and open source, and use it at will.
All consequences should be borne by the user, not by the author. 
The final right of interpretation of this statement rests with the author.
*/
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//follow function will help "DelSelfByBatFile" get app's name from path
void ExtractName(char path[],char get[])
{
	int i,j,n=strlen(path);
	for (i = n - 1; i >= 0; i--)
	{
		if (path[i] == '\\')break;
	}
	i++;
	for(j=0;i<n;i++)
	{
		get[j++] = path[i];
	}
	get[j] = '\0';
}

void DelSelfByBatFile()
{
	char strName[MAX_PATH];//path name
	char FileName[MAX_PATH];
	HMODULE hModule = GetModuleHandle(NULL);//get the app's handle
	GetModuleFileNameA(hModule, strName, MAX_PATH);//get app's path & name
	ExtractName(strName, FileName);//get name
	//creat a bat file
	FILE *fp;
	fp = fopen("Shelldel.bat", "w+");
	fprintf(fp, "@echo off\n");
	fprintf(fp, ":start\n");
	fprintf(fp, "\tif not exist %s goto done\n", FileName);
	fprintf(fp, "\tdel /f /q %s\n\tgoto start\n", FileName);
	fprintf(fp, ":done\n");
	fprintf(fp, "\tdel /f/q ");
	//if you don't specially use follow sentence,the bat file will not delete itself in windows10
	fputc('%', fp);
	fprintf(fp, "0\n");
	fclose(fp);
	//Execute the bat file to delete the app and bat
	HINSTANCE hin = ShellExecute((HWND)hModule, L"open", L"Shelldel.bat", NULL, NULL, SW_NORMAL);
}
//delete following code .... this is for test,not for you^-^
int main()
{
	DelSelfByBatFile();
	return 0;
}
//additional information
/*
It compiled with Windows10 in VS2017.
Anti-virus software is 
Huorong(https://www.huorong.cn) in windows 10 x64
Can't detected
360°²È«ÎÀÊ¿£¨http://weishi.360.cn£©in Windows 7 x64
Can't detected
*/