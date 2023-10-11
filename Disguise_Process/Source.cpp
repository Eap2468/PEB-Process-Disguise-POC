#include <iostream>
#include <Windows.h>
#include <winternl.h>

extern "C" _RTL_USER_PROCESS_PARAMETERS* GetParamInfo(void);

int main()
{
	wchar_t newPath[] = L"C:\\windows\\system32\\notepad.exe"; //Path to replace current process path with
	wchar_t newDir[] = L"C:\\windows\\system32";			   //Directory to replace current process with

	_RTL_USER_PROCESS_PARAMETERS* params = GetParamInfo(); //Get pointer to _RTL_USER_PROCESS_PARAMETERS and display the address for debugging
	std::cout << "\\___ [ RTL_USER_PROCESS_PARAMETERS ]\n\t\\_0x" << std::hex << params << std::endl;
	
	params->ImagePathName.Buffer = newPath; //ImagePathName buffer
	params->CommandLine.Buffer = newPath;   //CommandLine buffer
	params->Reserved2[6] = newDir;          //Process directory path
	
	std::cout << "PEB info should be changed";

	while (!GetAsyncKeyState(VK_ESCAPE)) //Keep process running to check results of POC
	{
		Sleep(500);
	}

	return 0;
}
