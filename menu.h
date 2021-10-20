#ifndef MENU_H_   /* Include guard */
#define MENU_H_

#define MENU_NEW_RECORD 1
#define MENU_NEW_USER 2
#define MENU_EXIT 9

#define MENU_CONTRIB 11
#define MENU_DOCS 12
#define MENU_INFO 13

HMENU hMenu;

HMENU AppMenu() {
  HMENU hSubMenu = CreateMenu();
  AppendMenu(hSubMenu, MF_STRING, MENU_NEW_RECORD, "Record");
  AppendMenu(hSubMenu, MF_STRING, MENU_NEW_USER, "User");

  HMENU hMenu = CreateMenu();
  AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu, "New");
  AppendMenu(hMenu, MF_SEPARATOR, NULL, NULL);
  AppendMenu(hMenu, MF_STRING, MENU_EXIT, "Exit");

  return hMenu;
}

HMENU HelpMenu() {
  HMENU hMenu = CreateMenu();
  AppendMenu(hMenu, MF_STRING, MENU_CONTRIB, "Contribute");
  AppendMenu(hMenu, MF_STRING, MENU_DOCS, "Documentation");
  AppendMenu(hMenu, MF_STRING, MENU_INFO, "About");

  return hMenu;
}

void AddMenus(HWND hWnd) {
  hMenu = CreateMenu();
  HMENU hAppMenu = AppMenu();
  HMENU hHelpMenu = HelpMenu();
  
  AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hAppMenu, "App");
  AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

  SetMenu(hWnd, hMenu);
}

#endif // MENU_H_
