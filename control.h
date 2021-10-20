#ifndef CONTROL_H_   /* Include guard */
#define CONTROL_H_

// 720
// 420
void AddControl(HWND hWnd) {
  CreateWindowW(L"static", L"Enter text here", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 310, 100, 100, 22, hWnd, NULL, NULL, NULL);
  CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 310, 126, 100, 22, hWnd, NULL, NULL, NULL);
}

#endif // CONTROL_H_