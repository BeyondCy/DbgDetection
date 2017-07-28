# DbgDetection

NOTE: This application was compiled using the DEV-C++ IDE (formally known as Bloodshed)

Info: When VirtualBox virtualizes a Windows Operating system both dbgdll.dll and sbiedll.dll are loaded into the virtual address space of every module loaded into memory. Hence, if the application is being virtualized we can attempted to load the modules into our executable. If they're present it is possible our application is being virtualized. dbghelp.dll is a Microsoft dll that contains functionality for debugging (as the name suggests). Sbiedll.dll is documented here: https://www.sandboxie.com/index.php?SBIE_DLL_API