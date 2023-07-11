/**
 * アプリケーションの実装をこのファイルに記述していきます。
 * 
 * ウィンドウプロシージャの実装があります。
 */

#include "../winmain/WinMainBoot.hpp"

extern HINSTANCE g_instance;

LRESULT CALLBACK WMB_WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        MoveWindow(hWnd, 100, 100, 320, 240, FALSE);
        CreateWindow(
            L"BUTTON", L"WinMainBoot",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            4, 4, 150, 50,
            hWnd, nullptr, g_instance, nullptr);

        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
