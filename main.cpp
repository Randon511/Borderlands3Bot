#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>

int main()
{
	std::vector<std::wstring> titles;
	//Borderlands window title is <Borderlands® 3  > including the spaces
	HWND hwnd = FindWindowA(0, ("Borderlands® 3  "));
	
	if (hwnd == 0) 
	{
		std::cout << "Error, no window found" << std::endl; 
		Sleep(2000);
	}
	else 
	{
		//Get processID
		DWORD procId;
		GetWindowThreadProcessId(hwnd, &procId);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);

		if (procId == 0)
		{
			std::cout << "Error, no proccess Id found" << std::endl;
			Sleep(2000);
		}
	}
	return 0;
}