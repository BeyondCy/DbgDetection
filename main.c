#include <stdio.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN

#define DEBUG printf("DEBUG - %ld\r\n", GetLastError());

DWORD dwError;
#define DEFAULT_EXIT "Press any key to continue..\r\n"
#define SW(x) SysWait(x);
VOID SysWait(LPTSTR lpString);

#define SET_ERROR_HANDLER dwError = GetLastError();
#define RESET_ERROR_HANDLER dwError = ERROR_SUCCESS;

CHAR tVmDlls[0x02][0x0f] = {"dbghelp.dll", "sbiedll.dll"}; //need to find more
BOOL NtDetectVmInjectedDlls(VOID);

INT __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
     RESET_ERROR_HANDLER
     
     if((!NtDetectVmInjectedDlls()) && (dwError == ERROR_SUCCESS))
          printf("No VM dll's detected\r\n");
     else if(dwError != ERROR_SUCCESS)
          printf("Failed to enumerate dll's\r\n");
     else
          printf("VM dll's detected\r\n");

     SW(DEFAULT_EXIT)
     return ERROR_SUCCESS;
}

VOID SysWait(LPTSTR lpString)
{
     printf("%s", lpString);
     dwError = getch();
}
BOOL NtDetectVmInjectedDlls(VOID)
{
     HMODULE hMod;
     DWORD dwX;
     BOOL bFlag = FALSE;
     
     for(dwX = 0; dwX < 0x02; dwX++)
     {
          RESET_ERROR_HANDLER
          
          hMod = GetModuleHandle(tVmDlls[dwX]);
          if(hMod == NULL)
          {
               SET_ERROR_HANDLER
               if(dwError == 0x7E)
                    continue;
               else
                    return FALSE;
          }
          
          bFlag = TRUE;
          FreeLibrary(hMod);
     }
     
     RESET_ERROR_HANDLER
     return bFlag;
}
