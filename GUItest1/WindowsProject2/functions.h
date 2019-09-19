#pragma once
#include <windows.h>
#include <shellapi.h>
#include <tlhelp32.h>
//#include <json/value.h>

#define MENU_FILE 1
#define MENU_DROP_NEW 101
#define MENU_DROP_OPEN 102
#define MENU_DROP_DROP_FILE1 1001
#define MENU_DROP_IMPORT 103
#define MENU_DROP_EXPORT 104
#define MENU_DROP_STARTUP 105
#define MENU_DROP_EXIT 106

#define MENU_CONTROL 6
#define MENU_ABOUT 7


#define SCREEN_CHECKBOX1 201

HWND hMain;
bool bCheck;
HMENU hMenu;
HMENU hFileMenu;
HMENU hFileMenu2;