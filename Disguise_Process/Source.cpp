#include <iostream>
#include <Windows.h>
#include <winternl.h>

extern "C" _RTL_USER_PROCESS_PARAMETERS* GetParamInfo(void);

int main()
{
	wchar_t newPath[] = L"C:\\windows\\system32\\notepad.exe";
	wchar_t newDir[] = L"C:\\windows\\system32";

	_RTL_USER_PROCESS_PARAMETERS* params = GetParamInfo();
	std::cout << "\\___ [ RTL_USER_PROCESS_PARAMETERS ]\n\t\\_0x" << std::hex << params << std::endl;
	
	params->ImagePathName.Buffer = newPath;
	params->CommandLine.Buffer = newPath;
	params->Reserved2[6] = newDir;
	
	std::cout << "PEB info should be changed";

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		Sleep(500);
	}

	return 0;
}