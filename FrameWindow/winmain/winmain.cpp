/*
 */

#include "../configure.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commctrl.h>

#pragma comment(lib, "comctl32.lib") 

HINSTANCE g_instance;

//-- in "app/WindowProc.cpp"
LRESULT CALLBACK WMB_WNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


static BOOL MakeMainWindow(HINSTANCE inst, int nCmdShow)
{
    //-- Register Window Class
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WMB_WNDPROC;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = inst;
    wcex.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = WMB_WINDOW_CLASS_NAME;
    wcex.hIconSm = nullptr;

    if (!RegisterClassExW(&wcex)) {
        return FALSE;
    }

    //-- Create Window
    HWND hWnd = CreateWindowW(WMB_WINDOW_CLASS_NAME, WMB_TITLE, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        nullptr, nullptr, inst, nullptr);

    if (!hWnd) {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    g_instance = hInstance;

    if (!MakeMainWindow(hInstance, nCmdShow))
    {
        return FALSE;
    }

    InitCommonControls();

    HACCEL hAccelTable = nullptr;
#ifdef WMB_RES_ACCELERATORS
    hAccelTable = LoadAccelerators(hInstance, WMB_RES_ACCELERATORS);
#endif

    MSG msg;

    //-- Message Loop
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (hAccelTable && TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            continue;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}
