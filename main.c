#include <windows.h>
#include "menu.h"
#include "control.h"

LRESULT CALLBACK WinProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
  WNDCLASSW wc = {0};
  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hInstance = hInst;
  wc.lpszClassName = L"myWindowClass";
  wc.lpfnWndProc = WinProcedure;

  if(!RegisterClassW(&wc))
    return -1;
  
  CreateWindowW(L"myWindowClass", L"TekUp", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 720, 420, NULL, NULL, NULL, NULL);
  
  MSG msg = {0};
  while(GetMessage(&msg, NULL, NULL, NULL)) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }

  return 0;
}

LRESULT CALLBACK WinProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
  switch (msg) {
  case WM_COMMAND:
    OnCommand(hWnd, msg, wp, lp);
    break;
  case WM_CREATE:
    AddMenus(hWnd);
    AddControl(hWnd);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  
  default:
    return DefWindowProcW(hWnd, msg, wp, lp);
  }
}

void OnCommand(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
  switch (wp) {
  case MENU_NEW_RECORD: 
    break;
  case MENU_NEW_USER: 
    break;
  case MENU_EXIT:
    PostQuitMessage(0);
    break;
  case MENU_CONTRIB: 
    break;
  case MENU_DOCS:
    break;
  case MENU_INFO:
    MessageBox(NULL, NULL, NULL, NULL); 
    break;
  
  default:
    break;
  }
}