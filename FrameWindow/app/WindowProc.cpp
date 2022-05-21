/*
 */

#include "../configure.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern HINSTANCE g_instance;

LRESULT CALLBACK WMB_WNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
    case WM_CREATE:
        MoveWindow(hWnd, 100, 100, 320, 240, FALSE);
		CreateWindow(
			L"BUTTON", L"Button",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			4, 4, 100, 50,
			hWnd, nullptr, g_instance, nullptr);

        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
