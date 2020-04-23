#define _WIN32_WINNT 0x0501
#define UNICODE 1
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include "../graphics/graphics.h"
#include <dwmapi.h>
using namespace Gdiplus;

HINSTANCE hInst;
LRESULT CALLBACK DlgSubclassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
LRESULT onNcPaint(HWND hwnd, WPARAM wParam, LPARAM lParam);

HBITMAP frameImg, frameRedImg, frameOrigImg;
int frameIndex = 0;


//HRESULT DwmEnableComposition(UINT uCompositionAction);

typedef HRESULT (WINAPI *pFnDwmEnableComposition)(UINT uCompAction);
typedef HRESULT (WINAPI *pFnDwmSetWindowAttribute)(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute);

#define WM_DMWNCRENDERINGCHANGED 0x31F
// wParam = 1 (fRenderingEnabled = true)
// wParam = 0 (fRenderingEnabled = false)


HRESULT EnableNcDwm(HWND hwnd, bool enable)
{
    HMODULE dwmMod = LoadLibrary(L"dwmapi.dll");
    if (dwmMod)
    {
        pFnDwmSetWindowAttribute DwmSetWindowAttribute;
        DwmSetWindowAttribute = (pFnDwmSetWindowAttribute)GetProcAddress(dwmMod, "DwmSetWindowAttribute");

       HRESULT hr = S_OK;
       DWMNCRENDERINGPOLICY ncrp;
       if (enable)
            ncrp = DWMNCRP_ENABLED;
       else
            ncrp = DWMNCRP_DISABLED;

       // Disable non-client area rendering on the window.
       hr = DwmSetWindowAttribute(hwnd, DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
       FreeLibrary(dwmMod);
       if (SUCCEEDED(hr))
       {
          return hr;
       }
   }
   return S_FALSE;
}

/*
#define DWM_EC_DISABLECOMPOSITION 0
#define DWM_EC_ENABLECOMPOSITION 1
HRESULT EnableDWM(HWND hwnd, bool enable)
{
    HMODULE dwmMod = LoadLibrary(L"dwmapi.dll");
    pFnDwmEnableComposition DwmEnableComposition;
    DwmEnableComposition = (pFnDwmEnableComposition)GetProcAddress(dwmMod, "DwmEnableComposition");
    HRESULT hr = S_OK;
    // Disable DWM Composition
    if (enable)
        hr = DwmEnableComposition(DWM_EC_ENABLECOMPOSITION);
    else
        hr = DwmEnableComposition(DWM_EC_DISABLECOMPOSITION);
    FreeLibrary(dwmMod);
   return hr;
}
*/

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static bool isSubclassed = false;
    switch(uMsg)
    {
        case WM_DMWNCRENDERINGCHANGED:
        {
            long dwEx = GetWindowLong(hwndDlg, GWL_EXSTYLE);
            dwEx &= ~(WS_EX_LAYERED);
            SetWindowLong(hwndDlg, GWL_EXSTYLE, dwEx);
            InvalidateRect(hwndDlg, NULL, true);
            UpdateWindow(hwndDlg);
            MoveAnchorsImmediatelly(hwndDlg);
        }
        return 0;

   //     case WM_ERASEBKGND:
   //         {
   //             RECT rc;
   //             GetClientRect(hwndDlg, &rc);
   //             FillRect((HDC)wParam, &rc, (HBRUSH) COLOR_BACKGROUND);
   //             return 1;
   //         }

        case WM_INITDIALOG:
        {
            mSetAnchorMode(GetDlgItem(hwndDlg, IDC_BUTTON1), ANCHOR_CENTER);
        }
        return TRUE;

        case WM_SIZE:
        {
            //MoveAnchorsImmediatelly(hwndDlg);
            DeferAnchorsMove(hwndDlg);
        }
        return TRUE;

        case WM_CLOSE:
        {
            EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
            case IDC_BUTTON1:
                if (isSubclassed == false)
                {
                    SetWindowSubclass( hwndDlg, DlgSubclassProc, 1, NULL);
                    EnableNcDwm(hwndDlg, false);
                    frameIndex++;
                    frameIndex &= 1;        // make sure it can only be in range [0..1]
                }
                else
                {
                    RemoveWindowSubclass( hwndDlg, DlgSubclassProc, 1);
                    EnableNcDwm(hwndDlg, true);
                }
                isSubclassed = !isSubclassed;


             //   InvalidateRect(hwndDlg, NULL, true);
             //   UpdateWindow(hwndDlg);
             //   MoveAnchorsImmediatelly(hwndDlg);
                break;
            }
        }
        return TRUE;
    }

    return FALSE;
}

LRESULT CALLBACK DlgSubclassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    static byte alpha = 255;
    switch (uMsg)
    {
        case WM_ENTERSIZEMOVE:
            printf("WM_ENTERSIZEMOVE\n");
            return 0;
            break;
        case WM_EXITSIZEMOVE:
            printf("WM_EXITSIZEMOVE\n");
            return 0;
            break;

        case WM_MOUSEWHEEL:
            if (((SHORT)(HIWORD(wParam))) > 0)
            {
                if (alpha > 30)
                    alpha -= 5;
            }
            else if (alpha < 255)
                alpha += 5;
            SetLayeredWindowAttributes(hwnd, RGB(255,0,255), alpha, LWA_COLORKEY|LWA_ALPHA);
            UpdateWindow(hwnd);
            return 0;

        case WM_DMWNCRENDERINGCHANGED:
            {
               // printf("WM_DMWNCRENDERINGCHANGED\n");
                long dwEx = GetWindowLong(hwnd, GWL_EXSTYLE);
                dwEx |= WS_EX_LAYERED;
                SetWindowLong(hwnd, GWL_EXSTYLE, dwEx);
                SetLayeredWindowAttributes(hwnd, RGB(255,0,255), alpha, LWA_COLORKEY|LWA_ALPHA);
                //MoveAnchorsImmediatelly(hwnd);
                DeferAnchorsMove(hwnd);
                InvalidateRect(hwnd, NULL, true);
                UpdateWindow(hwnd);
//                showWndRect(hwnd);
                return 0;
            }
            break;

        case WM_NCACTIVATE:
        case WM_NCPAINT:
          //  printf("WM_NCPAINT -");
          //  printf("wParam: 0x%08d lParam 0x%08x\n", wParam, lParam);
            onNcPaint(hwnd, wParam, lParam);
            return 0;

        case WM_NCCALCSIZE:
            {
                RECT *rc = (RECT*)lParam;
                rc->left += 8;             // frame image margin widths
                rc->top += 30;
                rc->right -= 8;
                rc->bottom -= 8;

//                rc->left += 14;             // frame image margin widths
//               rc->top += 39;
//                rc->right -= 14;
//                rc->bottom -= 14;
            }
            return (WVR_HREDRAW | WVR_VREDRAW);

        case WM_NCHITTEST:
            {
                POINT mousePos, rawMousePos;
                RECT clientRect, windowRect;

                mousePos.x = LOWORD(lParam);
                mousePos.y = HIWORD(lParam);
                rawMousePos = mousePos;

                GetClientRect(hwnd, &clientRect);
                GetWindowRect(hwnd, &windowRect);
                ScreenToClient(hwnd, &mousePos);

                if ((mousePos.x < clientRect.left) && (rawMousePos.y < windowRect.top+8))
                    return HTTOPLEFT;

                if ((mousePos.x > clientRect.right) && (rawMousePos.y < windowRect.top+8))
                    return HTTOPRIGHT;

                if ( (mousePos.x < clientRect.left) && (mousePos.y > clientRect.bottom))
                    return HTBOTTOMLEFT;

                if ( (mousePos.x > clientRect.right) && (mousePos.y > clientRect.bottom))
                    return HTBOTTOMRIGHT;

                if (rawMousePos.x < windowRect.left+11)
                    return HTLEFT;

                if (rawMousePos.x > windowRect.right-11)
                    return HTRIGHT;

                if (mousePos.y  > clientRect.bottom)
                    return HTBOTTOM;

                RECT closeRect;
                SetRect(&closeRect, windowRect.left + 15, windowRect.top+7, windowRect.left+15+16, windowRect.top+25);
                if (PtInRect(&closeRect, rawMousePos))
                {
//                    printf("over sys menu (appIcon) - %d,%d\n", mousePos.x, mousePos.y);
                    return HTSYSMENU;
                }

                if (rawMousePos.y < windowRect.top+8)
                    return HTTOP;

                if (mousePos.y < 0)
                    return HTCAPTION;
                else
                    return HTCLIENT;
            }

    }
    return DefSubclassProc(hwnd, uMsg, wParam, lParam);
//    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT onNcPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    // draw Frame
//     HBRUSH mBrush = CreateSolidBrush( RGB(0,113,201) );
    HDC hdc = GetWindowDC(hwnd);
//     HDC hdc = GetDCEx(hwnd, (HRGN)wParam, DCX_WINDOW);//|DCX_INTERSECTRGN);

    RECT mRect, wndRect;
    GetWindowRect(hwnd, &mRect);
    wndRect = mRect;
    mRect.right -= mRect.left;
    mRect.bottom -= mRect.top;
    mRect.left = 0;
    mRect.top = 0;

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP old, memBmp;
    old = (HBITMAP)GetCurrentObject(memDC, OBJ_BITMAP);

    memBmp = CreateCompatibleBitmap(hdc, mRect.right, mRect.bottom);
    //memBmp = zCreateDibSection(hdc, mRect.right, mRect.bottom, 24);

    SelectObject(memDC, memBmp);


    //StretchNineDraw(HDC destDC, RECT destRect, HBITMAP srcImage, RECT srcRect,
    //    int marginLeft, int marginTop, int marginRight, int marginBottom, int alpha);

    if (frameIndex == 0)
//        StretchNineDraw(memDC, mRect, frameImg, (RECT){0,0,33,58}, 16,41,16,16, 255);
        StretchNineDrawNoAlpha(memDC, mRect, frameImg, (RECT){0,0,33,58}, 16,41,16,16);
    else
        StretchNineDraw(memDC, mRect, frameRedImg, (RECT){0,0,33,58}, 16,41,16,16, 255);
//        StretchNineDrawNoAlpha(memDC, mRect, frameRedImg, (RECT){0,0,33,58}, 16,41,16,16);
    //    StretchNineDrawNoAlpha(memDC, mRect, frameOrigImg, (RECT){0,0,17,39}, 8,30,8,8);
    //1111drawImgNineSquareStretching(memDC, mRect, frameImg, (RECT){0,0,33,58}, 16,41,16,16);

//void StretchNineDrawNoAlpha(HDC destDC, RECT destRect, HBITMAP srcImage, RECT srcRect,
//                   int marginLeft, int marginTop, int marginRight, int marginBottom)



    // draw icon
    HICON smallIcon = LoadIcon (NULL, IDI_APPLICATION);
    DrawIconEx(memDC, 15, 9, smallIcon, 16, 16, 0,0, DI_NORMAL  );

    // draw window text
    wchar_t wndText[100];
    RECT textRect;
    textRect.left = 9 + 16 + 9;
    textRect.top = 0;
    textRect.right = 1000;
    textRect.bottom = 32;
    GetWindowText(hwnd, wndText, 99);
    //int oldMode = SetBkMode(hdc, TRANSPARENT);
    //int oldMode = SetBkMode(memDC, TRANSPARENT);
    SetBkMode(memDC, TRANSPARENT);

    HFONT oldFont, hfont0 = CreateFont(-13, 0, 0, 0, 0, FALSE, FALSE, FALSE, 1, 0, 0, 0, 0, (L"Ms Shell Dlg"));
    oldFont = (HFONT)SelectObject(memDC, hfont0);
    DrawText(memDC, wndText, -1, &textRect, DT_VCENTER|DT_SINGLELINE|DT_LEFT);
    SelectObject(memDC, oldFont);
    DeleteObject(hfont0);


    // top slice
    BitBlt(hdc, 0,0, mRect.right,41, memDC, 0,0, SRCCOPY);

    // left edge
    BitBlt(hdc, 0, mRect.top + 41, 16, mRect.bottom - (41+16),
           memDC, 0, mRect.top + 41, SRCCOPY);

    // right edge
    BitBlt(hdc, mRect.right-16, mRect.top + 41, 16, mRect.bottom - (41+16),
           memDC, mRect.right-16, mRect.top + 41, SRCCOPY);

    // bottom slice
    BitBlt(hdc, 0,mRect.bottom-16, mRect.right,16, memDC, 0,mRect.bottom-16, SRCCOPY);


 //   BitBlt(hdc, 0,0, mRect.right,mRect.bottom, memDC, 0,0, SRCCOPY);

    ReleaseDC(hwnd, hdc);
    SelectObject(memDC, old);
    DeleteDC(memDC);
    DeleteObject(memBmp);
 //   ValidateRgn(hwnd, (HRGN)wParam);
    return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    frameImg = mLoadImageFile(L"frame.png");
    frameRedImg = mLoadImageFile(L"frameRed.png");
    frameOrigImg = mLoadImageFile(L"frameOrig.png");

    hInst=hInstance;
    InitCommonControls();
    int result = DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);

    GdiplusShutdown(gdiplusToken);
    return result;
}
