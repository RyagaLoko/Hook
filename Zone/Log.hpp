#pragma once
#include "pch.h"

class Log
{
private:
	static void AddLog(const char* fileName, const char* type, int textAttrib, const char* msg)
	{
		auto t = std::time(0);
		auto now = std::localtime(&t);
		
		#ifdef CONSOLE
		static char buff[2048];
		sprintf(buff, "[%02d:%02d:%02d] [%s] %s", now->tm_hour, now->tm_min, now->tm_sec, type, msg);

		auto console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, textAttrib);
		std::cout << buff << std::endl;
		#endif

		static char fileBuff[MAX_PATH];
		sprintf(fileBuff, "%s..\\%s", GetBaseDir(), fileName);
		auto file = fopen(fileBuff, "a");
		fprintf(file, "[%02d:%02d:%02d] [%s] %s\n", now->tm_hour, now->tm_min, now->tm_sec, type, msg);
		fclose(file);
	}
	
public:
	static void Info(const char* msg)
	{
		AddLog("HookLog.Zone.txt", "Info", 15, msg);
	}
	
	static void Ok(const char* msg)
	{
		AddLog("HookLog.Zone.txt", "Info", 10, msg);
	}

	static void Warn(const char* msg)
	{
		AddLog("HookLog.Zone.txt", "Warn", 14, msg);
	}

	static void Error(const char* msg)
	{
		AddLog("HookLog.Zone.txt", "Error", 12, msg);
	}

	static void Pickup(const char* msg)
	{
		AddLog("HookLog.Zone.txt", "Pickup", 13, msg);
	}

	static void Debug(const char* msg)
	{
		//AddLog("HookLog.Zone.txt", "Debug", 13, msg);
	}

	static void ToFile(const char* fileName, const char* type, const char* msg)
	{
		AddLog(fileName, type, 13, msg);
	}
};