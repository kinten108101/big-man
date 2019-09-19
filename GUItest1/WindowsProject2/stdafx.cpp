#include "stdafx.h"
#include <string>
#include "functions.h"
#include <fstream>
#include <iostream>

LPCWSTR a = L"Jeong's Laboratory Configuration\nCopyright 2019 JPP\nDemo version 0.20.0005 \nContact: gb.lenguyen@gmail.com";
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

std::wstring path = L"c:\\Users\\Administrator\\Documents\\SHORTCUT\\thesauruscom.lnk";

void MenuCreate(HWND);
void StaticCreate(HWND);

int FIND_PROC_BY_NAME(const char);
/*void createProcess(std::wstring, std::wstring);*/

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{

	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"MyApp";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc)) return -1; // Final checkup after registration

	hMain = CreateWindowW(L"MyApp", L"LabConfig Demo", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 300, 500, NULL, NULL, NULL, NULL);
	SetWindowPos(hMain, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:
		//

		//
		switch (wp)
		{
		case MENU_DROP_DROP_FILE1:

			ShellExecute(NULL, L"open", L"http://www.lexico.com/en/", L"", L"", SW_SHOW);
			break;
		case MENU_DROP_EXIT:
			DestroyWindow(hWnd);
			break;
		case MENU_ABOUT:
			MessageBox(hWnd, a, L"Version History", NULL);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		MenuCreate(hWnd);
		StaticCreate(hWnd);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void MenuCreate(HWND hWnd)
{
	hMenu = CreateMenu();
	hFileMenu = CreateMenu();
	hFileMenu2 = CreateMenu();



	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"Settings");
	AppendMenu(hFileMenu, MF_STRING, MENU_DROP_NEW, L"New");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hFileMenu2, L"Open");
	AppendMenu(hFileMenu2, MF_STRING, MENU_DROP_DROP_FILE1, L"Thesaurus");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_UNCHECKED, MENU_DROP_STARTUP, L"Run On Startup");
	AppendMenu(hFileMenu, MF_STRING, MENU_DROP_EXIT, L"Exit");


	AppendMenu(hMenu, MF_STRING, MENU_CONTROL, L"Control");
	AppendMenu(hMenu, MF_STRING, MENU_ABOUT, L"About");

	SetMenu(hWnd, hMenu);

	/*}void createProcess(std::wstring path)
	{
		std::ifstream file;
		file.open(path, std::ios::in);

	}*/

}
/*void createProcess(std::wstring path, std::wstring cmd) {
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	if (CreateProcess(path, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
}
*/

void StaticCreate(HWND hWnd)
{
	//CreateWindowW(L"static", L"Enable Autoscroll", WS_CHILD | WS_VISIBLE, 200, 100, 50, 100, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"edit", L"Enable on Startup", WS_CHILD | WS_VISIBLE, 200, 100, 50, 100, hWnd, NULL, NULL, NULL);
	//CreateWindowW(L"button", L"Checkbox here", WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 50, 100, 50, 500, hWnd, NULL, NULL, NULL);
	//CheckDlgButton(hWnd, 1, BST_CHECKED);

}

