#include <windows.h>

// 窗口过程函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps); // 获取屏幕 DC

        // ---------- 双缓冲开始 ----------
        // 1. 获取窗口大小
        RECT rect;
        GetClientRect(hwnd, &rect);

        // 2. 创建内存 DC（虚拟画布）
        HDC memDC = CreateCompatibleDC(hdc);

        // 3. 创建位图（虚拟纸张）
        HBITMAP memBmp = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
        SelectObject(memDC, memBmp);

        // 4. 在内存 DC 上绘制所有内容
        // 4.1 填充背景色（白色）
        HBRUSH hBrushBg = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(memDC, hBrushBg);
        Rectangle(memDC, 0, 0, rect.right, rect.bottom);
        DeleteObject(hBrushBg);

        // 4.2 画一个红色矩形
        HPEN hPenRed = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
        SelectObject(memDC, hPenRed);
        HBRUSH hBrushRed = CreateSolidBrush(RGB(255, 200, 200));
        SelectObject(memDC, hBrushRed);
        Rectangle(memDC, 50, 50, 200, 150);
        DeleteObject(hPenRed);
        DeleteObject(hBrushRed);

        // 4.3 画一个绿色圆
        HPEN hPenGreen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
        SelectObject(memDC, hPenGreen);
        HBRUSH hBrushGreen = CreateSolidBrush(RGB(200, 255, 200));
        SelectObject(memDC, hBrushGreen);
        Ellipse(memDC, 250, 50, 400, 150);
        DeleteObject(hPenGreen);
        DeleteObject(hBrushGreen);

        // 4.4 画蓝色文字
        HFONT hFont = CreateFont(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                                 DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                 CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                 DEFAULT_PITCH | FF_DONTCARE, L"微软雅黑");
        SelectObject(memDC, hFont);
        SetTextColor(memDC, RGB(0, 0, 255));
        SetBkMode(memDC, TRANSPARENT);
        TextOut(memDC, 100, 200, L"GDI 双缓冲示例", wcslen(L"GDI 双缓冲示例"));
        DeleteObject(hFont);

        // 5. 一次性把内存 DC 的内容复制到屏幕（这一步极快，不会闪）
        BitBlt(hdc, 0, 0, rect.right, rect.bottom, memDC, 0, 0, SRCCOPY);

        // 6. 清理内存资源
        DeleteObject(memBmp);
        DeleteDC(memDC);
        // ---------- 双缓冲结束 ----------

        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// 程序入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 1. 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"MyGDIClass";
    RegisterClass(&wc);

    // 2. 创建窗口
    HWND hwnd = CreateWindow(L"MyGDIClass", L"GDI 绘图教程",
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             600, 400,
                             NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 3. 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}